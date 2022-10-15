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

const int N = 200005;

int n, k, ans, a[N];

bool check(int x) {
    for (int i = x, j = n; i >= 1; i--, j--) {
        if (j <= x) { return false; }
        if (a[i] + k > a[j]) { return false; }
    }
    return true;
}

int main() {
    n = read(); k = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    std::sort(a + 1, a + n + 1);
    for (int l = 0, r = n, mid; l <= r; ) {
        mid = l + r >> 1;
        if (check(mid)) { ans = mid; l = mid + 1; }
        else { r = mid - 1; }
    }
    printf("%d\n", ans);
    return 0;
}