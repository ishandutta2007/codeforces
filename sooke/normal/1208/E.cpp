#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5, L = 20;

int n, m, k, lgk, a[N], o[N], f[L][N];
long long max[N], ans[N], suf[N];

void build() {
    for (int i = 1; i <= k; i++) { o[i] = log(i) / log(2) + 1e-7; }
    lgk = o[k];
    for (int i = 0; i < k; i++) { f[0][i] = a[i]; }
    for (int j = 1; j <= lgk; j++) {
        for (int i = 0; i + (1 << j) <= k; i++) {
            f[j][i] = std::max(f[j - 1][i], f[j - 1][i + (1 << j - 1)]);
        }
    }
}
int query(int l, int r) {
    if (l > r) { return -1e9; }
    int lgl = o[r - l + 1];
    return std::max(f[lgl][l], f[lgl][r - (1 << lgl) + 1]);
}

int main() {
    m = read(); n = read();
    for (int i = 0; i < m; i++) {
        k = read();
        for (int j = 0; j < k; j++) { a[j] = read(); }
        int _l, _r = -1; build();
        for (int j = 0; j < k; j++) {
            int r = std::min(j, k - 1), l = std::max(j - n + k, 0);
            max[j] = query(l, r); _l = j;
            if (j > k - 1 || j - n + k < 0) { max[j] = std::max(max[j], 0ll); }
            ans[j] += max[j];
        }
        for (int j = std::max(k, n - k); j < n; j++) {
            int r = std::min(j, k - 1), l = std::max(j - n + k, 0);
            max[j] = query(l, r); _r = _r == -1 ? j - 1 : _r;
            if (j > k - 1 || j - n + k < 0) { max[j] = std::max(max[j], 0ll); }
            ans[j] += max[j];
        }
        int x = std::max(0, query(0, k - 1));
        if (_l < _r) {
            suf[_r] += x; suf[_l] -= x;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] += suf[i + 1]; ans[i] += suf[i];
    }
    for (int i = 0; i < n; i++) { printf("%I64d ", ans[i]); }
    return 0;
}