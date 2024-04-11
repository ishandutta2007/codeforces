#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5, L = 20;

int _n, n, lgn, a[N], ans[N], e[N], o[N], f[L][N], g[L][N];

void build() {
    for (int i = 1; i <= n; i++) { o[i] = log(i) / log(2) + 1e-7; }
    lgn = o[n];
    for (int i = 0; i < n; i++) { f[0][i] = g[0][i] = a[i]; }
    for (int i = 1; i <= lgn; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            f[i][j] = std::min(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
            g[i][j] = std::max(g[i - 1][j], g[i - 1][j + (1 << i - 1)]);
        }
    }
}

inline int queryf(int l, int r) {
    int lgl = o[r - l + 1];
    return std::min(f[lgl][l], f[lgl][r - (1 << lgl) + 1]);
}
inline int queryg(int l, int r) {
    int lgl = o[r - l + 1];
    return std::max(g[lgl][l], g[lgl][r - (1 << lgl) + 1]);
}

int main() {
    _n = read(); n = _n * 4;
    for (int i = 0; i < _n; i++) { a[i] = a[_n + i] = a[_n * 2 + i] = a[_n * 3 + i] = read(); }
    build();
    for (int i = 0; i < n; i++) {
        int resf, resg;
        resf = 1e9;
        for (int l = i + 1, r = n - 1, mid; l <= r; ) {
            mid = l + r >> 1;
            if (queryf(i + 1, mid) * 2 < a[i]) {
                r = mid - 1; resf = mid;
            } else {
                l = mid + 1;
            }
        }
        resg = 1e9;
        for (int l = i + 1, r = n - 1, mid; l <= r; ) {
            mid = l + r >> 1;
            if (queryg(i + 1, mid) > a[i]) {
                r = mid - 1; resg = mid;
            } else {
                l = mid + 1;
            }
        }
        e[i] = std::min(resf, resg);
    }
    for (int i = 0; i < n; i++) { ans[i] = 1e9; }
    for (int i = n - 1; i >= 0; i--) {
        if (e[i] != 1e9) {
            if (a[e[i]] < a[i]) {
                ans[i] = std::min(ans[i], e[i] - i);
            } else {
                ans[i] = std::min(ans[i], ans[e[i]] + e[i] - i);
            }
        }
    }
    for (int i = 0; i < _n; i++) { printf("%d ", ans[i] == 1e9 ? -1 : ans[i]); }
    return 0;
}