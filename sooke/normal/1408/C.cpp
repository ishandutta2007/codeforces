#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, x, y, xx, yy, a[N];
double p, q;

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read();
        x = 1; y = 1; xx = 0; yy = n + 1; p = q = 0;
        for (int i = 1; i <= n; i++) { a[i] = read(); }
        a[n + 1] = m;
        for (int i = 1; i <= n; i++) {
            if (p + (a[xx + 1] - a[xx]) / (x * 1.0) < q + (a[yy] - a[yy - 1]) / (y * 1.0)) {
                p += (a[xx + 1] - a[xx]) / (x * 1.0);
                x++; xx++;
            } else {
                q += (a[yy] - a[yy - 1]) / (y * 1.0);
                y++; yy--;
            }
        }
        if (p > q) {
            printf("%.8f\n", p + (a[yy] - a[xx] - (p - q) * y) / (x * 1.0 + y));
        } else {
            printf("%.8f\n", q + (a[yy] - a[xx] - (q - p) * x) / (x * 1.0 + y));
        }
    }
}