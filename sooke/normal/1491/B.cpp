#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, u, v, ans, a[N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); u = read(); v = read();
        for (int i = 1; i <= n; i++) {
            a[i] = read();
        }
        ans = v + std::min(u, v);
        for (int i = 2; i <= n; i++) {
            if (std::abs(a[i - 1] - a[i]) >= 2) {
                ans = 0;
            } else if (std::abs(a[i - 1] - a[i]) >= 1) {
                ans = std::min(ans, std::min(u, v));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}