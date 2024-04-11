#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, ans, a[N];

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 0; i < n; i++) { a[i] = read(); }
        std::sort(a, a + n);
        ans = std::min(a[n - 2], a[n - 1]);
        printf("%d\n", std::min(ans - 1, n - 2));
    }
    return 0;
}