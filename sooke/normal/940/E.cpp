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

const int maxN = 100005;

int n, m, l, r, a[maxN], q[maxN];
long long f[maxN], sum[maxN];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); sum[i] = sum[i - 1] + a[i]; }
    memset(f, 60, sizeof(f)); f[0] = 0;
    for (int i = 1; i <= n; i++) {
        while (l <= r && q[l] + m <= i) { l++; }
        f[i] = f[i - 1] + a[i];
        while (l <= r && a[q[r]] >= a[i]) { r--; }
        q[++r] = i;
        if (i >= m) { f[i] = std::min(f[i], f[i - m] + sum[i] - sum[i - m] - a[q[l]]); }
    }
    printf("%I64d\n", f[n]);
    return 0;
} ///