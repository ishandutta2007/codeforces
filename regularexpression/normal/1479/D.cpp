#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef uint64_t hsh;
uniform_int_distribution <hsh> rd(numeric_limits<hsh>::min(), numeric_limits<hsh>::max());

const int N = 3e5 + 7;
const int K = 20;

hsh key[N];

struct node {
    hsh h;
    int l, r;

    node() {}
    node(hsh h, int l, int r) : h(h), l(l), r(r) {}
};

vector <node> t;

int leaf(hsh x) {
    int id = (int)t.size();
    t.emplace_back(x, -1, -1);
    return id;
}

int update(int l, int r) {
    int id = (int)t.size();
    t.emplace_back(t[l].h ^ t[r].h, l, r);
    return id;
}

int modify(int v, int l, int r, int pos) {
    if (r - l == 1) 
        return leaf(t[v].h ^ key[pos]);
    int m = (l + r) / 2;
    int vl = t[v].l, vr = t[v].r;
    if (pos < m)
        vl = modify(t[v].l, l, m, pos);
    else 
        vr = modify(t[v].r, m, r, pos);
    return update(vl, vr);
}

int build(int l, int r) {
    if (r - l == 1)
        return leaf(0);
    int m = (l + r) / 2;
    return update(build(l, m), build(m, r));
}

int query(int v, int u, int l, int r, int ql, int qr) {
    if (l >= qr || r <= ql)
        return -1;
    int m = (l + r) / 2;
    if (l >= ql && r <= qr) {
        if (t[v].h == t[u].h)
            return -1;
        if (r - l == 1)
            return l;
        int ret = query(t[v].l, t[u].l, l, m, ql, qr);
        if (ret == -1)
            ret = query(t[v].r, t[u].r, m, r, ql, qr);
        return ret;
    }
    int ret = query(t[v].l, t[u].l, l, m, ql, qr);
    if (ret == -1)
        ret = query(t[v].r, t[u].r, m, r, ql, qr);
    return ret;
}

int n, q;
int a[N];
vector <int> g[N];
int who[N];
int up[K][N];
int tin[N], tout[N], timer = 0;

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int get_lca(int v, int u) {
    if (anc(v, u))
        return v;
    if (anc(u, v))
        return u;
    for (int i = K - 1; i >= 0; i--) {
        if (!anc(up[i][v], u))
            v = up[i][v];
    }
    return up[0][v];
}

void dfs(int v, int cur, int p = -1) {
    tin[v] = timer++;
    up[0][v] = p == -1 ? v : p;
    for (int i = 1; i < K; i++)
        up[i][v] = up[i - 1][up[i - 1][v]];
    who[v] = modify(cur, 0, n, a[v]);
    for (int u : g[v]) {
        if (u != p) 
            dfs(u, who[v], v);
    }
    tout[v] = timer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        key[i] = rd(rnd);
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, build(0, n));
    while (q--) {
        int v, u, l, r;
        cin >> v >> u >> l >> r;
        v--;
        u--;
        l--;
        int w = get_lca(v, u);
        int cv = who[v], cu = who[u];
        cv = modify(cv, 0, n, a[w]);
        int ret = query(cv, cu, 0, n, l, r);
        if (ret == -1)
            cout << -1 << "\n";
        else 
            cout << ret + 1 << "\n";
    }
}