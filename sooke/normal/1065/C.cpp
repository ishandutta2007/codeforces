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
#define int long long

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 200005;

int n, m, min = 1e9, max, ans, a[maxN], cnt[maxN];

signed main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); cnt[a[i]]++; min = std::min(min, a[i]); max = std::max(max, a[i]); }
    if (min == max) { printf("0\n"); return 0; }
    for (int i = max - 1; i; i--) { cnt[i] += cnt[i + 1]; }
    for (int i = 1; i <= max; i++) { cnt[i] += cnt[i - 1]; }
    for (int i = max, j = max; i != min; ) {
        while (j > min && cnt[i] - cnt[j - 1] <= m) { j--; } j++;
        ans++; i = j - 1;
    }
    printf("%I64d\n", ans);
    return 0;
} ///