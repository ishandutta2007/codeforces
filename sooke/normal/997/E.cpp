#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e6 + 5;

int n, q, a[N], vmax, smax[N], bmax[N], vmin, smin[N], bmin[N];
std::vector<std::pair<int, int>> qry[N];
long long ans[N];

struct SegmentTree {
    int f[N], g[N], tag[N], upd[N];
    long long sumg[N];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = std::min(f[ls], f[rs]); g[u] = 0;
        if (f[u] == f[ls]) { g[u] += g[ls]; }
        if (f[u] == f[rs]) { g[u] += g[rs]; }
        sumg[u] = sumg[ls] + sumg[rs];
    }
    inline void pushTag(int u, int x) {
        f[u] += x; tag[u] += x;
    }
    inline void pushUpd(int u, int x) {
        sumg[u] += 1ll * g[u] * x; upd[u] += x;
    }
    inline void pushDown(int u) {
        int ls = u << 1, rs = ls | 1;
        if (tag[u] != 0) {
            pushTag(ls, tag[u]); pushTag(rs, tag[u]);
            tag[u] = 0;
        }
        if (upd[u] != 0) {
            if (f[u] == f[ls]) { pushUpd(ls, upd[u]); }
            if (f[u] == f[rs]) { pushUpd(rs, upd[u]); }
            upd[u] = 0;
        }
    }

    void modify(int u, int l, int r, int p) {
        if (l + 1 >= r) { f[u] = p; g[u] = 1; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (p < mid) {
            modify(ls, l, mid, p);
        } else {
            modify(rs, mid, r, p);
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
    void update(int u, int l, int r, int pl, int pr, int x) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) {
            if (f[u] == x) { pushUpd(u, 1); }
            return;
        }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (pr <= mid) {
            update(ls, l, mid, pl, pr, x);
        } else if (pl >= mid) {
            update(rs, mid, r, pl, pr, x);
        } else {
            update(ls, l, mid, pl, mid, x);
            update(rs, mid, r, mid, pr, x);
        }
        pushUp(u);
    }
    void query(int u, int l, int r, int pl, int pr, long long &res) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { res += sumg[u]; return; }
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
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); a[i]--;
    }
    q = read();
    for (int i = 0; i < q; i++) {
        int l = read(), r = read(); l--; r--;
        qry[r].push_back({l, i});
    }
    smax[0] = 1e9; smin[0] = -1e9;
    for (int i = 0, j; i < n; i++) {
        j = i;
        for (; smax[vmax] < a[i]; vmax--) {
            smt.modify(1, 0, n, bmax[vmax], j, -smax[vmax]);
            j = bmax[vmax];
        }
        smt.modify(1, 0, n, j, i, a[i]);
        smax[++vmax] = a[i]; bmax[vmax] = j;
        j = i;
        for (; smin[vmin] > a[i]; vmin--) {
            smt.modify(1, 0, n, bmin[vmin], j, smin[vmin]);
            j = bmin[vmin];
        }
        smt.modify(1, 0, n, j, i, -a[i]);
        smin[++vmin] = a[i]; bmin[vmin] = j;
        smt.modify(1, 0, n, i);
        smt.update(1, 0, n, 0, i + 1, i);
        for (auto t : qry[i]) {
            smt.query(1, 0, n, t.first, i + 1, ans[t.second]);
        }
    }
    for (int i = 0; i < q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}