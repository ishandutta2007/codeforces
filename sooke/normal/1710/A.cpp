#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, m, k, p, q, c, d, a[N];
long long x, y;

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read(); k = read(); x = y = c = d = 0;
        for (int i = 0; i < k; i++) {
            a[i] = read();
            p = a[i] / n; q = a[i] / m;
            if (p == 1) { p = 0; }
            if (q == 1) { q = 0; }
            if (p > 2) { c = 1; }
            if (q > 2) { d = 1; }
            x += p; y += q;
        }
        bool ans = false;
        if (c) {
            ans |= x >= m;
        } else {
            ans |= x >= m && x % 2 == m % 2;
        }
        if (d) {
            ans |= y >= n;
        } else {
            ans |= y >= n && y % 2 == n % 2;
        }
        printf("%s\n", ans ? "Yes" : "No");
    }
    return 0;
}