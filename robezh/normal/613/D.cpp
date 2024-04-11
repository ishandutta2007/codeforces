#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)2e5 + 50, INF = (int)1e9;
const int LOG_N = 18;
int root = 0;
int n;

vector<int> G[N];
int parent[LOG_N][N];
int dep[N];
int dfn[N], T = 0;

void dfs(int v, int p, int d){
    dfn[v] = T++;
    parent[0][v] = p;
    dep[v] = d;
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v, d+1);
    }
}

void init(int V){
    dfs(root, -1, 0);

    for(int k = 0; k+1 < LOG_N; k++){
        for(int v = 0; v < V; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if(dep[u] > dep[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < LOG_N; k++){
        if((dep[v] - dep[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if(u == v) return u;
    for(int k = LOG_N - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int min_dis(int u, int v){
    int ca = lca(u, v);
    return dep[u] + dep[v] - 2 * dep[ca];
}

struct edge {
    int to, cost;
};


int stk[N];
vector<int> vir;
vector<edge> V[N];

void add_edge(int u, int v) {
    int cost = min_dis(u, v);
    V[u].push_back({v, cost});
    V[v].push_back({u, cost});
}

void build(vector<int> vec) {
    for(auto u : vir) V[u].clear();
    vir = vec;
    sort(vec.begin(),vec.end(),[](int u,int v) {return dfn[u]<dfn[v];});
    int sz = 0;
    stk[++sz] = vec[0];
    for(auto u : vec) {
        int x = lca(u, stk[sz]);
        vir.push_back(x);
        if(x != stk[sz]) {
            while(sz >= 2 && dep[stk[sz-1]] >= dep[x]) {
                add_edge(stk[sz-1], stk[sz]);
                sz--;
            }
            if(x != stk[sz]) {
                add_edge(x, stk[sz]);
                stk[sz] = x;
            }
        }
        if(u != stk[sz]) stk[++sz] = u;
    }
    for(int i=1;i<=sz-1;i++) add_edge(stk[i], stk[i+1]);
}

int in[N];
int ans = 0;
int dp[N];

void solve(int v, int p) {
    int childcnt = 0;
    for(auto e : V[v]) {
        if(e.to == p) continue;
        solve(e.to, v);
        childcnt += dp[e.to];
    }
    if(in[v]) {
        ans += childcnt;
        dp[v] = 1;
    }
    else {
        if(childcnt >= 2) {
            dp[v] = 0;
            ans += 1;
        }
        else if(childcnt == 1) {
            dp[v] = 1;
        }
        else {
            dp[v] = 0;
        }
    }
}

int solve() {
    int k;
    cin >> k;
    vi ns;
    for(int i = 0; i < k; i++) {
        int u; cin >> u; u--;
        ns.push_back(u);
        in[u] = true;
    }
    build(ns);

    bool bad = false;
    for(auto v : ns) {
        for(auto e : V[v]) {
            if(e.cost == 1 && in[e.to]) {
//                cout << v << " " << e.to << endl;
                bad = true;
            }
        }
    }
    if(bad) {
        for(int x : ns) in[x] = false;
        return -1;
    }
    ans = 0;
    solve(ns[0], -1);

    for(int x : ns) in[x] = false;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    init(n);
    int q;
    cin >> q;
    while(q--) {
        cout << solve() << '\n';
    }
}