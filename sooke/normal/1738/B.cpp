#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, k, a[N], s[N];

bool solve() {
    if (k == 1) { return true; }
    for (int i = n - k + 2; i <= n; i++) {
        a[i] = s[i] - s[i - 1];
        if (i > n - k + 2) {
            if (a[i] < a[i - 1]) { return false; }
        }
    }
    return s[n - k + 1] <= 1ll * a[n - k + 2] * (n - k + 1);
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); k = read();
        for (int i = n - k + 1; i <= n; i++) {
            s[i] = read();
        }
        printf("%s\n", solve() ? "Yes" : "No");
    }
    return 0;
}