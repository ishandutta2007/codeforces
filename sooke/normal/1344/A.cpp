#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, a[N];

bool check() {
    for (int i = 0; i < n; i++) {
        a[i] = (i + n + a[i] % n) % n;
    }
    std::sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (a[i] != i) { return false; }
    }
    return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 0; i < n; i++) {
            a[i] = read();
        }
        printf("%s\n", check() ? "Yes" : "No");
    }
    return 0;
}