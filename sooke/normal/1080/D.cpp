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

typedef long long lol;

inline lol read() {
    char c = getchar(); lol n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

lol n, m, p, l, r, ans;

int main() {
    for (int tn = read(); tn; tn--) {
        n = read(); m = read(); ans = -1; l = r = 0;
        if (n >= 32) { printf("YES %I64d\n", n - 1); continue; }
        for (int i = n; ~i; i--) {
            l = (1ll << (n - i + 1)) - n + i - 2;
            if (l <= m && m <= l + r) { ans = i; break; }
            r += ((1ll << (n - i + 2)) - 3) * ((1ll << (i * 2 - 2)) - 1) / 3;
        }
        if (~ans) { printf("YES %I64d\n", ans); } else { printf("NO\n"); }
    }
    return 0;
} //