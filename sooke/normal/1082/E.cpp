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

const int maxN = 500005;

int n, m, cnt, num, ans, a[maxN], max[maxN], lst[maxN];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); cnt += a[i] == m; }
    for (int i = 1; i <= n; i++) {
        if (a[i] == m) { num--; } else {
            max[a[i]] = std::max(max[a[i]] - lst[a[i]] + num, 0) + 1; lst[a[i]] = num;
            ans = std::max(ans, max[a[i]]);
        }
    }
    printf("%d\n", ans + cnt);
    return 0;
} ///