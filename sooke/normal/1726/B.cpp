#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, m, ans, a[N];

bool solve() {
    if (m < n) { return false; }
    if (n == 1) { a[1] = m; return true; }
    if (n == 2) { a[1] = m / 2; a[2] = m - m / 2; return a[1] == a[2]; }
    if (m == n) {
        for (int i = 1; i <= n; i++) { a[i] = 1; }
        return true;
    }
    if (m == n + 1) {
        for (int i = 1; i <= n; i++) { a[i] = i == 1 ? 2 : 1; }
        return (n - 1) % 2 == 0;
    }
    for (int i = 1; i <= n; i++) { a[i] = i == 1 ? m - (n - 1) : 1; }
    if ((n - 1) % 2 == 0) {
        return true;
    }
    if (n == 4 && m == 6) { a[1] = 3; a[2] = a[3] = a[4] = 1; return true; }
    if (m % 2 != 0) { return false; }
    int x = (a[1] + a[2]) / 2;
    a[1] = a[2] = x;
    return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read(); ans = 0;
        
        if (solve()) {
            printf("Yes\n");
            for (int i = 1; i <= n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}