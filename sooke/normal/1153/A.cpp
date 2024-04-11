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
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

int n, t, min = 2e9, ans;

int main() {
    n = read(); t = read();
    for (int i = 1; i <= n; i++) {
        int x = read(), y = read();
        for (int j = x; j <= t + 200000; j += y) {
            if (j >= t) {
                if (min > j - t) { min = j - t; ans = i; }
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}