#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;
const long long W = 1e17;

int n, p, q, a[N];
long long ans, suf[N];

inline long long getSum(int l, int r) {
    return suf[l] - suf[r];
}

struct SegmentTree {
    std::vector<long long> f[N << 2];
    
    void build(int u, int l, int r) {
        if (l + 1 >= r) {
            f[u].push_back(-W); f[u].push_back(p - a[l]);
            return;
        }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        build(ls, l, mid); build(rs, mid, r);
        long long xl, xr, yl, yr;
        f[u].assign(f[ls].size() + f[rs].size() - 1, W);
        f[rs][0] = -W * 10;
        for (int i = 0, j = 0; i < f[ls].size(); i++) {
            xl = f[ls][i];
            xr = i < f[ls].size() - 1 ? f[ls][i + 1] - 1 : W;
            yl = getSum(l, mid) + xl - 1ll * p * i;
            yr = getSum(l, mid) + xr - 1ll * p * i;
            for (; yl < f[rs][j]; j--);
            for (; j < f[rs].size() && yl >= f[rs][j]; j++); j--;
            for (; j < f[rs].size() && yr >= f[rs][j]; j++) {
                f[u][i + j] = std::min(f[u][i + j], std::max(xl, f[rs][j] - (getSum(l, mid) - 1ll * p * i)));
            }
        }
        f[rs][0] = f[u][0] = -W;
    }
    void query(int u, int l, int r, int pl, int pr, long long &res) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) {
            res += getSum(l, r) - 1ll * p * (std::upper_bound(f[u].begin(), f[u].end(), res) - f[u].begin() - 1);
            return;
        }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        if (pr <= mid) {
            query(ls, l, mid, pl, pr, res);
        } else if (pl >= mid) {
            query(rs, mid, r, pl, pr, res);
        } else {
            query(ls, l, mid, pl, mid, res);
            query(rs, mid, r, mid, pr, res);
        }
    }
} smt;

int main() {
    n = read(); q = read(); p = read();
    for (int i = 0; i < n; i++) { a[i] = suf[i] = read(); }
    for (int i = n; i > 0; i--) { suf[i - 1] += suf[i]; }
    smt.build(1, 0, n);
    for (int i = 0; i < q; i++) {
        int l = read(), r = read(); l--;
        smt.query(1, 0, n, l, r, ans = 0);
        printf("%lld\n", ans);
    }
    return 0;
}