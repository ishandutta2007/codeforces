#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int n, m, k, x, y;

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read(); k = read();
        printf("%d\n", std::min((n + m + k) / 3, std::min(n, m)));
    }    
    return 0;
} //