#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e6 + 5;

int n, a[N], b[N], p[N], ans[N];

struct SegmentTree {
    int f[N], g[N];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = std::max(f[ls], f[rs]) + g[u];
    }

    void modify(int u, int l, int r, int pl, int pr, int x) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { f[u] += x; g[u] += x; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
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

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read(); p[a[i]] = i;
    }
    smt.modify(1, 0, n, 0, p[n], 1);
    for (int i = 1, j = n; i <= n; i++) {
        for (; j > 1 && smt.f[1] <= 0; j--) {
            smt.modify(1, 0, n, 0, p[j - 1], 1);
        }
        ans[i] = j;
        b[i] = read();
        smt.modify(1, 0, n, 0, b[i], -1);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}