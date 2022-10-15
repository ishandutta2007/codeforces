#include <bits/stdc++.h>

const int mod = 1e9 + 7;

inline int power(int x, long long y, int res = 1) {
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    } return res;
}

long long ans = 1, m, n;

long long solve(int x) {
    long long res = 0;
    for (long long i = x; ; i *= x) {
        res += n / i;
        if (n / i / x == 0) { break; }
    } return power(x, res);
}

int main() {
    std::cin >> m >> n;
    for (int i = 2; 1ll * i * i <= m; i++) {
        if (m % i == 0) {
            ans = 1ll * ans * solve(i) % mod;
            while (m % i == 0) { m /= i; }
        }
    }
    if (m > 1) { ans = 1ll * ans * solve(m) % mod; }
    std::cout << ans << std::endl;
    return 0;
}