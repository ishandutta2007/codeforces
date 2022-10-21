#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500, INF = (int)1e9;
typedef pair<int, int> P;
typedef long long ll;

int tn=0, n = 0,m;
P val[N], dp[N], valcmp[N];
string word[N], a, b;
vector<int> G[N], rG[N], vs;
bool used[N];
int cmp[N];
vector<int> Gn[N];
map<string, int> mp;

void cpf(P &a, P &b){
    a.first = b.first;
    a.second = b.second;
}

P getval(string s){
    int res = 0;
    for(char c : s) if(c == 'r') res++;
    return {res, s.length()};
}

void add_edge(int from, int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v){
    used[v] = true;
    for(int nxt : G[v]){
        if(!used[nxt]) dfs(nxt);
    }
    vs.push_back(v);
}

void rdfs(int v, int k){
    used[v] = true;
    cmp[v] = k;
    for(int nxt : rG[v]){
        if(!used[nxt]) rdfs(nxt, k);
    }
}

P dfsn(int v){
    if(dp[v].first != -1) return dp[v];
    cpf(dp[v], valcmp[v]);
    for(int nxt : Gn[v]){
        P p = dfsn(nxt);
        if(p < dp[v]) cpf(dp[v], p);
    }
    return dp[v];
}


int scc(){
    memset(used, 0, sizeof(used));
    vs.clear();
    for(int v = 0; v < n; v++){
        if(!used[v]) dfs(v);
    }
    memset(used, 0, sizeof(used));
    int k = 0;
    reverse(vs.begin(), vs.end());
    for(int v : vs){
        if(!used[v]) rdfs(v, k++);
    }
    return k;
}

string lower_case(string s){
    for(int i = 0; i < s.length(); i++) if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
    return s;
}

int getid(string s){
    s = lower_case(s);

    if(mp.count(s)) return mp[s];
    int cntr = 0;
    for(char c : s) if(c == 'r') cntr++;
    val[n].first = cntr, val[n].second = s.length();
    return mp[s] = n++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> tn;
    for(int i = 0; i < tn; i++){
        cin >> word[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        int ia = getid(a), ib = getid(b);
        add_edge(ia, ib);
        //G[ia].push_back(ib);
    }
    int scn = scc();
    for(int i = 0; i < scn; i++){valcmp[i].first = valcmp[i].second = INF;}
    for(int i = 0; i < n; i++){
        for(int nxt : G[i]){
            Gn[cmp[i]].push_back(cmp[nxt]);
        }
        if(val[i] < valcmp[cmp[i]]){
            cpf(valcmp[cmp[i]], val[i]);
        }
    }
    for(int i = 0; i < scn; i++) dp[i].first = dp[i].second = -1;


    ll rcnt = 0, len = 0;
    for(int i = 0; i < tn; i++){
        word[i] = lower_case(word[i]);
        if(mp.count(word[i])){
            P cur = dfsn(cmp[mp[word[i]]]);
            rcnt += cur.first;
            len += cur.second;
        }
        else{
            P cur = getval(word[i]);
            rcnt += cur.first;
            len += cur.second;
        }
    }
//    for(auto p : mp){
//        cout << p.first << " " << val[getid(p.first)].first << " " << val[getid(p.first)].second << endl;
//    }

    cout << rcnt << " " << len << endl;

}