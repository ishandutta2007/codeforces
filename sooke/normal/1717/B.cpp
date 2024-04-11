#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 505;

int n, k, r, c;

int main() {
    for (int T = read(); T; T--) {
        n = read(); k = read(); r = read(); c = read();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                putchar((i + j) % k == (r + c) % k ? 'X' : '.');
            }
            printf("\n");
        }
    }
    return 0;
}