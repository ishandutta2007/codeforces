#include <bits/stdc++.h>
#define LL long long
#define TASKNAME ""

using namespace std;
struct Edge{int v; char ch;};
const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
int n;
vector<vector<Edge> > data;
pair<int, int> up[100000][100];
int binup[100000][20];
vector<LL> MOD = {(LL)1e9+7, (LL)1e9+9};
vector<int> PS = {281, 179};
vector<int> tin, tout, h;
int ctr=0;
vector<int> kek;
vector<vector<pair<LL, int> > > ggg;
void dfs(int vertex, int last, int code, int H){
    tin[vertex] = ctr++;
    h[vertex] = H;
    //cout << vertex << " " << last << " " << code << endl;
    //up[vertex][0] = {code, code};
    if (last != -1){
        up[vertex][0] = {code, code};
        //cout << code << " " << code << endl;
        for (int i=1; i < 100; i++){
            if (up[last][i-1] != make_pair((int) -1, (int) -1)){
                LL A = 1LL*up[last][i-1].first * 1LL*PS[0] + 1LL*code, B = 1LL*up[last][i-1].second * 1LL*PS[1] + 1LL*code;
                A %= MOD[0], B %= MOD[1];
                //cout << A << "!!!" << B << endl;
                up[vertex][i] = {A, B};
            }
        }
        binup[vertex][0] = last;
        int V = last, ind = 0;
        while (binup[V][ind] != -1){
            binup[vertex][ind+1] = binup[V][ind];
            V = binup[V][ind];
            ind++;
        }
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i].v;
        if (to == last) continue;
        dfs(to, vertex, data[vertex][i].ch, H+1);
    }
    tout[vertex] = ctr++;
}
bool High(int u, int v){
    return ((tin[u] <= tin[v]) && (tout[u] >= tout[v]));
}
int LCA(int u, int v){
    if (High(u, v)) return u;
    for (int i=19; i >= 0; i--){
        int to = binup[u][i];
        if (to==-1) continue;
        if (High(to, v)) continue;
        u = to;
    }
    return binup[u][0];
}
int lift(int u, int lvl){
    if (h[u] <= lvl) return u;
    int need = h[u] - lvl;
    for (int i=0; i < 20; i++){
        int ba = (1<<i) & need;
        if (ba == 0) continue;
        u = binup[u][i];
    }
    return u;
}
string Lift(int a, int b){
    string ans = "";
    while (a != b){
        ans += (char) (up[a][0].first);
        a = binup[a][0];
    }
    return ans;
}
int KMP(string &a, string &b){
    string s = b + "#" + a;
    int n = s.size();
    vector <int> z(n, 0);
    int l = -1, r = -1;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (r >= i) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
        if (z[i] == b.size()) {
            sum++;
        }
    }
    //cout << a << " " << b << " " << sum << endl;
    return sum;
}
unordered_map<LL, int> sas;
set<LL> govno;
void solve(int vertex, int last){
    //cout << vertex << "HUJ" << endl;
    LL pp = up[vertex][0].first*1LL*2e9+1LL*up[vertex][0].second;
    //cout << pp << endl;
    for (int i=0; i < 100; i++){
        LL ggg = up[vertex][i].first*1LL*2e9+1LL*up[vertex][i].second;
        if (!govno.count(ggg)) continue;
        sas[ggg]++;
    }
    for (int i=0; i < ggg[vertex].size(); i++){
        pair<LL, int> uni = ggg[vertex][i];
        int ind = abs(uni.second);
        kek[ind-1] += sas[uni.first] * uni.second / ind;
    }
    for (int i=0; i < data[vertex].size() ;i++){
        int to = data[vertex][i].v;
        if (to==last) continue;
        solve(to, vertex);
    }
    for (int i=0; i < 100; i++){
        LL ggg = up[vertex][i].first*1LL*2e9+1LL*up[vertex][i].second;
        if (!govno.count(ggg)) continue;
        sas[ggg]--;
    }
}
signed main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    data.resize(n);
    tin.resize(n), tout.resize(n), h.resize(n);
    for (int i=0; i < n-1; i++){
        int u, v;
        char x;
        cin >> u >> v >> x;
        u--, v--;
        data[u].push_back({v, x});
        data[v].push_back({u, x});
    }
    int q;
    cin >> q;
    kek.resize(q, 0);
    //vector<pair< pair<int, int>, string> > qw;
    for (int i=0; i < n; i++) for (int j=0; j < 100; j++) up[i][j] = {-1, -1};
    for (int i=0; i < n; i++) for (int j=0; j < 20; j++) binup[i][j] = -1;
    //return 0;
    dfs(0, -1, 0, 0);
    ggg.resize(n);
    //return 0;
    for (int i=0; i < q; i++){
        int u, v;
        string s;
        cin >> u >> v >> s;
        u--, v--;
        int S = s.size()-1;
        int L = LCA(u, v);
        int U = lift(u, h[L] + S);
        int V = lift(v, h[L] + S);
        string a = Lift(U, L), b = Lift(V, L);
        //cout << U << " " << V << " " << u << " " << v << " " << a << " " << b << endl;
        reverse(b.begin(), b.end());
        a += b;
        //cout << a << " " << s << endl;
        kek[i] += KMP(a, s);
        LL A = 0, B = 0;
        for (int j=s.size() - 1; j >= 0; j--){
            A *= 1LL*PS[0];
            A += s[j];
            A %= MOD[0];
            B *= 1LL*PS[1];
            B += s[j];
            B %= MOD[1];
        }
        LL gh = 2e9*A+B;
        A = 0, B = 0;
        for (int j=0; j < s.size(); j++){
            A *= PS[0];
            A += s[j];
            A %= MOD[0];
            B *= PS[1];
            B += s[j];
            B %= MOD[1];
        }
        LL hh = 2e9*A+B;
        //cout << A << " " << B << endl;
        ggg[U].push_back({gh, -(i+1)});
        ggg[u].push_back({gh, i+1});
        ggg[V].push_back({hh, -(i+1)});
        ggg[v].push_back({hh, i+1});
        govno.insert(gh);
        govno.insert(hh);
    }
  // if (n ==99001) return 1;
    solve(0, -1);
    for (int i=0;i<q;i++) cout << kek[i] << "\n";

}