#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> P;
typedef vector<int> vi;
typedef vector<ll> vl;
#define what_is(x) cerr << #x << " is " << x << endl;

const int N = 150050, LOGN = 18;

int n, m, k;
vector<int> G[N];
int parent[LOGN][N];
int depth[N];
vector<pii> qr[N];
int tin[N], tout[N], ord[N], tim = 0;
int root = 0;

struct BIT {
    int bit[N];

    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    void add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }
} bit;

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    ord[tim] = v;
    tin[v] = tim++;
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v, d+1);
    }
    tout[v] = tim - 1;
}

void init(){
    dfs(root, -1, 0);

    for(int k = 0; k+1 < LOGN; k++){
        for(int v = 0; v < n; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int climb(int u, int d) {
    for(int k = 0; k < LOGN; k++) if(d >> k & 1) u = parent[k][u];
    return u;
}

int lca(int u, int v){
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    v = climb(v, depth[v] - depth[u]);
    if(u == v) return u;
    for(int k = LOGN - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

ll res = 0;

void solve(int v, int p) {
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        solve(nxt, v);
    }
    for(auto x : qr[v]) {
        res += bit.get(tin[x.first]);
    }
    for(auto x : qr[v]) {
        if(depth[x.first] - depth[v] >= k) {
            int c = climb(x.first, depth[x.first] - depth[v] - k);
            bit.add(tin[c], tout[c], 1);
        }
    }
    for(auto x : qr[v]) {
        res += bit.get(tin[x.second]);
    }
    for(auto x : qr[v]) {
        if(depth[x.second] - depth[v] >= k) {
            int c = climb(x.second, depth[x.second] - depth[v] - k);
            bit.add(tin[c], tout[c], 1);
        }
    }
}

using Tree = tree<P, null_type, less<P>, rb_tree_tag,
        tree_order_statistics_node_update>;


int stk[N];
vector<int> vir;
vector<int> V[N];
vector<pii> ins[N];

void add_edge(int u, int v) {
    V[u].push_back(v);
    V[v].push_back(u);
}

void build(vector<int> vec) {
    for(auto u : vir) V[u].clear();
    vir = vec;
    sort(vec.begin(),vec.end(),[](int u,int v) {return tin[u]<tin[v];});
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

Tree tr[N];
int idx[N];

void solve2(int v, int p, int root) {
    int &t0 = idx[v];
    t0 = v;
    tr[t0].clear();
    for(int nxt : V[v]) {
        if(nxt == p) continue;
        solve2(nxt, v, root);
        int &t1 = idx[nxt];
        if(tr[t0].size() < tr[t1].size()) swap(t0, t1);
        for(P pp : tr[t1]) {
            int to = pp.second.first;
            if(depth[v] - depth[root] >= k) {
                res += tr[t0].size();
            }
            else if(depth[v] + depth[to] - depth[root] * 2 >= k) {
                int c = climb(to, (depth[v] + depth[to] - depth[root] * 2) - k);
                res += tr[t0].order_of_key({tout[c] + 1, {-1, -1}}) - tr[t0].order_of_key({tin[c], {-1, -1}});
            }
        }
        for(P pp : tr[t1]) tr[t0].insert(pp);
    }
    for(auto pp : ins[v]) {
        int to = pp.first;
        if (depth[v] - depth[root] >= k) {
            res += tr[t0].size();
        }
        else if (depth[v] + depth[to] - depth[root] * 2 >= k) {
            int c = climb(to, (depth[v] + depth[to] - depth[root] * 2) - k);
            res += tr[t0].order_of_key({tout[c] + 1, {-1, -1}}) - tr[t0].order_of_key({tin[c], {-1, -1}});

        }
        tr[t0].insert({tin[to], pp});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 0; i < n; i++) sort(all(G[i]));
    init();
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        if(tin[u] > tin[v]) swap(u, v);
        int ca = lca(u, v);
        qr[ca].push_back({u, v});
    }
    solve(0, -1);

    for(int v = 0; v < n; v++) {
        vi vec = {v};
        int tim = 0;
        for(auto p : qr[v]) {
            vec.push_back(p.first);
            ins[p.first].push_back({p.second, tim++});
        }
        sort(all(vec));
        vec.resize(unique(all(vec)) - vec.begin());
        build(vec);
        solve2(v, -1, v);
        for(auto x : vir) tr[x].clear();
        for(auto p : qr[v]) ins[p.first].clear();
    }

    cout << res << endl;
}