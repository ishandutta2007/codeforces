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

const int maxN = 100005;

int n, m, nxt[maxN], siz[maxN];
long long ans;
bool vis[maxN];

bool cmp(int x, int y) { return x > y; }

int dfs(int u) {
    if (vis[u]) { return 0; }
    vis[u] = true; return dfs(nxt[u]) + 1;
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> nxt[i]; }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) { siz[++m] = dfs(i); }
    }
    std::sort(siz + 1, siz + m + 1, cmp);
    if (m == 1) { ans += 1ll * siz[1] * siz[1]; } else {
        ans += 1ll * (siz[1] + siz[2]) * (siz[1] + siz[2]);
        for (int i = 3; i <= m; i++) { ans += 1ll * siz[i] * siz[i]; }
    }
    std::cout << ans;
    return 0;
} ///