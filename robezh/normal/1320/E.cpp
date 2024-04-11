#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = (int)2e5 + 50, INF = (int)1e9 + 50;
const int LOG_N = 18;

int n;
int root = 0;

vector<int> G[N];
int parent[LOG_N][N];
int depth[N], dfn[N], T = 0;

void dfs(int v, int p, int d){
    dfn[v] = T++;
    parent[0][v] = p;
    depth[v] = d;
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
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < LOG_N; k++){
        if((depth[v] - depth[u]) >> k & 1){
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
    return depth[u] + depth[v] - 2 * depth[ca];
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
            while(sz >= 2 && depth[stk[sz-1]] >= depth[x]) {
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

int v[N], s[N], u[N];


struct Cost {
    int sp, cost;
    bool operator < (const Cost &o) const {
        if(sp == -1) return false;
        if(o.sp == -1) return true;
        int bk1 = (cost + s[sp] - 1) / s[sp], bk2 = (o.cost + s[o.sp] - 1) / s[o.sp];
        return bk1 != bk2 ? bk1 < bk2 : (sp != o.sp ? sp < o.sp : cost < o.cost);
    }
};

typedef pair<Cost, int> Ci;

Cost dis[N];

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
        int k, m;
        cin >> k >> m;
        vector<int> ns;
        for(int i = 0; i < k; i++) {
            cin >> v[i] >> s[i]; v[i]--;
            ns.push_back(v[i]);
        }
        for(int i = 0; i < m; i++) {
            cin >> u[i]; u[i]--;
            ns.push_back(u[i]);
        }
        sort(ns.begin(), ns.end());
        ns.resize(unique(ns.begin(), ns.end()) - ns.begin());

        build(ns);
        for(auto v : vir) dis[v] = {-1, -1};
        priority_queue<Ci, vector<Ci>, greater<Ci> > pque;
        for(int i = 0; i < k; i++) {
            dis[v[i]] = {i, 0};
            pque.push({dis[v[i]], v[i]});
        }
        while(!pque.empty()) {
            auto p = pque.top(); pque.pop();
            if(dis[p.second] < p.first) continue;
            Cost c = p.first;
            int v = p.second;
            for(auto e : V[v]) {
                Cost nxtc = {c.sp, c.cost + e.cost};
                if(nxtc < dis[e.to]) {
                    dis[e.to] = nxtc;
                    pque.push({nxtc, e.to});
                }
            }
        }
        for(int i = 0; i < m; i++) {
            cout << dis[u[i]].sp + 1 << " ";
        }
        cout << "\n";
    }
}