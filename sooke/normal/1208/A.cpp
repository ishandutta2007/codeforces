#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int a, b, n;

int main() {
    for (int T = read(); T; T--) {
        a = read(); b = read(); n = read();
        switch (n % 3) {
            case 0: {
                printf("%d\n", a); break;
            }
            case 1: {
                printf("%d\n", b); break;
            }
            case 2: {
                printf("%d\n", a ^ b); break;
            }
        }
    }
    return 0;
}