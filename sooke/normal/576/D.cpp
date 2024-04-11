#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 151;

int n, m, ans;

typedef std::vector<std::bitset<N>> closure;

closure operator *(closure f, closure g) {
    closure res; res.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (f[i][j]) { res[i] |= g[j]; }
        }
    }
    return res;
}

closure f, _f, g[31], h[31];

struct Edge {
    int t, u, v;
} edg[N];

bool operator <(const Edge &i, const Edge &j) {
    return i.t < j.t;
}

int main() {
    n = read(); m = read();
    f.resize(n); g[0].resize(n); h[0].resize(n);
    f[0][0] = 1; h[0][n - 1][n - 1] = 1;
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(), t = read(); u--; v--;
        edg[i] = (Edge) {t, u, v};
    }
    std::sort(edg, edg + m);
    edg[m] = (Edge) {edg[m - 1].t + n * n, 0, 0};
    for (int i = 0, _i, lst = 0; i <= m; i = _i) {
        int d = edg[i].t - lst;
        ans = lst; lst = edg[i].t;
        for (int j = 1; j <= 29; j++) {
            g[j] = g[j - 1] * g[j - 1];
            h[j] = h[j - 1] * h[j - 1];
        }
        for (int j = 29; j >= 0; j--) {
            if (d >> j & 1) {
                _f = f * h[j];
                if (!_f[0][n - 1]) {
                    f = f * g[j]; ans += 1 << j;
                } else {
                    for (int k = j - 1; k >= 0; k--) {
                        _f = f * h[k];
                        if (!_f[0][n - 1]) {
                            f = _f; ans += 1 << k;
                        }
                    }
                    printf("%d\n", ans + 1);
                    return 0;
                }
            }
        }
        for (_i = i; _i <= m && edg[i].t == edg[_i].t; _i++) {
            g[0][edg[_i].u][edg[_i].v] = 1;
            h[0][edg[_i].u][edg[_i].v] = 1;
        }
    }
    printf("Impossible\n");
    return 0;
}