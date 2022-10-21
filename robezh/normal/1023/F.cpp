#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 500050, INF = (int)1e9 + 50, LOGN = 19;
int n, m, k;

struct edge {
    int u, v, cost;
};

vi G[N];
int parent[LOGN][N];
int mn[LOGN][N];
edge es[N];
int f[N];

int depth[N], vis[N], rt[N];

void dfs(int v, int p, int d, int r){
    rt[v] = r;
    vis[v] = 1;
    parent[0][v] = p;
    depth[v] = d;
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v, d+1, r);
    }
}

void init(){
    rep(i, 0, n) if(!vis[i]) dfs(i, -1, 0, i);

    for(int k = 0; k+1 < LOGN; k++){
        for(int v = 0; v < n; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < LOGN; k++){
        if((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if(u == v) return u;
    for(int k = LOGN - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

void upd(int u, int d, int val) {
    for(int k = 0; k < LOGN; k++) {
        if (d >> k & 1) {
            mn[k][u] = min(mn[k][u], val);
            u = parent[k][u];
        }
    }
}

int find(int u) {return f[u] == u ? u : f[u] = find(f[u]);}
void unite(int u, int v) {
    f[find(u)] = find(v);
}
ll res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    rep(i, 0, n) f[i] = i;
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
        unite(a, b);
    }
    rep(i, 0, k) {
        int a, b, w; cin >> a >> b >> w; a--, b--;
        es[i] = {a, b, w};
        if(find(a) != find(b)) {
            G[a].push_back(b);
            G[b].push_back(a);
            res -= w;
            unite(a, b);
        }
    }
    init();
    rep(i, 0, LOGN) fill(mn[i], mn[i] + N, INF);
    rep(i, 0, k) {
        int a, b, w;
        tie(a, b, w) = {es[i].u, es[i].v, es[i].cost};
        if(rt[a] != rt[b]) continue;
        int ca = lca(a, b);
        upd(a, depth[a] - depth[ca], w);
        upd(b, depth[b] - depth[ca], w);
    }
    for(int i = LOGN - 1; i >= 1; i--) {
        for(int j = 0; j < n; j++) {
            mn[i - 1][j] = min(mn[i - 1][j], mn[i][j]);
            int hf = parent[i - 1][j];
            if(hf == -1) continue;
            mn[i - 1][hf] = min(mn[i - 1][hf], mn[i][j]);
        }
    }
    rep(i, 0, n) {
        if(parent[0][i] == -1) continue;
        if(mn[0][i] == INF) return cout << -1 << endl, 0;
//        cout << i << " " << mn[0][i] << endl;

        res += mn[0][i];
    }
    cout << res << endl;
}