#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, ans, a[N], b[N];

int main() {
    n = read(); m = n - read();
    for (int i = 0; i < n; i++) { a[i] = read(); }
    for (int i = 1; i < n; i++) { b[i] = a[i] - a[i - 1]; }
    std::sort(b + 1, b + n);
    for (int i = 1; i <= m; i++) { ans += b[i]; }
    printf("%d\n", ans);
    return 0;
}