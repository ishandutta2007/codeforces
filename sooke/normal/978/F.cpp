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
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 200005;

int n, m, unin, table[maxN], a[maxN];
std::vector<int> vec[maxN];

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) { table[++unin] = a[i] = read(); }
    std::sort(table + 1, table + unin + 1);
    for (; m; m--) { int u = read(), v = read(); vec[u].push_back(v), vec[v].push_back(u); }
    for (int i = 1; i <= n; i++) {
        int ans = std::lower_bound(table + 1, table + unin + 1, a[i]) - table - 1;
        for (int j = 0; j < (int)vec[i].size(); j++) {
            if (a[vec[i][j]] < a[i]) { ans--; }
        }
        printf("%d ", ans);
    }
    return 0;
}

// .a[w3.5[tge.sa[fl.[sdl[fksp[d]