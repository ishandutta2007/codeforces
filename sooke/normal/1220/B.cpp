#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e3 + 5;

int n, a[N][N], ans[N];
long double x;

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { a[i][j] = read(); }
    } x = sqrtl((long double) a[0][1] * a[1][2] * a[0][2]);
    ans[0] = (int) (x / a[1][2]);
    for (int i = 1; i < n; i++) { ans[i] = a[0][i] / ans[0]; }
    for (int i = 0; i < n; i++) { printf("%d ", ans[i]); }
    return 0;
}