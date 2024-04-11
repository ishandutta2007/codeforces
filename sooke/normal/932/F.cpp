#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e5 + 5, E = 2e5 + 5, V = 1e7 + 5;

int n, a[N], b[N];
long long f[N];

struct List {
    int tot, fst[N], nxt[E], to[E];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v) {
        nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++;
    }
    inline void link(int u, int v) {
        insert(u, v); insert(v, u);
    }
} e;

struct Line {
    int a;
    long long b;

    inline long long y(int x) {
        return 1ll * a * x + b;
    }
} s[N];

struct SegmentTree {
    int tot, rt[N], f[V], ls[V], rs[V];

    SegmentTree() { tot = 1; }

    void modify(int &u, int l, int r, int i) {
        if (u == 0) { u = tot++; f[u] = n; }
        int mid = (l + r) / 2, j = f[u];
        long long il = s[i].y(l), ir = s[i].y(r), jl = s[j].y(l), jr = s[j].y(r);
        if (il > jl && ir > jr) { return; }
        if (il < jl && ir < jr) { f[u] = i; return; }
        long long im = s[i].y(mid), jm = s[j].y(mid);
        if (im > jm) { std::swap(i, j); std::swap(il, jl); std::swap(ir, jr); }
        f[u] = i;
        if (il > jl) { modify(ls[u], l, mid, j); }
        if (ir > jr) { modify(rs[u], mid, r, j); }
    }
    long long query(int u, int l, int r, int p) {
        if (u == 0) { return 1e18; }
        if (r - l <= 1) { return s[f[u]].y(p); }
        int mid = (l + r) / 2;
        if (p < mid) {
            return std::min(query(ls[u], l, mid, p), s[f[u]].y(p));
        } else {
            return std::min(query(rs[u], mid, r, p), s[f[u]].y(p));
        }
    }
    void merge(int &u, int v, int l, int r) {
        if (u == 0 || v == 0) { u |= v; return; }
        modify(u, l, r, f[v]);
        int mid = l + r >> 1;
        merge(ls[u], ls[v], l, mid);
        merge(rs[u], rs[v], mid, r);
    }
} smt;

void dfs(int u, int fa) {
    bool flag = true;
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i];
        if (v != fa) {
            flag = false; dfs(v, u);
            smt.merge(smt.rt[u], smt.rt[v], -N, N);
        }
    }
    if (!flag) { f[u] = smt.query(smt.rt[u], -N, N, a[u]); }
    s[u] = (Line) {b[u], f[u]}; smt.modify(smt.rt[u], -N, N, u);
}

int main() {
    n = read();
    for (int u = 0; u < n; u++) { a[u] = read(); }
    for (int u = 0; u < n; u++) { b[u] = read(); }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(); u--; v--;
        e.link(u, v);
    }
    s[n] = (Line) {0, (long long) 1e18}; dfs(0, 0);
    for (int u = 0; u < n; u++) { printf("%I64d ", f[u]); }
    return 0;
}