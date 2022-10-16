#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5;

int n, a[N], cnt[N], e[501][N / 2];
long long ans;

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read();
        int x = a[i];
        for (int d = 2; d <= 500; d++) {
            int c = 0;
            while (x % d == 0) { x /= d; c++; }
            e[d][i] = c;
        }
        if (x > 1) { cnt[x]++; }
    }
    ans = 1;
    for (int d = 2; d <= 500; d++) {
        std::nth_element(e[d] + 0, e[d] + 1, e[d] + n);
        for (int i = 0; i < e[d][1]; i++) { ans *= d; }
    }
    for (int d = 501; d <= 200000; d++) {
        if (cnt[d] >= n - 1) { ans *= d; }
    }
    printf("%lld\n", ans);
    return 0;
}