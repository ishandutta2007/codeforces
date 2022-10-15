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

const int maxN = 100005;

int n, a[maxN], b[maxN];
long long ans;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); b[i] = read(); }
    for (int i = 1; i < n; i++) { ans -= a[i] == b[i]; }
    for (int i = 1; i <= n; i++) { ans += std::max(0, std::min(a[i], b[i]) + 1 - std::max(a[i - 1], b[i - 1])); }
    std::cout << ans;
    return 0;
}