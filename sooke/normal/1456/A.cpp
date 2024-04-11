#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, p, k, x, y;
long long ans, f[N];
char s[N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); p = read(); k = read();
        scanf("%s", s + 1);
        x = read(); y = read();
        ans = 1e18;
        for (int i = n; i >= 1; i--) {
            f[i] = s[i] == '1' ? 0 : x;
            if (i + k <= n) { f[i] += f[i + k]; }
            if (i >= p) { ans = std::min(ans, f[i] + 1ll * y * (i - p)); }
        }
        printf("%lld\n", ans);
    }
    return 0;
}