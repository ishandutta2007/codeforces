#include <bits/stdc++.h>

inline long long read() {
    char c, _c; long long x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, k1, w1, k2, w2;
long long k, a[N], b[N];

bool compare(long long x, long long y) { return x > y; }

bool check(int m) {
    for (int i = 1; i <= m; i++) {
        b[i] = 0;
        if (i % k1 == 0) { b[i] += w1; }
        if (i % k2 == 0) { b[i] += w2; }
    } std::sort(b + 1, b + m + 1, compare);
    long long res = 0;
    for (int i = 1; i <= m; i++) { res += a[i] * b[i]; }
    return res >= k;
}
int solve() {
    int res = -1;
    for (int l = 1, r = n, mid; l <= r; ) {
        mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1; res = mid;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 1; i <= n; i++) { a[i] = read() / 100; }
        std::sort(a + 1, a + n + 1, compare);
        w1 = read(); k1 = read(); w2 = read(); k2 = read(); k = read();
        printf("%d\n", solve());
    }
    return 0;
}