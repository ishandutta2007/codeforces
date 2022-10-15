#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

inline int read() {
    char c = getchar(); int x = 0; bool sgn = false;
    while (c < '0' || c > '9') { if (c == '-') { sgn = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return sgn ? -x : x;
}

const int N = 1000005;

int n, m, l, r, a[N], s[N], t[N], f[N], g[N];
long long ans;

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; i++) { s[i] = n + 1; }
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        if (s[a[i]] == n + 1) { s[a[i]] = i; } t[a[i]] = i;
    }
    r = 0; f[0] = 0;
    for (int i = 1; i <= m; i++) {
        if (f[i - 1] == n + 1) { f[i] = n + 1; } else {
            if (s[i] < r) { f[i] = n + 1; } else { r = std::max(r, t[i]); f[i] = r; }
        }
    }
    l = n + 1; g[m + 1] = n + 1;
    for (int i = m; i >= 1; i--) {
        if (g[i + 1] == 0) { g[i] = 0; } else {
            if (t[i] > l) { g[i] = 0; } else { l = std::min(l, s[i]); g[i] = l; }
        }
    }
    for (int i = 1; i <= m; i++) {
        ans += m + 2 - (std::upper_bound(g + i + 1, g + m + 2, f[i - 1]) - g);
    }
    printf("%I64d\n", ans);
    return 0;
}