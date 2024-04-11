#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, max, a[N], b[N];

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read();
        b[i] = a[i] + max;
        max = std::max(max, b[i]);
        printf("%d ", b[i]);
    }
    return 0;
}