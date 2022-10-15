#include <bits/stdc++.h>

inline long long read() {
    char c, _c; long long x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e5 + 5;

long long n, m, k, now, ans, a[N];

inline long long get(long long x) { return (x - now - 1) / k; }

int main() {
    n = read(); m = read(); k = read();
    for (int i = 0; i < m; i++) { a[i] = read(); }
    for (int i = 0, j = 0; i < m; i = j) {
        for (; j < m && get(a[i]) == get(a[j]); j++);
        ans++; now = j;
    }
    printf("%lld\n", ans);
    return 0;
}