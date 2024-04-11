#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, x, y, a[N];
long long ans0, ans1;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        if (a[i] > 0) {
            a[i] = 0;
        } else {
            a[i] = 1;
        }
    }
    x++;
    for (int i = 1; i <= n; i++) {
        a[i] ^= a[i - 1];
        if (a[i] == 0) {
            ans0 += x; ans1 += y; x++;
        } else {
            ans0 += y; ans1 += x; y++;
        }
    } printf("%lld %lld\n", ans1, ans0);
    return 0;
}