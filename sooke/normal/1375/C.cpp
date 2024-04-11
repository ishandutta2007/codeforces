#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N];

bool check() {
    if (a[0] > a[n - 1]) { return false; }
    return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 0; i < n; i++) {
            a[i] = read();
        }
        printf("%s\n", check() ? "YES" : "NO");
    }    
    return 0;
}