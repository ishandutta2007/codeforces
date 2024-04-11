#include <bits/stdc++.h>
using namespace std;

const int N = 2050;
typedef long long ll;
const ll INF = (ll)1e18;

int v[N];

struct edge{
    int to;
    ll cap;
    int rev;
    edge(int _to, ll _cap, int _rev){
        to = _to, cap = _cap, rev = _rev;
    }
};

int n,m,s,d,a,b,c;
string str;
vector<edge> G[N];
char temp[N];
int level[N], iter[N];
bool used[N];

void add_edge(int from, int to, ll cap){
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size() - 1));
}

void bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int i = 0; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}


ll dfs(int v, int t, ll f){
    if(v == t) return f;

    for(int &i = iter[v]; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]){
            ll d = dfs(e.to, t, min(e.cap, f));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}


ll max_flow(int s, int t){
    ll flow = 0;
    for(;;){
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        ll f;
        while((f = dfs(s, t, INF)) > 0){
            flow += f;
        }
    }
}

int main(){
    ll tsum = 0;
    cin >> n >> m;
    int s = n + m, t = s + 1;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        add_edge(s, i, v[i]);
    }
    for(int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        add_edge(a, i + n, INF);
        add_edge(b, i + n, INF);
        add_edge(i + n, t, c);
        tsum += c;
    }

    cout << tsum - max_flow(s, t) << endl;
//    cout << tsum - max_flow(s, t) << endl;
}