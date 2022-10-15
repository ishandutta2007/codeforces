#include <cstdio>
#include <algorithm>

const int N = 4e6 + 5;

int n, m, q, a[N], b[N];

struct SegmentTree {
    int f[N], sum[N];
    
    inline void pushUp(int u) {
        int ul, ur; sum[u] = sum[ul = u << 1] + sum[ur = u << 1 | 1];
        f[u] = std::max(f[ul] + sum[ur], f[ur]);
    }
    void modify(int u, int l, int r, int p, int x) {
        if (l == r) { sum[u] += x; f[u] += x; return; }
        int mid = l + r >> 1;
        if (p <= mid) { modify(u << 1, l, mid, p, x); }
        else { modify(u << 1 | 1, mid + 1, r, p, x); }
        pushUp(u);
    }
    int query(int u, int l, int r, int x) {
        if (l == r) { return l; }
        int mid = l + r >> 1, ur = u << 1 | 1;
        if (f[ur] + x > 0) { return query(ur, mid + 1, r, x); }
        else { return query(u << 1, l, mid, x + sum[ur]); }
    }
} smt;

int main() {
    scanf("%d%d", &n, &m); smt.modify(1, 0, 1e6, 0, 1e6);
    for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); smt.modify(1, 0, 1e6, a[i], 1); }
    for (int i = 1; i <= m; i++) { scanf("%d", &b[i]); smt.modify(1, 0, 1e6, b[i], -1); }
    for (scanf("%d", &q); q; q--) {
        int opt, u, x; scanf("%d%d%d", &opt, &u, &x);
        if (opt == 1) { smt.modify(1, 0, 1e6, a[u], -1); smt.modify(1, 0, 1e6, a[u] = x, 1); }
        else { smt.modify(1, 0, 1e6, b[u], 1); smt.modify(1, 0, 1e6, b[u] = x, -1); }
        x = smt.query(1, 0, 1e6, 0); printf("%d\n", x ? x : -1);
    }
    return 0;
}