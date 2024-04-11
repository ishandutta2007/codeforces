#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 30005;

int n, m, p, num, l[maxN], r[maxN], a[maxN], table[maxN], lst[maxN], cnt[maxN], f[maxN];
long long ans[maxN];
std::vector<int> vec[maxN];

int main() {
    n = read(); p = read(); f[1] = f[2] = 1 % p;
    for (int i = 1; i <= n; i++) { table[++num] = a[i] = read(); }
    for (int i = 3; i <= n; i++) { f[i] = (f[i - 1] + f[i - 2]) % p; }
    std::sort(table + 1, table + num + 1); num = std::unique(table + 1, table + num + 1) - table - 1;
    for (int i = 1; i <= n; i++) { vec[std::lower_bound(table + 1, table + num + 1, a[i]) - table].push_back(i); }
    m = read();
    for (int i = 1; i <= m; i++) { l[i] = read(); r[i] = read(); }
    for (int i = 1, x; i <= num; i++) {
        x = table[i] % p;
        for (std::vector<int> ::iterator it = vec[i].begin(); it != vec[i].end(); it++) {
            for (int j = 1; j <= m; j++) {
                if (l[j] <= *it && *it <= r[j] && i != lst[j]) { lst[j] = i; ans[j] += x * f[++cnt[j]]; }
            }
        }
    }
    for (int i = 1; i <= m; i++) { printf("%lld\n", ans[i] % p); }
    return 0;
}