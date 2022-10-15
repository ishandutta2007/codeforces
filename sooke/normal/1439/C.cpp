#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, q, a[N];

struct SegmentTree {
    long long f[N], g[N], max[N], min[N];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = f[ls] + f[rs];
        max[u] = std::max(max[ls], max[rs]);
        min[u] = std::min(min[ls], min[rs]);
    }
    inline void pushTag(int u, int l, int r, long long x) {
        f[u] = x * (r - l);
        g[u] = x; max[u] = x; min[u] = x;
    }
    inline void pushDown(int u, int l, int r) {
        if (g[u] != 0) {
            int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
            pushTag(ls, l, mid, g[u]);
            pushTag(rs, mid, r, g[u]);
            g[u] = 0;
        }
    }

    void modify(int u, int l, int r, int pl, int pr, int x) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) {
            if (min[u] >= x) { return; }
            if (max[u] <= x) { pushTag(u, l, r, x); return; }
        }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u, l, r);
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
    void query(int u, int l, int r, int p, long long &res) {
        if (l + 1 >= r) { res += p == n ? f[u] : 0; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u, l, r);
        if (p < mid) {
            query(ls, l, mid, p, res);
        } else {
            res += f[ls];
            query(rs, mid, r, p, res);
        }
        pushUp(u);
    }
    void find(int u, int l, int r, long long x, int &p) {
        if (l + 1 >= r) { p = l; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u, l, r);
        if (x < f[ls]) {
            find(ls, l, mid, x, p);
        } else {
            find(rs, mid, r, x - f[ls], p);
        }
        pushUp(u);
    }
    void go(int u, int l, int r, int pl, int pr, long long x, int &p) {
        if (pl >= pr) { p = -1; return; }
        if (l == pl && r == pr) {
            if (min[u] > x) { p = -1; return; }
        }
        if (l + 1 >= r) { p = l; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u, l, r);
        if (l == pl && r == pr) {
            if (min[ls] <= x) {
                go(ls, l, mid, pl, mid, x, p);
            } else {
                go(rs, mid, r, mid, pr, x, p);
            }
        } else if (pr <= mid) {
            go(ls, l, mid, pl, pr, x, p);
        } else if (pl >= mid) {
            go(rs, mid, r, pl, pr, x, p);
        } else {
            go(ls, l, mid, pl, mid, x, p);
            if (p != -1) { return; }
            go(rs, mid, r, mid, pr, x, p);
        }
        pushUp(u);
    }
} smt;

int solve(int p, long long x) {
    int res = 0;
    while (true) {
        long long y = 0, all = 0;
        smt.query(1, 0, n, p, y);
        int i;
        smt.query(1, 0, n, n, all);
        if (all <= x + y) {
            long long test = 0;
            smt.query(1, 0, n, n - 1, test);
            i = n;
        } else {
            smt.find(1, 0, n, x + y, i);
        }
        res += i - p;
        long long z = 0;
        smt.query(1, 0, n, i, z);
        x -= z - y; p = -1;
        smt.go(1, 0, n, i, n, x, p);
        if (p == -1) { break; }
    }
    return res;
}

int main() {
    n = read(); q = read();
    for (int i = 0; i < n; i++) {
        a[i] = read();
        smt.modify(1, 0, n, i, i + 1, a[i]);
    }
    for (int i = 0; i < q; i++) {
        int opt = read();
        if (opt == 1) {
            int p = read(), x = read();
            smt.modify(1, 0, n, 0, p, x);
        } else {
            int p = read(), x = read(); p--;
            printf("%d\n", solve(p, x));
        }
    }
    return 0;
}