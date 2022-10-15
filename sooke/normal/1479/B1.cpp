#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int inf = 1e9;
const int N = 1e6 + 5;

int n, m, ans, a[N];

struct SegmentTree {
    int f[N * 4], g[N * 4];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = std::max(f[ls], f[rs]);
    }
    inline void pushTag(int u, int x) {
        f[u] += x; g[u] += x;
    }
    inline void pushDown(int u) {
        int ls = u << 1, rs = ls | 1;
        if (g[u] != 0) {
            pushTag(ls, g[u]);
            pushTag(rs, g[u]);
            g[u] = 0;
        }
    }

    void modify(int u, int l, int r, int p, int x) {
        if (l + 1 >= r) { f[u] = std::max(f[u], x); return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (p < mid) {
            modify(ls, l, mid, p, x);
        } else {
            modify(rs, mid, r, p, x);
        }
        pushUp(u);
    }
    void modify(int u, int l, int r, int pl, int pr, int x) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { pushTag(u, x); return; }
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
    void query(int u, int l, int r, int pl, int pr, int &res) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { res = std::max(res, f[u]); return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (pr <= mid) {
            query(ls, l, mid, pl, pr, res);
        } else if (pl >= mid) {
            query(rs, mid, r, pl, pr, res);
        } else {
            query(ls, l, mid, pl, mid, res);
            query(rs, mid, r, mid, pr, res);
        }
        pushUp(u);
    }
} smt;

int main() {
    n = read(); m = n + 1;
    smt.modify(1, 0, m, 1, m, -n * 5);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        int x = 0;
        smt.query(1, 0, m, a[i], a[i] + 1, x);
        int y = 0;
        smt.query(1, 0, m, 0, a[i], y);
        smt.query(1, 0, m, a[i] + 1, m, y);
        y++;
        if (a[i - 1] != a[i]) {
            smt.modify(1, 0, m, 0, m, 1);
        }
        smt.modify(1, 0, m, a[i - 1], std::max(x, y));
    }
    smt.query(1, 0, m, 0, m, ans);
    printf("%d\n", ans);
    return 0;
}