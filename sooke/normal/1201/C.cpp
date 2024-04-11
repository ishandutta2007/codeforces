#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, k, ans, a[N];

bool check(int x) {
    long long sum = 0;
    for (int i = 0; i < m; i++) {
        sum += std::max(0ll, 0ll + x + a[i]);
    }
    return sum <= k;
}

int main() {
    n = read(); m = n / 2 + 1; k = read();
    for (int i = 0; i < n; i++) { a[i] = -read(); }
    std::sort(a, a + n);
    for (int l = 0, r = 2e9, mid; l <= r; ) {
        mid = (0ll + l + r) / 2;
        if (check(mid)) {
            l = mid + 1; ans = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}