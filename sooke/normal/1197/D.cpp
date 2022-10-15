#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, m, k, a[N];
long long ans, min, b[N];

int main() {
    n = read(); m = read(); k = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    for (int x = 0; x < m; x++) {
        min = 1e18;
        for (int i = 0; i <= n; i++) {
            if (i) { b[i] = b[i - 1]; }
            else { b[i] = 0; }
            b[i] += a[i];
            if (i % m == x) {
                b[i] -= k;
                ans = std::max(ans, b[i] - min);
            }
            min = std::min(min, b[i]);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}