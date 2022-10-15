#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const long long inf = 1e18;
const int N = 4e5 + 5, L = 11;

int n, q, a[N];
long long pwr[L + 1];

inline long long get(long long x) {
    return x - *std::lower_bound(pwr, pwr + L, x);
}

struct SegmentTree {
    long long f[N], g[N], tag[N], tag0[N], add[N];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = std::max(f[ls], f[rs]);
        g[u] = g[ls] == g[rs] ? g[ls] : -inf;
    }
    inline void pushTag(int u, long long x, long long x0) {
        tag[u] = x; tag0[u] = x0; add[u] = 0;
        f[u] = x0; g[u] = x;
    }
    inline void pushAdd(int u, long long x) {
        add[u] += x; f[u] += x; g[u] += x;
    }
    inline void pushDown(int u) {
        int ls = u << 1, rs = ls | 1;
        if (tag[u] != -1) {
            pushTag(ls, tag[u], tag0[u]);
            pushTag(rs, tag[u], tag0[u]);
            tag[u] = -1;
        }
        if (add[u] != 0) {
            pushAdd(ls, add[u]); pushAdd(rs, add[u]);
            add[u] = 0;
        }
    }

    void build(int u, int l, int r) {
        if (l + 1 >= r) { f[u] = get(a[l]); g[u] = a[l]; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        tag[u] = -1; add[u] = 0;
        build(ls, l, mid); build(rs, mid, r);
        pushUp(u);
    }
    void assign(int u, int l, int r, int pl, int pr, int x, int x0) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { pushTag(u, x, x0); return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (pr <= mid) {
            assign(ls, l, mid, pl, pr, x, x0);
        } else if (pl >= mid) {
            assign(rs, mid, r, pl, pr, x, x0);
        } else {
            assign(ls, l, mid, pl, mid, x, x0);
            assign(rs, mid, r, mid, pr, x, x0);
        }
        pushUp(u);
    }
    void modify(int u, int l, int r, int pl, int pr, int x) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { pushAdd(u, x); return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (pr <= mid) {
            modify(ls, l, mid, pl, pr, x);
        } else if (pl >= mid) {
            modify(rs, mid, r, pl, pr, x);
        } else {
            modify(ls, l, mid, pl, mid, x);
            modify(rs, mid, r, mid, pr, x);
        }
        pushUp(u);
    }
    void figure(int u, int l, int r) {
        if (f[u] <= 0) { return; }
        if (g[u] >= 0) { pushTag(u, g[u], get(g[u])); return; }
        if (l + 1 >= r) { return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        figure(ls, l, mid); figure(rs, mid, r);
        pushUp(u);
    }
    void query(int u, int l, int r, int p, long long &res) {
        if (l + 1 >= r) { res = g[u]; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (p < mid) {
            query(ls, l, mid, p, res);
        } else {
            query(rs, mid, r, p, res);
        }
        pushUp(u);
    }
} smt;

int main() {
    n = read(); q = read();
    for (int i = 0; i < n; i++) {
        a[i] = read();
    }
    pwr[0] = 1;
    for (int i = 0; i < L; i++) {
        pwr[i + 1] = pwr[i] * 42;
    }
    smt.build(1, 0, n);
    for (; q; q--) {
        int opt = read();
        if (opt == 1) {
            int p = read(); p--;
            long long ans;
            smt.query(1, 0, n, p, ans);
            printf("%lld\n", ans);
        } else if (opt == 2) {
            int l = read(), r = read(), x = read(); l--;
            smt.assign(1, 0, n, l, r, x, get(x));
        } else {
            int l = read(), r = read(), x = read(); l--;
            do {
                smt.modify(1, 0, n, l, r, x);
                smt.figure(1, 0, n);
            } while (smt.f[1] == 0);
        }
    }
    return 0;
}