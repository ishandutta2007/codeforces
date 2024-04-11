#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int mod = 998244353;

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

const int N = 2e5 + 5;

int n, ans, pwr[N], a[N];
long long pre[N], suf[N];

int main() {
    pwr[0] = 1;
    for (int i = 1; i < N; i++) {
        pwr[i] = add(pwr[i - 1], pwr[i - 1]);
    }
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 0; i <= n + 1; i++) {
            pre[i] = suf[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            a[i] = read(); pre[i] = pre[i - 1] + a[i];
        }
        for (int i = n; i >= 1; i--) {
            suf[i] = suf[i + 1] + a[i];
        }
        ans = 1;
        for (int i = 1, j = 1, l = n, r = n; i <= n; ) {
            for (; j <= n && pre[i] == pre[j]; j++);
            for (; l >= 1 && suf[l] == suf[r]; l--);
            if (pre[i] < suf[r]) {
                i = j;
            } else if (pre[i] > suf[r]) {
                r = l;
            } else {
                if (i < r) {
                    if (j <= l) {
                        ans = 1ll * ans * binom(j - i + r - l, j - i) % mod;
                    } else {
                        ans = 1ll * ans * pwr[j - i - (int) (j == n + 1)] % mod;
                    }
                }
                i = j;
                r = l;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}