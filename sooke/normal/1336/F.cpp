#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5, L = 19;

long long ans;
int n, _n, m, k, st, s[N], t[N], lca[N];
int tms, dfn[N], siz[N], lgn, ft[L][N], son[N], dep[N], dis[N];
vector<int> a[N], b[N];
vector<pair<int, int>> e[N];
set<pair<int, int>> _e[N];

struct Fenwick {
    int f[N];

    void modify(int u, int x) {
        for (int i = u; i <= n; i += i & -i) { f[i] += x; }
    }
    int query(int u) {
        int res = 0;
        for (int i = u; i >= 1; i ^= i & -i) { res += f[i]; }
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
} fw;

void dfs(int u, int fa) {
    ft[0][u] = fa; dfn[u] = ++tms; siz[u] = 1;
    for (int i = 1; i <= lgn; i++) { ft[i][u] = ft[i - 1][ft[i - 1][u]]; }
    for (auto i : e[u]) {
        int v = i.first, w = i.second;
        if (v == fa) { continue; }
        dep[v] = dep[u] + 1; dis[v] = dis[u] + w;
        dfs(v, u); siz[u] += siz[v];
        if (son[u] == 0) { son[u] = v; }
    }
}
int findLca(int u, int v) {
    if (dep[u] < dep[v]) { swap(u, v); }
    int x = dep[u] - dep[v];
    for (int i = lgn; i >= 0; i--) {
        if (x >> i & 1) { u = ft[i][u]; }
    }
    if (u == v) { return u; }
    for (int i = lgn; i >= 0; i--) {
        if (ft[i][u] != ft[i][v]) { u = ft[i][u]; v = ft[i][v]; }
    }
    return ft[0][u];
}
int climb(int u, int v, int x) {
    if (x <= 0) { return u; }
    x = dis[v] - dis[u] - x; u = v;
    if (x < 0) { return -1; }
    for (int i = lgn; i >= 0; i--) {
        if (dis[u] - dis[ft[i][v]] <= x) { v = ft[i][v]; }
    }
    return v;
}

struct Treap {
    int ls[N], rs[N], siz[N], val[N], key[N];

    inline void newNode(int u) {
        ls[u] = rs[u] = 0; siz[u] = 1; key[u] = rand();
    }
    inline void pushUp(int u) {
        siz[u] = siz[ls[u]] + siz[rs[u]] + 1;
    }
    
    void split(int u, int x, int y, int &l, int &r) {
        if (u == 0) { l = r = 0; return; }
        if (x < val[u] || (x == val[u] && y < u)) {
            r = u; split(ls[u], x, y, l, ls[r]);
        } else {
            l = u; split(rs[u], x, y, rs[l], r);
        }
        pushUp(u);
    }
    int merge(int l, int r) {
        if (l == 0 || r == 0) { return l + r; }
        if (key[l] < key[r]) {
            rs[l] = merge(rs[l], r); pushUp(l); return l;
        } else {
            ls[r] = merge(l, ls[r]); pushUp(r); return r;
        }
    }

    void insert(int &rt, int u) {
        int l, r; split(rt, val[u], u, l, r);
        newNode(u); rt = merge(merge(l, u), r);
    }
    void erase(int &rt, int u) {
        int l, mid, r; split(rt, val[u], u - 1, l, r); split(r, val[u], u, mid, r);
        rt = merge(l, r);
    }
    int query(int &rt, int u) {
        int l, mid, r; split(rt, dfn[u], 0, l, r); split(r, dfn[u] + ::siz[u], 0, mid, r);
        int res = siz[mid]; rt = merge(merge(l, mid), r); return res;
    }
    void calc(int &rt, int u, int p) {
        if (u == 0) { return; }
        calc(rt, ls[u], p); calc(rt, rs[u], p);
        int v = climb(lca[u], t[u], k - dis[p] + dis[lca[u]]);
        if (v == -1) { return; }
        ans += query(rt, v) - (lca[u] == v ? query(rt, son[v]) : 0);
    }
    void go(int &rt, int u) {
        if (u == 0) { return; }
        go(rt, ls[u]); go(rt, rs[u]);
        insert(rt, u);
    }
} tr;

int solve(int u) {
    for (auto i : a[u]) {
        int v = climb(u, s[i], k);
        if (v > 0) { ans += fw.query(dfn[v], dfn[v] + siz[v] - 1); }
        v = climb(u, t[i], k);
        if (v > 0) { ans += fw.query(dfn[v], dfn[v] + siz[v] - 1); }
    }
    for (auto i : a[u]) { fw.modify(dfn[s[i]], 1); fw.modify(dfn[t[i]], 1); }
    int rt = 0;
    for (auto i : b[u]) { tr.val[i] = dfn[t[i]]; tr.calc(rt, i, u); tr.go(rt, i); }
    for (auto i : e[u]) {
        int v = i.first;
        if (v == ft[0][u]) { continue; }
        int _rt = solve(v);
        if (tr.siz[rt] < tr.siz[_rt]) { swap(rt, _rt); }
        tr.calc(rt, _rt, u); tr.go(rt, _rt);
    }
    for (auto i : a[u]) { tr.erase(rt, i); }
    return rt;
}

int main() {
    cin >> _n >> m >> k; n = _n;
    for (int i = 1; i < _n; i++) {
        int u, v; cin >> u >> v;
        _e[u].insert({v, 1}); _e[v].insert({u, 1});
    }
    for (int u = 1; u <= _n; u++) {
        if (_e[u].size() < 4) { continue; } e[0].clear();
        for (auto i : _e[u]) { e[0].push_back(i); }
        int fa = 0;
        for (auto i : e[0]) {
            int v = i.first, w = i.second, r = fa > 0 ? ++n : u;
            _e[v].erase({u, w}); _e[u].erase({v, w});
            _e[v].insert({r, w}); _e[r].insert({v, w});
            if (fa > 0) { _e[fa].insert({r, 0}); _e[r].insert({fa, 0}); } fa = r;
        }
    }
    lgn = log(n) / log(2) + 1e-7;
    for (int u = 1; u <= n; u++) {
        for (auto i : _e[u]) { e[u].push_back(i); }
        if (e[u].size() == 1) { st = u; }
    }
    dfs(st, 0);
    for (int i = 1; i <= m; i++) {
        cin >> s[i] >> t[i]; lca[i] = findLca(s[i], t[i]);
        if (dfn[s[i]] > dfn[t[i]]) { swap(s[i], t[i]); }
        if (dfn[t[i]] < dfn[son[lca[i]]] + siz[son[lca[i]]]) { swap(s[i], t[i]); }
        a[lca[i]].push_back(i); b[s[i]].push_back(i);
    }
    solve(st);
    cout << ans;
    return 0;
}