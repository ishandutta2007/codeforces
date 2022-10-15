#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 20, M = 5e5 + 5, A = 1 << N;

int n, m, all, a[M], cnt[N];
long long w[N][N], f[A];

int main() {
    n = 20; m = read(); all = 1 << n;
    for (int i = 0; i < m; i++) {
        a[i] = read(); a[i]--; cnt[a[i]]++;
        for (int j = 0; j < n; j++) {
            w[j][a[i]] += cnt[j];
        }
    }
    for (int i = 1, j; i < all; i++) {
        f[i] = 1e18;
        for (int u = 0; u < n; u++) {
            if (1 << u & i) {
                j = 1 << u ^ i;
                long long sum = 0;
                for (int v = 0; v < n; v++) {
                    if (1 << v & j) { sum += w[u][v]; }
                } f[i] = std::min(f[i], f[j] + sum);
            }
        }
    }
    printf("%I64d\n", f[all - 1]);
    return 0;
}