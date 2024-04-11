#include <cctype>
#include <cstdio>
#include <algorithm>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 4e5 + 5;

int n, k, a[N], f[N], fst[N], nxt[N];

struct SegmentTree {
    int f[N], g[N];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = std::max(f[ls], f[rs]) + g[u];
    }
    void build(int u, int l, int r) {
        g[u] = 0;
        if (l + 1 >= r) {
            f[u] = ::f[l]; return;
        } int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        build(ls, l, mid); build(rs, mid, r);
        pushUp(u);
    }
    void modify(int u, int l, int r, int pl, int pr, int x) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) {
            f[u] += x; g[u] += x; return;
        } int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        if (pr <= mid) {
            modify(ls, l, mid, pl, pr, x);
        } else if (pl >= mid) {
            modify(rs, mid, r, pl, pr, x);
        } else {
            modify(ls, l, mid, pl, mid, x);
            modify(rs, mid, r, mid, pr, x);
        } pushUp(u);
    }
    int query(int u, int l, int r, int pl, int pr) {
        if (pl >= pr) { return -1e9; }
        if (l == pl && r == pr) { return f[u]; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        if (pr <= mid) {
            return g[u] + query(ls, l, mid, pl, pr);
        } else if (pl >= mid) {
            return g[u] + query(rs, mid, r, pl, pr);
        } else {
            return g[u] + std::max(query(ls, l, mid, pl, mid),
                                   query(rs, mid, r, mid, pr));
        }
    }
} smt;

int main() {
    n = read(); k = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read(); f[i] = -1e9;
        nxt[i] = fst[a[i]]; fst[a[i]] = i;
    }
    for (; k; k--) {
        smt.build(1, 0, n);
        for (int i = 1; i <= n; i++) {
            smt.modify(1, 0, n, nxt[i], i, 1);
            f[i] = smt.query(1, 0, n, 0, i);
        }
    } printf("%d\n", f[n]);
    return 0;
}