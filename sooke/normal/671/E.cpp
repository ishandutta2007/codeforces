#include <bits/stdc++.h>
 
inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}
 
const int N = 1e6 + 5;
 
int n, k, ans, w[N], g[N], vol, stc[N];
long long gr[N], gl[N];
 
struct SegmentTree {
    long long f[N], g[N], tag[N], tmax[N];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = std::min(f[ls], f[rs]);
        g[u] = std::min(g[ls], g[rs]);
    }
    inline void pushTag(int u, long long x, long long y) {
        g[u] = std::max(g[u], f[u] + y); f[u] += x;
        tmax[u] = std::max(tmax[u], tag[u] + y); tag[u] += x;
    }
    inline void pushDown(int u) {
        int ls = u << 1, rs = ls | 1;
        pushTag(ls, tag[u], tmax[u]);
        pushTag(rs, tag[u], tmax[u]);
        tag[u] = tmax[u] = 0;
    }

    void build(int u, int l, int r) {
        if (l + 1 >= r) { f[u] = g[u] = gl[l + 1]; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        build(ls, l, mid); build(rs, mid, r);
        pushUp(u);
    }
    void modify(int u, int l, int r, int pl, int pr, long long x) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { pushTag(u, x, x); return; }
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
    void query(int u, int l, int r, int pl, int pr, long long x, int &p) {
        if (pl >= pr || p != -1) { return; }
        if (l == pl && r == pr) {
            if (g[u] > x) { return; }
            if (l + 1 >= r) { p = l; return; }
        }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (pr <= mid) {
            query(ls, l, mid, pl, pr, x, p);
        } else if (pl >= mid) {
            query(rs, mid, r, pl, pr, x, p);
        } else {
            query(ls, l, mid, pl, mid, x, p);
            query(rs, mid, r, mid, pr, x, p);
        }
        pushUp(u);
    }
} smt;

int main() {
    n = read(); k = read();
    for (int i = 1; i < n; i++) { w[i] = read(); }
    for (int i = 1; i <= n; i++) { g[i] = read(); }
    for (int i = 2; i <= n; i++) {
        gr[i] = gr[i - 1] + w[i - 1] - g[i - 1];
    }
    for (int i = n - 1; i >= 1; i--) {
        gl[i] = gl[i + 1] + w[i] - g[i + 1];
    }
    smt.build(1, 0, n); ans = 1;
    for (int i = 1; i <= n; i++) {
        for (; vol > 0 && gr[stc[vol]] <= gr[i]; vol--) {
            smt.modify(1, 0, n, stc[vol - 1], stc[vol], gr[i] - gr[stc[vol]]);
        }
        stc[++vol] = i;
        smt.modify(1, 0, n, 0, i - 1, gl[i] - gl[i - 1]);
        int p = -1;
        smt.query(1, 0, n, 0, i, k + gl[i], p);
        ans = std::max(ans, i - p);
    }
    printf("%d\n", ans);
    return 0;
}