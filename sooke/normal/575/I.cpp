#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 5e3 + 5, M = 1e6 + 5;

int n, q, ans[M];

struct Action {
    int opt, dir, x, y, len;
} a[M];

struct FenwickTree {
    int n, m, f[N][N * 2];

    void reset(int _n, int _m) {
        n = _n; m = _m;
        for (int i = 1; i <= n; i++) {
            memset(f[i], 0, (m + 1) * 4);
        }
    }
    void modify(int u, int v, int x) {
        u = std::min(u, n);
        v = std::min(v, m);
        for (int i = u; i >= 1; i ^= i & -i) {
            for (int j = v; j >= 1; j ^= j & -j) {
                f[i][j] += x;
            }
        }
    }
    int query(int u, int v) {
        int res = 0;
        for (int i = u; i <= n; i += i & -i) {
            for (int j = v; j <= m; j += j & -j) {
                res += f[i][j];
            }
        }
        return res;
    }
} tr;

int main() {
    n = read(); q = read();
    for (int i = 0; i < q; i++) {
        a[i].opt = read();
        if (a[i].opt == 1) {
            a[i].dir = read(); a[i].dir--;
            a[i].x = read(); a[i].y = read(); a[i].len = read();
        } else {
            a[i].x = read(); a[i].y = read();
        }
    }
    for (int d = 0; d < 4; d++) {
        for (int i = 0; i < q; i++) {
            if (d == 1) { a[i].y = n + 1 - a[i].y; }
            if (d == 2) { a[i].x = n + 1 - a[i].x; a[i].y = n + 1 - a[i].y; }
            if (d == 3) { a[i].y = n + 1 - a[i].y; }
        }
        tr.reset(n, n * 2);
        for (int i = 0; i < q; i++) {
            if (a[i].opt == 1) {
                if (a[i].dir != d) { continue; }
                tr.modify(n, a[i].x + a[i].y + a[i].len, 1);
                tr.modify(a[i].x - 1, a[i].x + a[i].y + a[i].len, -1);
            } else {
                ans[i] += tr.query(a[i].x, a[i].x + a[i].y);
            }
        }
        tr.reset(n, n * 2);
        for (int i = 0; i < q; i++) {
            if (a[i].opt == 1) {
                if (a[i].dir != d) { continue; }
                tr.modify(a[i].y - 1, a[i].x + a[i].y + a[i].len, -1);
            } else {
                ans[i] += tr.query(a[i].y, a[i].x + a[i].y);
            }
        }
        tr.reset(n, n);
        for (int i = 0; i < q; i++) {
            if (a[i].opt == 1) {
                if (a[i].dir != d) { continue; }
                tr.modify(a[i].x - 1, a[i].y - 1, 1);
            } else {
                ans[i] += tr.query(a[i].x, a[i].y);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        if (a[i].opt == 2) { printf("%d\n", ans[i]); }
    }
    return 0;
}