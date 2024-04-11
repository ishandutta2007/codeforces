#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int main() {
    for (int T = read(); T; T--) {
        read(); printf("%d\n", read() << 1);
    }
    return 0;
}