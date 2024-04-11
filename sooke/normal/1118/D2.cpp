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
    char c = getchar(); int x = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return f ? -x : x;
}

const int maxN = 200005;

int n, m, ans = -1, a[maxN];

bool cmp(int x, int y) { return x > y; }

bool check(int x) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) { sum += std::max(0, a[i] - (i - 1) / x); }
    return sum >= m;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    std::sort(a + 1, a + n + 1, cmp);
    for (int l = 1, r = n, mid; l <= r; ) {
        mid = l + r >> 1;
        if (check(mid)) { r = mid - 1; ans = mid; } else { l = mid + 1; }
    }
    printf("%d\n", ans);
    return 0;
}