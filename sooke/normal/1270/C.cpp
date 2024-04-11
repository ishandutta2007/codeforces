#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, a[N];
long long now, tmp;

void solve() {
    printf("2\n%lld %lld\n", tmp, now + tmp);
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); now = 0; tmp = 0;
        for (int i = 0; i < n; i++) { a[i] = read(); now += a[i]; tmp ^= a[i]; }
        solve();
    }
    return 0;
}