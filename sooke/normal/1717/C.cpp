#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, a[N], b[N];

bool solve() {
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) { return false; }
        if (a[i] < b[i] && b[i] > b[(i + 1) % n] + 1) { return false; }
        // if (a[i] > a[(i + 1) % n] && b[i] <= b[(i + 1) % n]) { return false; }
        // if (b[i] > b[(i + 1) % n] && a[i] - a[(i + 1) % n] < b[i] - b[(i + 1) % n]) { return false; }
    }
    return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 0; i < n; i++) { a[i] = read(); }
        for (int i = 0; i < n; i++) { b[i] = read(); }
        printf("%s\n", solve() ? "YES" : "NO");
    }
    return 0;
}