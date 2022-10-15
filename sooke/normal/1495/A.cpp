#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

int n;
double ans;
std::vector<int> a, b;

int main() {
    for (int T = read(); T; T--) {
        n = read(); a.clear(); b.clear();
        for (int i = 0; i < n * 2; i++) {
            int x = read(), y = read();
            if (x == 0) {
                a.push_back(std::abs(y));
            } else {
                b.push_back(std::abs(x));
            }
        }
        ans = 0;
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            ans += std::sqrt(1ll * a[i] * a[i] + 1ll * b[i] * b[i]);
        }
        printf("%.9f\n", ans);
    }
    return 0;
}