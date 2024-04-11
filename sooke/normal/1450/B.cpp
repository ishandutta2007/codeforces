#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, k, a[N], b[N];

int solve() {
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            flag &= std::abs(a[i] - a[j]) + std::abs(b[i] - b[j]) <= k;
        }
        if (flag) { return 1; }
    }
    return -1;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); k = read();
        for (int i = 0; i < n; i++) {
            a[i] = read(); b[i] = read();
        }
        printf("%d\n", solve());
    }
    return 0;
}