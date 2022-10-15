#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const double eps = 1e-7, pi = acos(-1);

struct Complex {
    double re, im;
};

Complex operator +(const Complex &x, const Complex &y) {
    return (Complex) {x.re + y.re, x.im + y.im};
}
Complex operator -(const Complex &x, const Complex &y) {
    return (Complex) {x.re - y.re, x.im - y.im};
}
Complex operator *(const Complex &x, const Complex &y) {
    return (Complex) {x.re * y.re - x.im * y.im, x.re * y.im + x.im * y.re};
}

namespace Polynom {
    std::vector<int> rev;
    std::vector<Complex> rt;
    
    void getRevRoot(int n) {
        int m = log(n) / log(2) + eps;
        rev.resize(n); rt.resize(n);
        for (int i = 1; i < n; i++) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << m - 1;
        }
        for (int len = 1; len < n; len *= 2) {
            rt[len] = (Complex) {1, 0};
            Complex uni = (Complex) {cos(pi / len), sin(pi / len)};
            for (int i = 1; i < len; i++) {
                rt[len + i] = rt[len + i - 1] * uni;
            }
        }
    }
    void fft(std::vector<Complex> &f, int n) {
        for (int i = 0; i < n; i++) {
            if (i < rev[i]) { std::swap(f[i], f[rev[i]]); }
        }
        for (int len = 1; len < n; len *= 2) {
            for (int i = 0; i < n; i += len * 2) {
                for (int j = 0; j < len; j++) {
                    Complex x = f[i + j], y = f[i + j + len] * rt[len + j];
                    f[i + j] = x + y; f[i + j + len] = x - y;
                }
            }
        }
    }
    std::vector<double> operator *(const std::vector<double> &f, const std::vector<double> &g) {
        int n = 1, m = f.size() + g.size() - 1, invn;
        while (n < m) { n *= 2; }
        std::vector<Complex> a(n), b(n);
        for (int i = 0; i < f.size(); i++) { a[i].re = f[i]; }
        for (int i = 0; i < g.size(); i++) { b[i].re = g[i]; }
        getRevRoot(n); fft(a, n); fft(b, n);
        for (int i = 0; i < n; i++) { a[i] = a[i] * b[i]; }
        std::reverse(a.begin() + 1, a.end()); fft(a, n);
        std::vector<double> res(m);
        for (int i = 0; i < m; i++) { res[i] = a[i].re / n; }
        return res;
    }
}

using Polynom::operator *;

const int N = 105, M = 4e4 + 5;

int n, m, t, k, eu[N], ev[N], ew[N], dis[N][N];
double ans, p[N][M], dp[N][M], ep[N][M];

void cdq(int l, int r) {
    if (r <= t) {
        for (int i = l; i <= r; i++) {
            for (int u = 1; u <= n; u++) {
                dp[u][i] = dis[u][n] + k;
            }
        }
        dp[n][t] = 0;
        return;
    }
    if (l == r) {
        for (int u = 1; u <= n; u++) {
            dp[u][l] = dp[u][l - 1];
        }
        for (int i = 0; i < m; i++) {
            int u = eu[i];
            dp[u][l] = std::min(dp[u][l], ep[i][l] + ew[i]);
        }
        return; 
    }
    int mid = l + r >> 1;
    cdq(l, mid);
    for (int i = 0; i < m; i++) {
        int u = eu[i], v = ev[i];
        std::vector<double> f(mid - l + 1);
        std::vector<double> g(r - l + 1);
        for (int j = l; j <= mid; j++) {
            f[j - l] = dp[v][j];
        }
        for (int j = 0; j <= r - l; j++) {
            g[j] = p[i][j];
        }
        f = f * g;
        for (int j = mid - l + 1; j <= r - l; j++) {
            ep[i][l + j] += f[j];
        }
    }
    cdq(mid + 1, r);
}

int main() {
    n = read(); m = read(); t = read(); k = read();
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            dis[u][v] = u == v ? 0 : 1e9;
        }
    }
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(), w = read();
        eu[i] = u; ev[i] = v; ew[i] = w;
        dis[u][v] = std::min(dis[u][v], w);
        for (int j = 1; j <= t; j++) {
            p[i][j] = read(); p[i][j] /= 1e5;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                dis[u][v] = std::min(dis[u][v], dis[u][i] + dis[i][v]);
            }
        }
    }
    cdq(0, t * 2);
    ans = 1e18;
    for (int i = 0; i <= t * 2; i++) {
        ans = std::min(ans, dp[1][i]);
    }
    printf("%.6f\n", ans);
    return 0;
}