#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

int n, m, x, y, c;
long long ans;

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read(); ans = 0;
        x = m / n; y = m % n;
        for (int i = y; i < n; i++) { ans += 1ll * x * x; }
        for (int i = 0; i < y; i++) { ans += 1ll * (x + 1) * (x + 1); }
        printf("%I64d\n", ans);
    }
    return 0;
}