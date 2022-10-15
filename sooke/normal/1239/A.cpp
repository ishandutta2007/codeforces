#include <bits/stdc++.h>

const int mod = 1e9 + 7;

inline int power(int x, int y, int res = 1) {
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    } return res;
}

const int N = 1e6 + 5;

int n, m, ans, f[N];

int solve(int n, int m) {
    f[0] = 1; f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    return (f[n] + f[n]) % mod;
}

int main() {
    std::cin >> n >> m;
    ans = (ans + solve(n, m)) % mod;
    ans = (ans + solve(m, n)) % mod;
    ans = (ans + mod - 2) % mod;
    std::cout << ans << std::endl;
    return 0;
}