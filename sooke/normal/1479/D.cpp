#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

std::mt19937_64 rng(2021);

const int N = 12e5 + 5;

struct Query {
    int i, u, v, lca;
};

int n, q, ql, qr, a[N], tms, dep[N], ft[N], dfn[N], siz[N], top[N], hs[N], ans[N];
unsigned long long val1[N], val2[N];
std::vector<int> e[N], p[N];
std::vector<Query> qry[N], _qry[N];

struct FenwickTree {
    unsigned long long f[N];
    
    void modify(int u, unsigned long long x) {
        for (int i = u; i <= n; i += i & -i) {
            f[i] ^= x;
        }
    }
    unsigned long long query(int u) {
        unsigned long long res = 0;
        for (int i = u; i >= 1; i ^= i & -i) {
            res ^= f[i];
        }
        return res;
    }
} tr1, tr2;

void modify(int c) {
    for (auto u : p[c]) {
        tr1.modify(dfn[u], val1[c]);
        tr1.modify(dfn[u] + siz[u], val1[c]);
        tr2.modify(dfn[u], val2[c]);
        tr2.modify(dfn[u] + siz[u], val2[c]);
    }
}
bool query(int u, int v, int lca) {
    int w = a[lca];
    if (w < ql || w >= qr) { w = n; }
    if ((tr1.query(dfn[u]) ^ tr1.query(dfn[v])) != val1[w]) { return true; }
    if ((tr2.query(dfn[u]) ^ tr2.query(dfn[v])) != val2[w]) { return true; }
    return false;
}

void dfs1(int u, int fa) {
    ft[u] = fa; dep[u] = dep[fa] + 1; siz[u] = 1; hs[u] = 0;
    for (auto v : e[u]) {
        if (v != fa) {
            dfs1(v, u); siz[u] += siz[v];
            if (siz[hs[u]] < siz[v]) { hs[u] = v; }
        }
    }
}
void dfs2(int u, int tp) {
    top[u] = tp; dfn[u] = ++tms;
    if (hs[u]) { dfs2(hs[u], tp); }
    for (auto v : e[u]) {
        if (v != ft[u] && v != hs[u]) { dfs2(v, v); }
    }
}
 
int findLca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            u = ft[top[u]];
        } else {
            v = ft[top[v]];
        }
    }
    return dep[u] < dep[v] ? u : v;
}

void insert(int u, int l, int r, int pl, int pr, Query x) {
    if (pl >= pr) { return; }
    if (l == pl && r == pr) { _qry[u].push_back(x); return; }
    int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
    if (pr <= mid) {
        insert(ls, l, mid, pl, pr, x);
    } else if (pl >= mid) {
        insert(rs, mid, r, pl, pr, x);
    } else {
        insert(ls, l, mid, pl, mid, x);
        insert(rs, mid, r, mid, pr, x);
    }
}

void solve(int u, int l, int r) {
    while (qr < r) { modify(qr++); }
    while (l < ql) { modify(--ql); }
    while (r < qr) { modify(--qr); }
    while (ql < l) { modify(ql++); }
    for (auto i : _qry[u]) {
        if (ans[i.i] != -1) { continue; }
        if (query(i.u, i.v, i.lca)) { qry[u].push_back(i); }
    }
    if (l + 1 >= r) {
        for (auto i : qry[u]) { ans[i.i] = l + 1; }
        return;
    }
    int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
    for (auto i : qry[u]) {
        if (ans[i.i] != -1) { continue; }
        _qry[ls].push_back(i);
    }
    solve(ls, l, mid);
    for (auto i : qry[u]) {
        if (ans[i.i] != -1) { continue; }
        qry[rs].push_back(i);
    }
    solve(rs, mid, r);
}

int main() {
    n = read(); q = read();
    for (int u = 1; u <= n; u++) {
        a[u] = read(); a[u]--;
        p[a[u]].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        val1[i] = rng(); val2[i] = rng();
    }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v); e[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1, 1);
    for (int i = 0; i < q; i++) {
        int u = read(), v = read(), l = read(), r = read(); l--;
        insert(1, 0, n, l, r, (Query) {i, u, v, findLca(u, v)}); ans[i] = -1;
    }
    ql = 0; qr = 0;
    solve(1, 0, n);
    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}