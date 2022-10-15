#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 105;

int n, m, cnt[maxN];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        m = read();
        for (int j = 1; j <= m; j++) { cnt[read()]++; }
    }
    for (int i = 1; i <= 100; i++) {
        if (cnt[i] == n) { printf("%d ", i); }
    }
    return 0;
} ///