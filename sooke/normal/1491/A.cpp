#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, q, x, a[N];

int main() {
    n = read(); q = read();
    for (int i = 0; i < n; i++) {
        a[i] = read();
        x += a[i] == 1;
    }
    for (; q; q--) {
        int opt = read();
        if (opt == 1) {
            int i = read(); i--;
            x -= a[i] == 1;
            a[i] ^= 1;
            x += a[i] == 1;
        } else {
            int k = read();
            printf("%d\n", x >= k);
        }
    }
    return 0;
}