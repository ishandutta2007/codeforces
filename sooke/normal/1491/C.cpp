#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 5e3 + 5;

int n, p, a[N], nxt[N], anc[N];
long long ans, d[N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); ans = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = read(); anc[i] = i; nxt[i] = i; d[i] = 0;
        }
        anc[n + 1] = n + 1; nxt[n + 1] = n + 1;
        for (int i = 1; i <= n; i++) {
            ans += std::max(0ll, a[i] - d[i] - 1);
            for (int j = i + 2; j <= n && j <= i + a[i]; j++) {
                d[j]++;
            }
            if (a[i] < d[i] + 1) {
                d[i + 1] += std::abs(a[i] - d[i]) + 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}