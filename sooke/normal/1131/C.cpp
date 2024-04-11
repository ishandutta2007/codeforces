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

int n, m, lst, a[maxN], b[maxN];
bool used[maxN];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i += 2) {
        if (!used[i]) {
            used[i] = true; b[++m] = a[i];
            lst = i;
        }
    }
    for (int i = lst == n ? n - 1 : n; i >= 2; i -= 2) {
        if (!used[i]) {
            used[i] = true; b[++m] = a[i];
        }
    }
    for (int i = 1; i <= n; i++) { printf("%d ", b[i]); }
    return 0;
}