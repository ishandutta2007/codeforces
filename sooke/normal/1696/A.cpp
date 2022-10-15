#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

int n, z, ans;

int main() {
    for (int T = read(); T; T--) {
        n = read(); z = read();
        ans = 0;
        for (int i = 0; i < n; i++) {
            int x = read();
            ans = std::max(ans, x | z);
        }
        printf("%d\n", ans);
    }
    return 0;
}