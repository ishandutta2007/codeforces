#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int inf = 1e9;
const int N = 2e5 + 5;

int n, k, a[N];

int main() {
    int T = read();
    for (; T; T--) {
        n = read(); k = read();
        int ans = 0, min = inf + 1, max = -inf;
        for (int i = 0; i < n; i++) {
            a[i] = read();
            if (min > inf) {
                min = max = a[i];
            } else {
                max = std::max(max, a[i]);
                min = std::min(min, a[i]);
                if (max - min > k * 2) {
                    max = min = a[i]; ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}