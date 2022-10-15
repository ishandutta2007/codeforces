#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 2e5 + 5;

int n, m, a[N];
long long sum = 0;

int main() {
    for (int T = read(); T; T--) {
        n = read(); sum = 0;
        bool flag = true;
        m = -1;
        for (int i = 0; i < n; i++) {
            a[i] = read();
            if (a[i] != 0) { m = i; }
        }
        m = m + 1;
        for (int i = 0; i < m; i++) {
            sum += a[i];
            if (i < m - 1 && sum <= 0) { flag = false; }
        }
        printf("%s\n", sum == 0 && flag ? "Yes" : "No");
    }
    return 0;
}