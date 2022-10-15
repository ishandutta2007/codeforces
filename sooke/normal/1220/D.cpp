#include <bits/stdc++.h>

inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 100;

int n, p, max;
std::vector<long long> a[N], b[N];

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        long long x = read(), _x, y = 0; _x = x;
        for (; x % 2 == 0; x /= 2) { y++; }
        a[y].push_back(_x);
    }
    for (int i = 0; i < N; i++) { max = std::max(max, (int) a[i].size()); }
    printf("%d\n", n - max);
    for (int i = 0; i < N; i++) {
        if (a[i].size() == max) {
            p = i; break;
        }
    }
    for (int i = 0; i < N; i++) {
        if (p != i) {
            for (auto u : a[i]) { printf("%I64d ", u); }
        }
    }
    return 0;
}