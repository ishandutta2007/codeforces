#include <bits/stdc++.h>

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

const int N = 2e5 + 5, M = 2e3 + 5;

int n, m, p, q, t, w[M], ws[M], f[M][M], g[M], h[M];
int fac[N], invf[N], pwr[N], qwr[N];

void init(int n) {
    fac[0] = pwr[0] = qwr[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
        pwr[i] = 1ll * pwr[i - 1] * p % mod;
        qwr[i] = 1ll * qwr[i - 1] * q % mod;
    }
    invf[n] = power(fac[n], mod - 2);
    for (int i = n; i >= 1; i--) {
        invf[i - 1] = 1ll * invf[i] * i % mod;
    }
}

int binom(int n, int m) {
    if (n < m || m < 0) { return 0; }
    return 1ll * fac[n] * invf[m] % mod * invf[n - m] % mod;
}

int main() {
    scanf("%d%d%d%d%d", &n, &m, &p, &q, &t);
    p = 1ll * p * power(q, mod - 2) % mod;
    q = sub(1, p);
    init(2e5);
    for (int i = 0; i <= m; i++) {
        w[i] = 1ll * pwr[i] * qwr[t - i] % mod * binom(t, i) % mod;
    }
    for (int r = 1; r <= m; r++) {
        ws[r] = ws[r - 1];
        for (int l = 1; l <= r; l++) {
            ws[r] = add(ws[r], 1ll * w[m - r] * w[l - 1] % mod);
        }
        f[1][r] = ws[r];
    }
    for (int i = 2; i <= n; i++) {
        int x = 0, y = 0;
        for (int l = 1; l <= m; l++) {
            g[l] = add(g[l - 1], 1ll * w[l - 1] * f[i - 1][l - 1] % mod);
            h[l] = add(h[l - 1], w[l - 1]);
        }
        for (int r = 1; r <= m; r++) {
            f[i][r] = 1ll * f[i - 1][m] * ws[r] % mod;
            x = add(x, 1ll * w[m - r] * g[r] % mod);
            f[i][r] = sub(f[i][r], x);
            y = add(y, 1ll * w[m - r] * f[i - 1][m - r] % mod * h[r] % mod);
            f[i][r] = sub(f[i][r], y);
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}