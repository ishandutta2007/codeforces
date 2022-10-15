#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int n, k, a[105];

int solve() {
    n = std::unique(a, a + n) - a;
    int ans = 0;
    while (n > 1) {
        ans++;
        if (k == 1) { return -1; }
        n -= k - 1;
    }
    ans = std::max(ans, 1);
    return ans;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); k = read();
        for (int i = 0; i < n; i++) {
            a[i] = read();
        }
        printf("%d\n", solve());
    }
    return 0;
}