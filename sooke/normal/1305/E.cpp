#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, m, f[N];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) { f[i] = f[i - 1] + (i - 1) / 2; }
    if (m > f[n]) { printf("-1\n"); return 0; }
    for (int i = n; i >= 1; i--) {
        if (f[i - 1] <= m) {
            for (int j = 1; j < i; j++) { printf("%d ", j); }
            printf("%d ", i + ((i - 1) / 2 - (m - f[i - 1])) * 2);
            for (int j = 0; j < n - i; j++) { printf("%d ", (int) 5e8 + j * 40000); }
            return 0;
        }
    }
    return 0;
}