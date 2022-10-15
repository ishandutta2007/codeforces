#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, a[N], b[N];
long long f[3][N];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    for (int i = 1; i <= n; i++) { b[i] = read(); }
    for (int i = 1; i <= n; i++) {
        f[0][i] = std::max(f[0][i], f[0][i - 1]);
        f[0][i] = std::max(f[0][i], f[1][i - 1]);
        f[0][i] = std::max(f[0][i], f[2][i - 1]);
        f[1][i] = std::max(f[1][i], f[0][i - 1] + a[i]);
        // f[1][i] = std::max(f[1][i], f[1][i - 1] + a[i]);
        f[1][i] = std::max(f[1][i], f[2][i - 1] + a[i]);
        f[2][i] = std::max(f[2][i], f[0][i - 1] + b[i]);
        f[2][i] = std::max(f[2][i], f[1][i - 1] + b[i]);
        // f[2][i] = std::max(f[2][i], f[2][i - 1] + b[i]);
    }
    printf("%I64d\n", std::max(std::max(f[0][n], f[1][n]), f[2][n]));
    return 0;
}