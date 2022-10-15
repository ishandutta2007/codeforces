#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N], p[N];
long long now;

struct SegmentTree {
    long long f[N], g[N], tag[N];
    
    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = f[ls] + f[rs];
        g[u] = g[ls] + g[rs];
    }
    inline void pushTag(int u, int l, int r, long long x) {
        tag[u] += x; f[u] += x * g[u];
    }
    inline void pushDown(int u, int l, int r) {
        if (tag[u] != 0) {
            int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
            pushTag(ls, l, mid, tag[u]);
            pushTag(rs, mid, r, tag[u]);
            tag[u] = 0;
        }
    }

    void build(int u, int l, int r) {
        g[u] = 1;
        if (r - l <= 1) { return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        build(ls, l, mid); build(rs, mid, r);
        pushUp(u);
    }
    void modify(int u, int l, int r, int p) {
        if (r - l <= 1) { f[u] = g[u] = 0; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u, l, r);
        if (p < mid) {
            modify(ls, l, mid, p);
        } else {
            modify(rs, mid, r, p);
        }
        pushUp(u);
    }
    void modify(int u, int l, int r, int pl, int pr, long long x) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { pushTag(u, l, r, x); return; }
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
    void query(int u, int l, int r, int pl, int pr, long long &res) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { res += f[u]; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u, l, r);
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
    void queryg(int u, int l, int r, int pl, int pr, long long &res) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { res += r - l - g[u]; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u, l, r);
        if (pr <= mid) {
            queryg(ls, l, mid, pl, pr, res);
        } else if (pl >= mid) {
            queryg(rs, mid, r, pl, pr, res);
        } else {
            queryg(ls, l, mid, pl, mid, res);
            queryg(rs, mid, r, mid, pr, res);
        }
        pushUp(u);
    }
} smt0, smt1;

long long query(int pos) {
    long long res = 0;
    smt0.query(1, 0, n, 0, pos, res);
    smt1.query(1, 0, n, pos, n, res);
    return res;
}

int main() {
    n = read(); smt0.build(1, 0, n); smt1.build(1, 0, n);
    for (int i = 1; i <= n; i++) { a[i] = read(); p[a[i]] = i; }
    for (int i = 1; i <= n; i++) {
        int u = p[i], pos = 0; long long tmp;
        smt0.modify(1, 0, n, u - 1);
        smt1.modify(1, 0, n, u - 1);
        smt0.queryg(1, 0, n, u, n, now);
        smt0.modify(1, 0, n, u, n, 1);
        smt1.modify(1, 0, n, 0, u - 1, 1);
        for (int l = 1, r = n, mid; l <= r; ) {
            mid = l + r >> 1; tmp = 0;
            smt0.queryg(1, 0, n, 0, mid, tmp);
            if (tmp < (i + 1) / 2) {
                l = mid + 1; pos = mid;
            } else {
                r = mid - 1;
            }
        }
        pos++;
        printf("%lld ", now + query(pos));
    }
    return 0;
}