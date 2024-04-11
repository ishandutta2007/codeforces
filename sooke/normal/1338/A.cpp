#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n;
long long a[N];

int main() {
    for (int T = read(); T; T--) {
        n = read();
        long long max = 0;
        for (int i = 1; i <= n; i++) { a[i] = read(); }
        for (int i = 2; i <= n; i++) {
            if (a[i - 1] > a[i]) {
                max = std::max(max, a[i - 1] - a[i]);
                a[i] = a[i - 1];
            }
        }
        int ans = 0;
        long long now = 1;
        for (; now - 1 < max; ans++, now *= 2);
        printf("%d\n", ans);
    }
    return 0;
}