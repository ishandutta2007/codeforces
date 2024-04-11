#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    }
    return res;
}

const int N = 1e6 + 5;

int n, f[N], g[N], w[N], pwr[N], inv[N];

int main() {
    pwr[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) {
        pwr[i] = add(pwr[i - 1], pwr[i - 1]);
        inv[i] = power(pwr[i], mod - 2);
    }
    for (int T = read(); T; T--) {
        n = read();
        if (n == 1) { printf("1\n"); continue; }
        if (n == 2) { printf("0\n1\n"); continue; }
        g[n + 1] = 0;
        for (int i = n; i >= 1; i--) {
            f[i] = g[i + 1];
            if (i == n) { f[i] = add(f[i], 2); }
            if (i * 2 <= n) { f[i] = sub(f[i], g[i * 2]); }
            g[i] = add(g[i + 1], f[i]);
        }
        for (int i = 1; i <= n; i++) {
            f[i] = 1ll * f[i] * inv[n] % mod * pwr[i / 2] % mod;
            printf("%d\n", f[i]);
        }
    }
    return 0;
}