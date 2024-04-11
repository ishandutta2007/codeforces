#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 4e6 + 5;

long long ans, ansl = 2e9, ansr = 2e9;
int n, num, a[N], b[N], tb[N], val[N];
std::vector<std::pair<int, int>> rb[N];

struct SegmentTree {
    std::pair<long long, int> f[N];
    long long tag[N];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = std::max(f[ls], f[rs]);
    }
    inline void pushTag(int u, long long x) {
        f[u].first += x; tag[u] += x;
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
            f[u] = {0, l}; return;
        } int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        build(ls, l, mid); build(rs, mid, r);
        pushUp(u);
    }
    void modify(int u, int l, int r, int pl, int pr, int x) {
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
    void query(int u, int l, int r, int pl, int pr, std::pair<long long, int> &res) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) {
            res = std::max(res, f[u]); return;
        } int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (pr <= mid) {
            query(ls, l, mid, pl, pr, res);
        } else if (pl >= mid) {
            query(rs, mid, r, pl, pr, res);
        } else {
            query(ls, l, mid, pl, mid, res);
            query(rs, mid, r, mid, pr, res);
        } pushUp(u);
    }
} smt;

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); b[i] = read(); val[i] = read();
        if (a[i] > b[i]) { std::swap(a[i], b[i]); }
        tb[num++] = a[i]; tb[num++] = b[i];
    } std::sort(tb, tb + num); num = std::unique(tb, tb + num) - tb;
    for (int i = 0; i < n; i++) {
        a[i] = std::lower_bound(tb, tb + num, a[i]) - tb;
        b[i] = std::lower_bound(tb, tb + num, b[i]) - tb;
        rb[a[i]].push_back({b[i], val[i]});
    } smt.build(1, 0, num);
    for (int l = num - 1; l >= 0; l--) {
        for (auto _rb : rb[l]) {
            int r = _rb.first, w = _rb.second;
            smt.modify(1, 0, num, r, num, w);
        } smt.modify(1, 0, num, l + 1, num, tb[l] - tb[l + 1]);
        std::pair<long long, int> res = {-1e18, 0};
        smt.query(1, 0, num, l, num, res);
        if (ans < res.first) {
            ans = res.first; ansl = tb[l]; ansr = tb[res.second];
        }
    } printf("%I64d\n%I64d %I64d %I64d %I64d\n", ans, ansl, ansl, ansr, ansr);
    return 0;
}