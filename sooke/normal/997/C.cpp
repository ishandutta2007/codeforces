#include <cstdio>

const int maxN = 1000005, p = 998244353;

int n, ans, fac[maxN], inv[maxN];

inline int power(int x, long long y) { int res = 1; for (; y; y >>= 1, x = (long long) x * x % p) { if (y & 1) { res = (long long) res * x % p; } } return res; }
inline int binomial(int x, int y) { return (long long) fac[x] * inv[y] % p * inv[x - y] % p; }
inline long long sign(int x) { return x & 1 ? -1 : 1; }

int main() {
    scanf("%d", &n);
    for (int i = fac[0] = 1; i <= n; i++) { fac[i] = (long long) fac[i - 1] * i % p; }
    inv[n] = power(fac[n], p - 2);
    for (int i = n; i; i--) { inv[i - 1] = (long long) inv[i] * i % p; }
    for (int i = 1; i <= n; i++) { ans = (ans + sign(i) * binomial(n, i) * power(3, (long long) n * (n - i) + i) * 2) % p; }
    for (int i = 0; i < n; i++) { ans = (ans + sign(n - i) * binomial(n, i) * (power(power(3, i) - 1, n) - power(3, (long long) n * i)) * 3) % p; }
    printf("%d\n", (p - ans) % p);
    return 0;
}