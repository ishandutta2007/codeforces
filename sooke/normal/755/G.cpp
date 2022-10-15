#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const double eps = 1e-7;
const int mod = 998244353, gen = 3;

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

namespace Polynom {
    std::vector<int> rev, rt;

    void getRevRoot(int n) {
        int m = log(n) / log(2) + eps;
        rev.resize(n); rt.resize(n);
        for (int i = 1; i < n; i++) { rev[i] = rev[i >> 1] >> 1 | (i & 1) << m - 1; }
        for (int len = 1; len < n; len *= 2) {
            int uni = power(gen, (mod - 1) / (len * 2));
            rt[len] = 1;
            for (int i = 1; i < len; i++) { rt[i + len] = 1ll * rt[i + len - 1] * uni % mod; }
        }
    }
    void ntt(std::vector<int> &f, int n) {
        f.resize(n);
        for (int i = 0; i < n; i++) {
            if (i < rev[i]) { std::swap(f[i], f[rev[i]]); }
        }
        for (int len = 1; len < n; len *= 2) {
            for (int i = 0; i < n; i += len * 2) {
                for (int j = 0; j < len; j++) {
                    int x = f[i + j], y = 1ll * f[i + j + len] * rt[j + len] % mod;
                    f[i + j] = add(x, y); f[i + j + len] = sub(x, y);
                }
            }
        }
    }
    std::vector<int> operator *(std::vector<int> f, std::vector<int> g) {
        if (f.empty() || g.empty()) { return std::vector<int>(); }
        int n = 1, m = f.size() + g.size(); m--;
        while (n < m) { n *= 2; }
        int invn = power(n, mod - 2);
        getRevRoot(n); ntt(f, n); ntt(g, n);
        for (int i = 0; i < n; i++) { f[i] = 1ll * f[i] * g[i] % mod; }
        std::reverse(f.begin() + 1, f.end()); ntt(f, n);
        f.resize(m);
        for (int i = 0; i < m; i++) { f[i] = 1ll * f[i] * invn % mod; }
        return f;
    }
}

using Polynom::operator *;

const int N = 1e6 + 5;

int n, m, fac[N], invf[N], _fac[N], _invf[N], pwr2[N];
std::vector<int> f, g;

void initCombin(int n) { 
    fac[0] = 1;
    for (int i = 1; i <= n; i++) { fac[i] = 1ll * fac[i - 1] * i % mod; }
    invf[n] = power(fac[n], mod - 2);
    for (int i = n; i >= 1; i--) { invf[i - 1] = 1ll * invf[i] * i % mod; }
    _fac[n] = 1;
    for (int i = n - 1; i >= 0; i--) { _fac[i] = 1ll * _fac[i + 1] * std::max(1, ::n - i) % mod; }
    for (int i = 0; i <= n; i++) { _invf[i] = power(_fac[i], mod - 2); }
    pwr2[0] = 1;
    for (int i = 1; i <= n; i++) { pwr2[i] = add(pwr2[i - 1], pwr2[i - 1]); }
}

int main() {
    n = read(); m = read();
    initCombin(m + 1);
    f.resize(m + 1); g.resize(m + 1);
    for (int i = 0, now = 1; i <= m; i++) {
        f[i] = 1ll * pwr2[i] * invf[i] % mod * invf[i] % mod;
        g[i] = 1ll * _fac[i] * invf[i] % mod;
        if (i & 1) { g[i] = sub(0, g[i]); }
        if (now == 0) { break; }
    }
    f = f * g;
    for (int i = 0; i <= m; i++) { f[i] = 1ll * f[i] * fac[i] % mod * _invf[i] % mod; }
    for (int i = 1; i <= m; i++) { printf("%d ", i <= n ? f[i] : 0); }
    return 0;
}