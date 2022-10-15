#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

inline int power(int x, int y, int res = 1) {
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    } return res;
}

const int N = 1e3 + 5;

int n, m, a[N], b[N], f[N][N];

int solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            if (f[i][j] == 1) { return 0; }
            f[i][j] = 2;
        }
        if (f[i][a[i]] == 2) { return 0; }
        f[i][a[i]] = 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < b[i]; j++) {
            if (f[j][i] == 1) { return 0; }
            f[j][i] = 2;
        }
        if (f[b[i]][i] == 2) { return 0; }
        f[b[i]][i] = 2;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == 0) { res++; }
        }
    } return power(2, res);
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < n; i++) { a[i] = read(); }
    for (int i = 0; i < m; i++) { b[i] = read(); }
    printf("%d\n", solve());
    return 0;
}