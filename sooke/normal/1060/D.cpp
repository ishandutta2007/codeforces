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

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 100005;

int n, l[maxN], r[maxN];
long long ans;

int main() {
    n = read(); ans = n;
    for (int i = 1; i <= n; i++) { l[i] = read(), r[i] = read(); }
    std::sort(l + 1, l + n + 1); std::sort(r + 1, r + n + 1);
    for (int i = 1; i <= n; i++) { ans += std::max(l[i], r[i]); }
    std::cout << ans << std::endl;
    return 0;
}

// Sooke