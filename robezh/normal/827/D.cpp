#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = 200050, INF = (int)1e9 + 50;
const int LOG_N = 18;
int root = 0;
int n, m;

struct toedge {
    int to, cost, id;
};

struct biedge {
    int a, b, cost, id;
} es[N];

int f[N];

int find(int u) {
    return f[u] == u ? u : f[u] = find(f[u]);
}
bool same(int u, int v) {
    return find(u) == find(v);
}
void unite(int u, int v) {
    f[find(u)] = find(v);
}


vector<toedge> G[N];
int parent[LOG_N][N];
int mxval[LOG_N][N];
int st[LOG_N][N];
int depth[N], par[N], eid[N];
int in_tree[N];

void dfs(int v, int p, int d, int val, int lid){
    parent[0][v] = p;
    depth[v] = d;
    mxval[0][v] = val;
    eid[v] = lid;
    for(auto e : G[v]){
        if(e.to != p) dfs(e.to, v, d + 1, e.cost, e.id);
    }
}

void init(int V){
    dfs(root, -1, 0, INF, -1);

    for(int k = 0; k+1 < LOG_N; k++){
        for(int v = 0; v < V; v++){
            if(parent[k][v] < 0) {
                parent[k+1][v] = -1;
                mxval[k + 1][v] = mxval[k][v];
            }
            else {
                parent[k+1][v] = parent[k][parent[k][v]];
                mxval[k + 1][v] = max(mxval[k][v], mxval[k][parent[k][v]]);
            }
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

int getmax(int u, int ca) {
    int res = 0;
    for(int k = 0; k < LOG_N; k++){
        if((depth[u] - depth[ca]) >> k & 1){
            res = max(res, mxval[k][u]);
            u = parent[k][u];
        }
    }
    return res;
}

void upd(int u, int ca, int val) {
    for(int k = 0; k < LOG_N; k++){
        if((depth[u] - depth[ca]) >> k & 1){
            st[k][u] = min(st[k][u], val);
            u = parent[k][u];
        }
    }
}

int fres[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        es[i] = {a, b, c, i};
    }
    iota(f, f + n, 0);
    sort(es, es + m, [](const biedge &e1, const biedge &e2) {
        return e1.cost < e2.cost;
    });
    rep(i, 0, m) {
        if(!same(es[i].a, es[i].b)) {
            unite(es[i].a, es[i].b);
            G[es[i].a].push_back({es[i].b, es[i].cost, es[i].id});
            G[es[i].b].push_back({es[i].a, es[i].cost, es[i].id});
            in_tree[es[i].id] = 1;
//            cout << es[i].a << " " << es[i].b << " " << es[i].cost << endl;
        }
    }
    init(n);
    rep(i, 0, LOG_N) rep(j, 0, N) st[i][j] = INF;
    rep(i, 0, m) {
        if(!in_tree[es[i].id]) {
            int ca = lca(es[i].a, es[i].b);
            fres[es[i].id] = max(getmax(es[i].a, ca), getmax(es[i].b, ca)) - 1;
            upd(es[i].a, ca, es[i].cost);
            upd(es[i].b, ca, es[i].cost);
        }
    }
    for(int i = LOG_N - 1; i >= 1; i--) {
        for (int j = 0; j < n; j++) {
            st[i - 1][j] = min(st[i - 1][j], st[i][j]);
            int p = parent[i - 1][j];
            if(p >= 0) st[i - 1][p] = min(st[i - 1][p], st[i][j]);
        }
    }
    for(int i = 1; i < n; i++) {
        fres[eid[i]] = st[0][i] - 1;
    }
    rep(i, 0, m) {
        if(fres[i] > (int)1e9) cout << -1 << " ";
        else cout << fres[i] << " ";
    }
    cout << endl;





}