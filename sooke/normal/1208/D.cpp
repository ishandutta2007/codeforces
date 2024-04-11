#include <bits/stdc++.h>

inline long long read() {
    char c, _c; long long x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, p[N];
long long a[N];

struct SegmentTree {
    long long f[N], g[N], tag[N];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        if (f[ls] < f[rs]) {
            f[u] = f[ls]; g[u] = g[ls];
        } else {
            f[u] = f[rs]; g[u] = g[rs];
        }
    }
    inline void pushTag(int u, long long x) {
        f[u] += x; tag[u] += x;
    }
    inline void pushDown(int u) {
        if (tag[u] != 0) {
            int ls = u << 1, rs = ls | 1;
            pushTag(ls, tag[u]); pushTag(rs, tag[u]);
            tag[u] = 0;
        }
    }
    void build(int u, int l, int r) {
        if (l + 1 >= r) {
            g[u] = l; return;
        } int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        build(ls, l, mid); build(rs, mid, r);
    }
    void modify(int u, int l, int r, int pl, int pr, long long x) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) {
            pushTag(u, x); return;
        } int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (pr <= mid) {
            modify(ls, l, mid, pl, pr, x);
        } else if (pl >= mid) {
            modify(rs, mid, r, pl, pr, x);
        } else {
            modify(ls, l, mid, pl, mid, x);
            modify(rs, mid, r, mid, pr, x);
        } pushUp(u);
    }
} smt;

int main() {
    n = read();
    smt.build(1, 0, n);
    for (int i = 0; i < n; i++) {
        a[i] = read();
        smt.modify(1, 0, n, i, i + 1, a[i]);
    }
    for (int x = 1; x <= n; x++) {
        int i = smt.g[1];
        p[i] = x;
        smt.modify(1, 0, n, i, i + 1, 1e18);
        smt.modify(1, 0, n, i + 1, n, -x);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    return 0;
} ////