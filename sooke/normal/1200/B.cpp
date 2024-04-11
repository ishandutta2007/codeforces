#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, k, a[N];
long long m;

bool check() {
    for (int i = 0, x; i < n - 1; i++) {
        x = std::max(0, a[i + 1] - k);
        if (a[i] < x) {
            if (x - a[i] > m) { return false; }
            m -= x - a[i];
        } else {
            m += a[i] - x;
        }
    }
    return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read(); k = read();
        for (int i = 0; i < n; i++) { a[i] = read(); }
        printf("%s\n", check() ? "YES" : "NO");
    }
    return 0;
}