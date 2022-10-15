#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

const int maxN = 1000005, p = 998244353;

int n, fac[maxN], inv[maxN];
long long ans;

inline int power(int x, int y) { int res = 1; for (; y; y >>= 1, x = 1ll * x * x % p) { if (y & 1) { res = 1ll * res * x % p; } } return res; }

int main() {
    std::cin >> n;
    for (int i = fac[0] = 1; i <= n; i++) { fac[i] = 1ll * fac[i - 1] * i % p; }
    inv[n] = power(fac[n], p - 2);
    for (int i = n; i; i--) { inv[i - 1] = 1ll * inv[i] * i % p; }
    for (int i = 1; i <= n; i++) { ans = (ans + 1ll * fac[n] * inv[i] % p * (fac[i] + p - 1)) % p; }
    std::cout << (ans + 1) % p;
    return 0;
} //