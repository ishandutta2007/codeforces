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

const int N = 300005;

int n, ans, a[N], f[N], g[N];
std::set<std::pair<int, int>> set;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        if (!f[a[i]]) {
            f[a[i]] = i;
            set.insert({f[a[i]], a[i]});
        }
        g[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] && (int) set.size() > 1) {
            set.erase({f[i], i});
            ans = std::max(ans, g[i] - set.begin()->first);
            set.insert({f[i], i});
        }
    }
    printf("%d\n", ans);
    return 0;
} //