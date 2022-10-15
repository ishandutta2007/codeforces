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

const int N = 300005;

int n, m, a[N], f[N];
std::vector<int> son[N];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    for (int i = 2; i <= n; i++) { son[read()].push_back(i); }
    for (int i = n; i; i--) {
        if (son[i].empty()) { m++; f[i] = 1; } else {
            if (a[i] == 0) {
                for (auto j : son[i]) { f[i] += f[j]; }
            } else {
                f[i] = 1e9;
                for (auto j : son[i]) { f[i] = std::min(f[i], f[j]); }
            }
        }
    }
    printf("%d\n", m + 1 - f[1]);
    return 0;
}