#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int p = 998244353, gen = 3;

inline int add(int x, int y) { x += y; return x >= p ? x - p : x; }
inline int sub(int x, int y) { x -= y; return x >= 0 ? x : x + p; }
inline int power(int x, int y) { int res = 1; for (; y; y >>= 1, x = (long long) x * x % p) { if (y & 1) { res = (long long) res * x % p; } } return res; }

namespace Polynom {
    std::vector<int> rev, root, fac, inv, one = {1};

    std::vector<int> operator +(std::vector<int> f, std::vector<int> g) {
        int n = (int) std::max(f.size(), g.size()); f.resize(n); g.resize(n);
        for (int i = 0; i < n; i++) { f[i] = add(f[i], g[i]); } return f;
    }
    std::vector<int> operator -(std::vector<int> f, std::vector<int> g) {
        int n = (int) std::max(f.size(), g.size()); f.resize(n); g.resize(n);
        for (int i = 0; i < n; i++) { f[i] = sub(f[i], g[i]); } return f;
    }

    void getRevRoot(int n) {
        int m = log(n) / log(2) + 1e-7; rev.resize(n); root.resize(n);
        for (int i = 1; i < n; i++) { rev[i] = rev[i >> 1] >> 1 | (i & 1) << m - 1; }
        for (int len = 1, uni; len < n; len <<= 1) {
            uni = power(gen, (p ^ 1) / (len << 1)); root[len] = 1;
            for (int i = 1; i < len; i++) { root[i + len] = (long long) root[i + len - 1] * uni % p; }
        }
    }
    void ntt(std::vector<int> &f, int n) {
        f.resize(n);
        for (int i = 0; i < n; i++) { if (i < rev[i]) { std::swap(f[i], f[rev[i]]); } }
        for (int len = 1; len < n; len <<= 1) {
            for (int i = 0; i < n; i += len << 1) {
                for (int j = 0; j < len; j++) {
                    int x = f[i + j], y = (long long) f[i + j + len] * root[j + len] % p;
                    f[i + j] = add(x, y); f[i + j + len] = sub(x, y);
                }
            }
        }
    }
    std::vector<int> operator *(std::vector<int> f, std::vector<int> g) {
        int n = 1, m = (int) f.size() + (int) g.size() - 1, invN;
        while (n < m) { n <<= 1; } invN = power(n, p - 2);
        getRevRoot(n); ntt(f, n); ntt(g, n);
        for (int i = 0; i < n; i++) { f[i] = (long long) f[i] * g[i] % p; }
        std::reverse(f.begin() + 1, f.end()); ntt(f, n);
        for (int i = 0; i < n; i++) { f[i] = (long long) f[i] * invN % p; }
        f.resize(m); return f;
    }

    std::vector<int> polyInv(std::vector<int> f, int m) {
        std::vector<int> g, h; f.resize(m);
        if (m == 2) { g.push_back(power(f[0], p - 2)); } else { g = polyInv(f, m >> 1); }
        int n = m << 1, invN = power(n, p - 2); g.resize(m); h.resize(m);
        for (int i = (m >> 1) - 1; ~i; i--) { h[i] = (g[i] << 1) % p; }
        getRevRoot(n); ntt(f, n); ntt(g, n);
        for (int i = 0; i < n; i++) { f[i] = (long long) f[i] * g[i] % p * g[i] % p; }
        std::reverse(f.begin() + 1, f.end()); ntt(f, n);
        for (int i = 0; i < m; i++) { h[i] = sub(h[i], (long long) f[i] * invN % p); }
        return h;
    }
    std::vector<int> operator ~(std::vector<int> f) {
        int n = 1, m = (int) f.size();
        while (n < m) { n <<= 1; } f = polyInv(f, n);
        f.resize(m); return f;
    }

    void getFacInv(int n) {
        if (n <= (int) fac.size()) { return; } fac.resize(n); inv.resize(n);
        for (int i = fac[0] = 1; i < n; i++) { fac[i] = (long long) fac[i - 1] * i % p; }
        inv[n - 1] = power(fac[n - 1], p - 2);
        for (int i = n - 1; i; i--) { inv[i - 1] = (long long) inv[i] * i % p; }
    }
    std::vector<int> operator >>(std::vector<int> f, int m) {
        int n = (int) f.size(); m = std::min(n, m); getFacInv(n);
        for (int i = m; i < n; i++) { f[i - m] = (long long) f[i] * fac[i] % p * inv[i - m] % p; }
        f.resize(n - m); return f;
    }
    std::vector<int> operator <<(std::vector<int> f, int m) {
        int n = (int) f.size(); f.resize(n + m); getFacInv(n + m);
        for (int i = n + m - 1; i >= m; i--) { f[i] = (long long) f[i - m] * fac[i - m] % p * inv[i] % p; }
        std::fill(f.begin(), f.begin() + m, 0); return f;
    }

    std::vector<int> polyLn(std::vector<int> f) {
        int n = (int) f.size(); f = (f >> 1) * (~f) << 1;
        f.resize(n); return f;
    }
    std::vector<int> polyExp(std::vector<int> f, int n) {
        std::vector<int> g, h; f.resize(n);
        if (n == 2) { g.push_back(1); } else { g = polyExp(f, n >> 1); }
        g.resize(n); return g * (one - polyLn(g) + f);
    }
    std::vector<int> polyExp(std::vector<int> f) {
        int n = 1, m = (int) f.size();
        while (n < m) { n <<= 1; } f = polyExp(f, n);
        f.resize(m); return f;
    }
    std::vector<int> operator ^(std::vector<int> f, int x) {
        int n = (int) f.size(); f = polyLn(f);
        for (int i = 0; i < n; i++) { f[i] = (long long) f[i] * x % p; }
        return polyExp(f);
    }
}

using Polynom::one;
using Polynom::operator +;
using Polynom::operator -;
using Polynom::operator ~;
using Polynom::operator ^;

int n, m;
std::vector<int> f;

int main() {
    n = read(); m = read() + 1; f.resize(m);
    for (int i = 1; i <= n; i++) { int x = read(); if (x < m) { f[x] += 4; } }
    f = ~((one - f ^ p + 1 >> 1) + one);
    for (int i = 1; i < m; i++) { printf("%d\n", (f[i] << 1) % p); }
    return 0;
}