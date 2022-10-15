#include <bits/stdc++.h>

inline long long read() {
    char c, _c; long long x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int mod = 1e9 + 7, inv2 = mod + 1 >> 1;

inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int sub(int x, int y) { return x - y >= 0 ? x - y : x - y + mod; }
inline int power(int x, int y, int res = 1) {
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    } return res;
}

const int N = 2e5 + 5;

int n, k, ans, now = 1, tot = 1, fac[N], invf[N];
long long m;

void initCombin(int n) {
    for (int i = fac[0] = 1; i <= n; i++) { fac[i] = 1ll * fac[i - 1] * i % mod; }
    invf[n] = power(fac[n], mod - 2);
    for (int i = n; i; i--) { invf[i - 1] = 1ll * invf[i] * i % mod; }
}
int binom(int n, int m) { return n < m ? 0 : 1ll * fac[n] * invf[m] % mod * invf[n - m] % mod; }

int main() {
    n = read(); m = read(); initCombin(k = n);
    for (int i = 0; i < n; i++) {
        m -= read();
        if (m < 0) { break; }
        for (; k > m; k--) { now = sub(now, binom(i, k)); }
        now = sub(add(now, now), binom(i, k));
        tot = 1ll * tot * inv2 % mod;
        ans = add(ans, 1ll * tot * now % mod);
    }
    printf("%d\n", ans);
    return 0;
}