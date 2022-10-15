#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, m, k, cnt[N];

int main() {
    n = read(); m = read();
    for (int i = 0; i < n; i++) { cnt[read() - 1]++; }
    for (int i = 0; i < m; i++) { k += cnt[i] & 1; }
    printf("%d\n", n - k / 2);
    return 0;
}