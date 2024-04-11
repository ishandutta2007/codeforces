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
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 200005;

int n, m, num, ans = 1e9, a[maxN], b[maxN];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); } a[++n] = 1e9; 
    for (int i = 1; i <= m; i++) {
        int l = read(), r = read(), y = read();
        if (l == 1) { b[++num] = r; }
    }
    std::sort(a + 1, a + n + 1); std::sort(b + 1, b + num + 1);
    for (int i = 1; i <= n; i++) { ans = std::min(ans, i - 1 + num + 1 - (std::lower_bound(b + 1, b + num + 1, a[i]) - b)); }
    printf("%d\n", ans);
    return 0;
} //