#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 998244353, inv2 = mod + 1 >> 1;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}
inline int power(int x, int y, int res = 1) {
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    } return res;
}

const int N = 1e6 + 5;

int n, m, k, ans, a[N], fac[N], invf[N];

void initCombin(int n) {
    for (int i = fac[0] = 1; i <= n; i++) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
    }
    invf[n] = power(fac[n], mod - 2);
    for (int i = n; i >= 1; i--) {
        invf[i - 1] = 1ll * invf[i] * i % mod;
    }
}

int binom(int n, int m) {
    if (n < m) { return 0; }
    return 1ll * fac[n] * invf[m] % mod * invf[n - m] % mod;
}

int solve(int x) {
    if (x & 1) {
        return power(2, x - 1);
    } else {
        return 1ll * sub(power(2, x), binom(x, x / 2)) * inv2 % mod;
    }
}

int main() {
    n = read(); k = read();
    for (int i = 0; i < n; i++) { a[i] = read(); }
    for (int i = 0; i < n; i++) { m += a[i] != a[(i + 1) % n]; }
    initCombin(1e6);
    if (m == 1) {
        printf("0\n");
    } else {
        for (int i = 0; i <= m; i++) {
            ans = add(ans, 1ll * binom(m, i) * power(k - 2, m - i) % mod * solve(i) % mod);
        }
        ans = 1ll * ans * power(k, n - m) % mod;
        printf("%d\n", ans);
    }
    return 0;
}