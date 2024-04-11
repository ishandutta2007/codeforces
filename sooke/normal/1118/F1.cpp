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
    char c = getchar(); int x = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return f ? -x : x;
}

const int maxN = 300005;

int n, m, ans, col[maxN], cnt[3], siz[3][maxN];
std::vector<int> e[maxN];

void dfs(int u, int fa) {
    for (std::vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++) {
        int v = *it;
        if (v != fa) {
            dfs(v, u);
            for (int i = 0; i <= 2; i++) { siz[i][u] += siz[i][v]; }
            ans += siz[1][v] + cnt[2] - siz[2][v] == 0 || siz[2][v] + cnt[1] - siz[1][v] == 0;
        }
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { col[i] = read(); cnt[col[i]]++; siz[col[i]][i] = 1; }
    for (int i = 2; i <= n; i++) {
        int u = read(), v = read();
        e[u].push_back(v); e[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}