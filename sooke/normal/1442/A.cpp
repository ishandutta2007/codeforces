#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N];

bool check() {
    int x = 0, y = 1e9;
    for (int i = 0; i < n; i++) {
        a[i] -= x;
        if (a[i] < 0) { return false; }
        if (a[i] <= y) {
            y = a[i];
        } else {
            a[i] -= y;
            x += a[i];
        }
    }
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