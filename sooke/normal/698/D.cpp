#include <bits/stdc++.h>

const int N = 1e3 + 5;

int m, n, ans, p[N], id[N];
bool ok[N], vis[N];
std::vector<int> e[8][N];

struct Point {
    int x, y;
} a[N], b[N];

inline bool straight(Point u, Point v, Point w) {
    if (1ll * (v.x - u.x) * (w.y - v.y) != 1ll * (v.y - u.y) * (w.x - v.x)) { return false; }
    if (!(std::min(u.x, w.x) <= v.x && v.x <= std::max(u.x, w.x))) { return false; }
    if (!(std::min(u.y, w.y) <= v.y && v.y <= std::max(u.y, w.y))) { return false; }
    return true;
}

void dfs(int &k, int i) {
    if (k >= m) { return; }
    int _p = p[k];
    for (auto j : e[_p][i]) {
        if (!vis[j]) {
            dfs(++k, j);
            if (k >= m) { return; }
        }
    }
    id[_p] = i; vis[i] = true;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) { scanf("%d%d", &a[i].x, &a[i].y); }
    for (int i = 0; i < n; i++) { scanf("%d%d", &b[i].x, &b[i].y); }
    for (int k = 0; k < m; k++) {
        p[k] = k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) { continue; }
                if (straight(a[k], b[j], b[i])) {
                    e[k][i].push_back(j);
                    if (e[k][i].size() >= m) { break; }
                }
            }
        }
    }
    do {
        for (int i = 0; i < n; i++) {
            if (ok[i]) { continue; }
            int k = 0; dfs(k, i); ok[i] = k < m;
            for (k = 0; k < m; k++) { vis[id[k]] = false; }
        }
    } while (std::next_permutation(p, p + m));
    for (int i = 0; i < n; i++) { ans += ok[i]; }
    printf("%d\n", ans);
    return 0;
}