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

int n, m, ans = 1e9, a[maxN];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (a[j] - a[i] <= m) { ans = std::min(ans, n - (j - i + 1)); }
        }
    }
    printf("%d\n", ans);
    return 0;
} //