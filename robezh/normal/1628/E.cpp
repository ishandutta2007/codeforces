#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)6e5 + 50, LOGN = 20;
const int INF = (int)1e9;

struct edge {
    int u, v, c;
};

int n, q;
vi G[N];
int val[N];
vector<edge> es;
int tcnt = 0;
int f[N];


int find(int u) {
    return f[u] == u ? u : f[u] = find(f[u]);
}

int parent[LOGN][N];
int dep[N];
int tin[N], tout[N], ord[N], tim = 0;

void dfs(int v, int p, int d) {
    ord[tim] = v;
    tin[v] = tim++;
    parent[0][v] = p;
    dep[v] = d;
    for (int nxt : G[v]) {
        if(nxt != p) dfs(nxt, v, d + 1);
    }
    tout[v] = tim - 1;
}

void init(int n) {
    dfs(n - 1, -1, 0);
    for (int k = 0; k + 1 < LOGN; k++) {
        for (int v = 0; v < n; v++) {
            if(parent[k][v] < 0) parent[k + 1][v] = -1;
            else parent[k + 1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    rep(k, 0, LOGN) {
        if((dep[v] - dep[u]) >> k & 1) v = parent[k][v];
    }
    if(u == v) return v;
    for (int k = LOGN - 1; k >= 0; k--) {
        if(parent[k][u] != parent[k][v]) {
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

#define ls(x) 2*x+1
#define rs(x) 2*x+2

struct Tree {
    int mx[N * 4], mn[N * 4], tmx[N * 4], tmn[N * 4];
    int set[N * 4];

    void setnode(int x, int tag) {
        set[x] = tag;
        if(tag == 0) {
            tmx[x] = -INF;
            tmn[x] = INF;
        } else {
            tmx[x] = mx[x];
            tmn[x] = mn[x];
        }
    }

    void push_down(int x, int l, int r) {
        if(set[x] != -1) {
            if(l < r) {
                setnode(ls(x), set[x]);
                setnode(rs(x), set[x]);
            }
            set[x] = -1;
        }
    }

    void merge(int x) {
        tmx[x] = max(tmx[ls(x)], tmx[rs(x)]);
        tmn[x] = min(tmn[ls(x)], tmn[rs(x)]);
    }


    void init(int x, int l, int r) {
        if(l == r) {
            set[x] = -1;
            mx[x] = mn[x] = tin[l];
            tmx[x] = -INF;
            tmn[x] = INF;
            return;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        set[x] = -1;
        mx[x] = max(mx[ls(x)], mx[rs(x)]);
        mn[x] = min(mn[ls(x)], mn[rs(x)]);
        tmx[x] = -INF;
        tmn[x] = INF;
    }

    void update(int a, int b, int x, int l, int r, int tag) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;
        push_down(x, l, r);
        if(a <= l && r <= b) {
            setnode(x, tag);
            return ;
        }
        update(a, b, ls(x), l, mid, tag);
        update(a, b, rs(x), mid + 1, r, tag);
        merge(x);
    }
} tree;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 0, n - 1) {
        int u, v, c;
        cin >> u >> v >> c; u--, v--;
        es.push_back({u, v, c});
    }
    sort(all(es), [](const edge &e1, const edge &e2) {
        return e1.c < e2.c;
    });
    iota(f, f + 2 * n - 1, 0);
    tcnt = n;
    rep(i, 0, n) val[i] = -INF;
    for (auto &e : es) {
        int par = tcnt++;
        int u = find(e.u), v = find(e.v);
        assert(u != v);
        val[par] = e.c;
        f[u] = f[v] = par;
        G[par].push_back(u);
        G[par].push_back(v);

//        cout << par << " to " << u << " and " << v << " with value " << e.c << endl;
    }
    init(tcnt);

    tree.init(0, 0, n - 1);

    while(q--) {
        int tp; cin >> tp;
        if(tp <= 2) {
            int l, r; cin >> l >> r; l--, r--;
            tree.update(l, r, 0, 0, n - 1, (tp == 1 ? 1 : 0));
        } else {
            int x; cin >> x; x--;
            int l = min(tin[x], tree.tmn[0]), r = max(tin[x], tree.tmx[0]);
//            cout << l <<
            int ca = lca(ord[l], ord[r]);
            cout << (val[ca] == -INF ? -1 : val[ca]) << '\n';
        }
    }


}