#include <bits/stdc++.h>

const int mod = 998244353;
const int max_N = (int) 1e6 + 21;

int qpow(int x, int k) {
    x = (x + mod) % mod;
    int res = 1;
    while (k) {
        if (k & 1) {
            res = int(1ll * res * x % mod);
        }
        x = int(1ll * x * x % mod);
        k >>= 1;
    }
    return res;
}

int n, fac[max_N], _fac[max_N], inv[max_N], ans;

int C(int n, int m) {
    return int(1ll * fac[n] * _fac[m] % mod * _fac[n - m] % mod);
}

int main() {
    scanf("%d", &n);
    if (n == 1)return puts("3"), 0;
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] = int(1ll * (mod / i) * inv[mod % i] % mod);
        if (inv[i]) inv[i] = mod - inv[i];
    }
    fac[0] = _fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = int(1ll * fac[i - 1] * i % mod);
        _fac[i] = int(1ll * _fac[i - 1] * inv[i] % mod);
    }
    for (int a = n, k = 1; a; --a) {
        int tmp1 = int(3ll * C(n, a) % mod);
        int tmp2 = (qpow(k - 1, n) - qpow(k, n) + mod) % mod;
        int tmp = int(1ll * tmp1 * tmp2 % mod);
        if (a & 1) {
            ans = (ans - tmp + mod) % mod;
        } else {
            ans = (ans + tmp) % mod;
        }
        k = int(3ll * k % mod);
    }
    ans = int((ans + 2ll * qpow(qpow(3, n) - 3, n)) % mod);
    int tmp = int(2ll * qpow(qpow(3, n), n) % mod);
    ans = (ans - tmp + mod) % mod;
    if (ans) ans = mod - ans;
    printf("%d\n", ans);
    return 0;
}