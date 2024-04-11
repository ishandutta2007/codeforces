#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

namespace Combin {
    std::vector<int> inv, fac, invf;

    void getInvFac(int n) {
        if (inv.empty()) { inv = fac = invf = std::vector<int> (2, 1); }
        int m = inv.size(); n++;
        if (m < n) {
            inv.resize(n); fac.resize(n); invf.resize(n);
            for (int i = m; i < n; i++) {
                inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
                fac[i] = 1ll * fac[i - 1] * i % mod;
                invf[i] = 1ll * invf[i - 1] * inv[i] % mod;
            }
        }
    }
    inline int binom(int n, int m) {
        if (n < m || m < 0) { return 0; }
        getInvFac(n);
        return 1ll * fac[n] * invf[m] % mod * invf[n - m] % mod; 
    }
}

using namespace Combin;

int n, ans;

int main() {
    n = read();
    for (int i = 0; i <= n; i++) {
        int x = read();
        ans += binom(i + x, i + 1);
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}