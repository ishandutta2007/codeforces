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

const int maxN = 1000005;

int n, m, max, a[maxN], sum[maxN], l[maxN], r[maxN], f[maxN], ans[maxN];

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); max = std::max(max, a[i]); }
    for (int i = 1; i <= m; i++) { l[i] = read(), r[i] = read(); }
    for (int i = 1; i <= max; i++) { sum[i] = sum[i - 1] ^ i; }
    for (int i = 1; i <= n; i++) {
        f[i] = a[i];
        for (int j = i + 1; j <= n; j++) {
            if (a[j] <= a[i]) { f[j] = std::max(f[j - 1], sum[a[j] - 1] ^ sum[a[i]]); }
            else { f[j] = std::max(f[j - 1], sum[a[i] - 1] ^ sum[a[j]]); }
        }
        for (int j = 1; j <= m; j++) {
            if (l[j] <= i) { ans[j] = std::max(ans[j], f[r[j]]); }
        }
    }
    for (int i = 1; i <= m; i++) { printf("%d\n", ans[i]); }
    return 0;
}