#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e6 + 5;

int n, q, a[N], b[N], ans[N];
std::vector<std::pair<int, int>> qry[N];

struct SegmentTree {
    int g[N], f[N], fi[N];

    inline void pushUp(int u) {
        f[u] = 1e9;
        int ls = u << 1, rs = ls | 1;
        if (f[u] > f[ls]) {
            f[u] = f[ls]; fi[u] = fi[ls];
        }
        if (f[u] > f[rs]) {
            f[u] = f[rs]; fi[u] = fi[rs];
        }
    }
    inline void pushTag(int u, int x) {
        f[u] += x; g[u] += x;
    }
    inline void pushDown(int u) {
        if (g[u] != 0) {
            int ls = u << 1, rs = ls | 1;
            pushTag(ls, g[u]); pushTag(rs, g[u]);
            g[u] = 0;
        }
    }

    void modify(int u, int l, int r, int p, int x) {
        if (l + 1 >= r) { f[u] = x; fi[u] = l; return; }
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
} smt;

struct FenwickTree {
    int f[N];

    void modify(int u, int x) {
        for (int i = u; i <= n; i += i & -i) { f[i] += x; }
    }
    int query(int u) {
        int res = 0;
        for (int i = u; i >= 1; i ^= i & -i) { res += f[i]; }
        return res;
    }
} tr;

int main() {
    n = read(); q = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); a[i]--;
        b[i] = i - a[i];
        smt.modify(1, 0, n, i, 1e9);
    }
    for (int i = 0; i < q; i++) {
        int l = read(), r = read();
        r = n - r;
        qry[l].push_back({r, i});
    }
    for (int i = n - 1; i >= 0; i--) {
        if (b[i] >= 0) { smt.modify(1, 0, n, i, b[i]); }
        while (smt.f[1] <= 0) {
            int u = smt.fi[1];
            smt.modify(1, 0, n, u, 1e9);
            smt.modify(1, 0, n, u, n, -1);
            tr.modify(u + 1, 1);
        }
        for (auto t : qry[i]) {
            ans[t.second] = tr.query(t.first);
        }
    }
    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}