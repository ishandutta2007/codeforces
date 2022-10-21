#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)5e5 + 50;

struct qry{
    int u, v, x, in;
} qr[N];

struct edge {
    int to, v;
};

int n, q;
vector<edge> G[N];

int f[N];

int find(int u) {return f[u] == u ? u : f[u] = find(f[u]);}
void unite(int u, int v) {f[find(u)] = find(v);}
bool same(int u, int v) {return find(u) == find(v);}

const int LOGN = 19;

int vis[N];
int parent[LOGN][N];
int depth[N], val[N];
int tin[N], tout[N], tim;

void dfs(int v, int p, int d, int cv){
    vis[v] = 1;
    parent[0][v] = p;
    depth[v] = d;
    val[v] = cv;
    tin[v] = tim++;
    for(auto e : G[v]){
        if(e.to != p) dfs(e.to, v, d+1, cv ^ e.v);
    }
    tout[v] = tim - 1;
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


int bit[N];

void add(int x, int val) {
    for(int i = x; i < n; i |= i + 1) bit[i] += val;
}

void add(int l, int r, int v) {
    add(l, v);
    add(r + 1, -v);
}

ll get(int x) {
    ll res = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
    return res;
}

void add_path(int u, int v) {
    int ca = lca(u, v);
    while(u != ca) {
        add(tin[u], tout[u], 1);
        u = parent[0][u];
    }
    while(v != ca) {
        add(tin[v], tout[v], 1);
        v = parent[0][v];
    }
}

int query_path(int u, int v) {
    int ca = lca(u, v);
    return get(tin[u]) + get(tin[v]) - 2 * get(tin[ca]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    iota(f, f + n, 0);
    rep(i, 0, q) {
        int u, v, x; cin >> u >> v >> x; u--, v--;
        qr[i] = {u, v, x, 0};
        if(!same(u, v)) {
            unite(u, v);
            G[u].push_back({v, x});
            G[v].push_back({u, x});
            qr[i].in = 1;
//            cout << u << " " << v << endl;
        }
    }
    rep(i, 0, n) {
        if(!vis[i]) dfs(i, -1, 0, 0);
    }
    for(int k = 0; k+1 < LOGN; k++){
        for(int v = 0; v < n; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
    rep(i, 0, q) {
        if(qr[i].in) {
            cout << "YES\n";
        } else {
            bool can_add = ((val[qr[i].u] ^ val[qr[i].v] ^ qr[i].x) == 1 && query_path(qr[i].u, qr[i].v) == 0);
            if(can_add) {
                cout << "YES\n";
                add_path(qr[i].u, qr[i].v);
            } else {
                cout << "NO\n";
            }
        }
    }

}