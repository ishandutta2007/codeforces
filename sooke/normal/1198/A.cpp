#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const double eps = 1e-7;

const int N = 1e6 + 5;

int n, m, k, num, ans = 1e9, a[N], b[N], pre[N], suf[N];

inline int getPre(int u) { return u >= 0 ? pre[u] : 0; }
inline int getSuf(int u) { return u < num ? suf[u] : 0; }

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        if ((int) ceil(log(i) / log(2) - eps) * n <= m * 8) {
            k = i;
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = read();
    }
    std::sort(b, b + n);
    num = std::unique(b, b + n) - b;
    for (int i = 0; i < n; i++) {
        int x = std::lower_bound(b, b + num, a[i]) - b;
        pre[x]++; suf[x]++;
    }
    for (int i = 1; i < num; i++) { pre[i] += pre[i - 1]; }
    for (int i = num - 2; i >= 0; i--) { suf[i] += suf[i + 1]; }
    for (int i = 0; i < num; i++) {
        ans = std::min(ans, getPre(i - 1) + getSuf(i + k));
    }
    printf("%d\n", ans);
    return 0;
}