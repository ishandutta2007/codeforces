#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int T, n, m;

int main() {
    for (T = read(); T; T--) {
        n = read(); m = read();
        if (m % 3 == 0) {
            n %= m + 1;
            printf("%s\n", n % 3 || n == m ? "Alice" : "Bob");
        } else { printf("%s\n", n % 3 ? "Alice" : "Bob"); }
    }
    return 0;
}