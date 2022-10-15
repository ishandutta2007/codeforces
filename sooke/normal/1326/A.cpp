#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

int T, n;

int main() {
    for (int T = read(); T; T--) {
        n = read();
        if (n == 1) {
            printf("-1");
        } else {
            int x = 0;
            for (int i = 1; i < n; i++) {
                x = (x + 2) % 3;
            }
            if (x == 0) {
                printf("4");
                for (int i = 2; i < n; i++) {
                    printf("2");
                }
            } else {
                for (int i = 1; i < n; i++) {
                    printf("2");
                }
            }
            printf("3");
        }
        printf("\n");
    }
    return 0;
}