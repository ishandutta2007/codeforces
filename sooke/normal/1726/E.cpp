#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const double eps = 1e-8;
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

namespace Combin {
    std::vector<int> inv, fac, invf, pwr;

    void getInvFac(int n) {
        if (inv.empty()) { inv = fac = invf = std::vector<int> (2, 1); pwr.push_back(1); pwr.push_back(2); }
        int m = inv.size(); n++;
        if (m < n) {
            inv.resize(n); fac.resize(n); invf.resize(n); pwr.resize(n);
            for (int i = m; i < n; i++) {
                inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
                fac[i] = 1ll * fac[i - 1] * i % mod;
                invf[i] = 1ll * invf[i - 1] * inv[i] % mod;
                pwr[i] = 1ll * pwr[i - 1] * pwr[1] % mod;
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

namespace Polynom {
    std::vector<int> rev, rt, gu, gv, hv;

    void getRevRoot(int n) {
        int m = log(n) / log(2) + eps;
        rev.resize(n);
        for (int i = 1; i < n; i++) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << m - 1;
        }
        static int len = 1;
        if (len < n) {
            rt.resize(n);
            for (; len < n; len *= 2) {
                int uni = power(gen, (mod - 1) / (len * 2));
                rt[len] = 1;
                for (int i = 1; i < len; i++) {
                    rt[i + len] = 1ll * rt[i + len - 1] * uni % mod;
                }
            }
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
        int n = 1, n0 = f.size(), n1 = g.size(), m = n0 + n1 - 1;
        if (n0 <= 32 && n1 <= 32) {
            std::vector<unsigned long long> h0(m), h1(m), h2(m), h3(m);
            for (int i = 0; i < n0; i++) {
                for (int j = 0; j < n1; j += 4) {
                    h0[i + j] += 1ll * f[i] * g[j];
                    if (j + 1 < n1) { h1[i + j + 1] += 1ll * f[i] * g[j + 1]; }
                    if (j + 2 < n1) { h2[i + j + 2] += 1ll * f[i] * g[j + 2]; }
                    if (j + 3 < n1) { h3[i + j + 3] += 1ll * f[i] * g[j + 3]; }
                }
            }
            std::vector<int> h(m);
            for (int i = 0; i < m; i++) {
                h[i] = (h0[i] % mod + h1[i] % mod + h2[i] % mod + h3[i] % mod) % mod;
            }
            return h;
        }
        while (n < m) { n *= 2; }
        int invn = power(n, mod - 2);
        getRevRoot(n); ntt(f, n); ntt(g, n);
        for (int i = 0; i < n; i++) { f[i] = 1ll * f[i] * g[i] % mod; }
        std::reverse(f.begin() + 1, f.end()); ntt(f, n); f.resize(m);
        for (int i = 0; i < m; i++) { f[i] = 1ll * f[i] * invn % mod; }
        return f;
    }

    std::vector<int> polyInv(std::vector<int> f, int n) {
        f.resize(n);
        if (n <= 64) {
            std::vector<int> h(n);
            h[0] = power(f[0], mod - 2);
            for (int i = 1; i < n; i++) {
                unsigned long long g0 = 0, g1 = 0, g2 = 0, g3 = 0;
                for (int j = 0; j < i; j += 8) {
                    g0 = (g0 + 1ll * h[j] * f[i - j]) % mod;
                    if (j + 1 < i) { g1 += 1ll * h[j + 1] * f[i - j - 1]; }
                    if (j + 2 < i) { g2 += 1ll * h[j + 2] * f[i - j - 2]; }
                    if (j + 3 < i) { g3 += 1ll * h[j + 3] * f[i - j - 3]; }
                    if (j + 4 < i) { g0 += 1ll * h[j + 4] * f[i - j - 4]; }
                    if (j + 5 < i) { g1 += 1ll * h[j + 5] * f[i - j - 5]; }
                    if (j + 6 < i) { g2 += 1ll * h[j + 6] * f[i - j - 6]; }
                    if (j + 7 < i) { g3 += 1ll * h[j + 7] * f[i - j - 7]; }
                }
                h[i] = (g0 % mod + g1 % mod + g2 % mod + g3 % mod) * (mod - h[0]) % mod;
            }
            return h;
        }
        std::vector<int> g = polyInv(f, n / 2), h(n);
        g.resize(n);
        for (int i = 0; i < n / 2; i++) { h[i] = g[i]; }
        int invn = power(n, mod - 2);
        getRevRoot(n); ntt(f, n); ntt(g, n);
        for (int i = 0; i < n; i++) { f[i] = 1ll * f[i] * g[i] % mod; }
        std::reverse(f.begin() + 1, f.end()); ntt(f, n);
        for (int i = 1; i < n / 2; i++) { f[i] = 0; }
        for (int i = n / 2; i < n; i++) { f[i] = 1ll * f[i] * invn % mod; }
        f[0] = 1; ntt(f, n);
        for (int i = 0; i < n; i++) { f[i] = 1ll * f[i] * g[i] % mod; }
        std::reverse(f.begin() + 1, f.end()); ntt(f, n);
        for (int i = n / 2; i < n; i++) { h[i] = sub(0, 1ll * f[i] * invn % mod); }
        return h;
    }
    std::vector<int> operator ~(std::vector<int> f) {
        if (f.empty()) { return f; }
        int n = 1, m = f.size();
        while (n < m) { n *= 2; }
        f = polyInv(f, n); f.resize(m);
        return f;
    }
    
    std::vector<int> polyDeri(std::vector<int> f) {
        if (f.empty()) { return f; }
        int m = f.size();
        for (int i = 1; i < m; i++) { f[i - 1] = 1ll * f[i] * i % mod; }
        f.pop_back();
        return f;
    }
    std::vector<int> polyInte(std::vector<int> f) {
        f.push_back(0);
        int m = f.size();
        getInvFac(m);
        for (int i = m - 1; i >= 1; i--) { f[i] = 1ll * f[i - 1] * inv[i] % mod; }
        f[0] = 0;
        return f;
    }
    
    std::vector<int> polyLn(std::vector<int> f) {
        if (f.empty()) { return f; }
        int m = f.size();
        f = (~f) * polyDeri(f);
        f.resize(m); f = polyInte(f); f.pop_back();
        return f;
    }
    std::vector<int> polyExp(std::vector<int> f, int n, int o) {
        f.resize(n);
        if (n <= 128) {
            std::vector<int> h(n);
            h[0] = 1;
            getInvFac(n);
            for (int i = 1; i < n; i++) {
                f[i] = 1ll * f[i] * i % mod;
                unsigned long long g0 = 0, g1 = 0, g2 = 0, g3 = 0, g4 = 0, g5 = 0, g6 = 0, g7 = 0;
                for (int j = 0; j < i; j += 16) {
                    g0 = (g0 + 1ll * h[j] * f[i - j]) % mod;
                    if (j + 1 < i) { g1 += 1ll * h[j + 1] * f[i - j - 1]; }
                    if (j + 2 < i) { g2 += 1ll * h[j + 2] * f[i - j - 2]; }
                    if (j + 3 < i) { g3 += 1ll * h[j + 3] * f[i - j - 3]; }
                    if (j + 4 < i) { g4 += 1ll * h[j + 4] * f[i - j - 4]; }
                    if (j + 5 < i) { g5 += 1ll * h[j + 5] * f[i - j - 5]; }
                    if (j + 6 < i) { g6 += 1ll * h[j + 6] * f[i - j - 6]; }
                    if (j + 7 < i) { g7 += 1ll * h[j + 7] * f[i - j - 7]; }
                    if (j + 8 < i) { g0 += 1ll * h[j + 8] * f[i - j - 8]; }
                    if (j + 9 < i) { g1 += 1ll * h[j + 9] * f[i - j - 9]; }
                    if (j + 10 < i) { g2 += 1ll * h[j + 10] * f[i - j - 10]; }
                    if (j + 11 < i) { g3 += 1ll * h[j + 11] * f[i - j - 11]; }
                    if (j + 12 < i) { g4 += 1ll * h[j + 12] * f[i - j - 12]; }
                    if (j + 13 < i) { g5 += 1ll * h[j + 13] * f[i - j - 13]; }
                    if (j + 14 < i) { g6 += 1ll * h[j + 14] * f[i - j - 14]; }
                    if (j + 15 < i) { g7 += 1ll * h[j + 15] * f[i - j - 15]; }
                }
                h[i] = (g0 % mod + g1 % mod + g2 % mod + g3 % mod + g4 % mod + g5 % mod + g6 % mod + g7 % mod) * inv[i] % mod;
            }
            if (o) {
                gu = h; gv = ~h;
                getRevRoot(n * 2); ntt(gu, n * 2);
            }
            return h;
        }
        std::vector<int> g = polyExp(f, n / 2, 1), h(n);
        g.resize(n);
        for (int i = 0; i < n / 2; i++) { h[i] = g[i]; }
        std::vector<int> f0 = f; f0.resize(n / 2); f0 = polyDeri(f0);
        std::vector<int> g0 = polyDeri(g); g0.push_back(0);
        hv = gv; gv.resize(n);
        int invn = power(n, mod - 2);
        getRevRoot(n); ntt(f0, n);
        for (int i = 0; i < n; i++) { f0[i] = 1ll * f0[i] * gu[i] % mod; }
        std::reverse(f0.begin() + 1, f0.end()); ntt(f0, n);
        for (int i = 0; i < n; i++) { f0[i] = sub(g0[i], 1ll * f0[i] * invn % mod); }
        ntt(f0, n); ntt(hv, n);
        for (int i = 0; i < n; i++) { f0[i] = 1ll * f0[i] * hv[i] % mod; }
        std::reverse(f0.begin() + 1, f0.end()); ntt(f0, n); f0 = polyInte(f0);
        for (int i = 0; i < n / 2; i++) { f[i] = 0; }
        for (int i = n / 2; i < n; i++) { f[i] = sub(1ll * f0[i] * invn % mod, f[i]); }
        ntt(f, n);
        for (int i = 0; i < n; i++) { f[i] = 1ll * f[i] * gu[i] % mod; }
        std::reverse(f.begin() + 1, f.end()); ntt(f, n);
        for (int i = n / 2; i < n; i++) { h[i] = sub(0, 1ll * f[i] * invn % mod); }
        if (o) {
            gu = h;
            getRevRoot(n * 2); ntt(gu, n * 2); getRevRoot(n);
            for (int i = 0; i < n; i++) { f[i] = 1ll * gu[i * 2] * hv[i] % mod; }
            std::reverse(f.begin() + 1, f.end()); ntt(f, n);
            for (int i = 1; i < n / 2; i++) { f[i] = 0; }
            for (int i = n / 2; i < n; i++) { f[i] = 1ll * f[i] * invn % mod; }
            f[0] = 1; ntt(f, n);
            for (int i = 0; i < n; i++) { f[i] = 1ll * f[i] * hv[i] % mod; }
            std::reverse(f.begin() + 1, f.end()); ntt(f, n);
            for (int i = n / 2; i < n; i++) { gv[i] = sub(0, 1ll * f[i] * invn % mod); }
        }
        return h;
    }
    std::vector<int> polyExp(std::vector<int> f) {
        if (f.empty()) { return f; }
        int n = 1, m = f.size();
        while (n < m) { n *= 2; }
        f = polyExp(f, n, 0); f.resize(m);
        return f;
    }
}

using Polynom::operator *;

const int N = 1e6 + 5;

int n, ans;
std::vector<int> f, g;

int main() {
    getInvFac(300001);
    f.resize(300001);
    g.resize(300001);
    for (int i = 0; i <= 300000; i += 2) {
        f[i] = 1ll * power(499122177, i / 2) * invf[i / 2] % mod;
    }
    for (int i = 0; i <= 300000; i++) {
        g[i] = invf[i];
    }
    f = f * g;
    for (int T = read(); T; T--) {
        n = read();
        ans = 0;
        for (int i = 0; i <= n; i += 4) {
            ans = add(ans, 1ll * f[n - i] * fac[n - i] % mod * binom(n - i + i / 2, i / 2) % mod * fac[i / 2] % mod * invf[i / 4] % mod);
        }
        printf("%d\n", ans);
    }
    return 0;
}