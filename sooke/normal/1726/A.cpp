#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, ans, a[N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); ans = 0;
        for (int i = 0; i < n; i++) {
            a[i] = read();
        }
        for (int i = 0; i < n; i++) {
            ans = std::max(ans, a[i] - a[(i + 1) % n]);
            ans = std::max(ans, a[i] - a[0]);
            ans = std::max(ans, a[n - 1] - a[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}