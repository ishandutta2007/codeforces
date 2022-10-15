#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

int n, a, b;

int main() {
    for (int T = read(); T; T--) {
        n = read(); a = read(); b = read();
        bool flag;
        for (int i = 0; i < a; i++) {
            int x = read();
            if (x == n) { flag = true; }
        }
        for (int i = 0; i < b; i++) {
            int x = read();
            if (x == n) { flag = false; }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}