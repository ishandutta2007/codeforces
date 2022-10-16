#include <bits/stdc++.h>

const int N = 1e3 + 5;

int n, m, ans, c[N][N];
int lx, rx, ly, ry;
char str[N];
bool vis[N][N];

void dfs(int x, int y) {
    if (!vis[x][y]) { return; }
    lx = std::min(lx, x); rx = std::max(rx, x);
    ly = std::min(ly, y); ry = std::max(ry, y);
    vis[x][y] = false;
    dfs(x - 1, y); dfs(x + 1, y);
    dfs(x, y - 1); dfs(x, y + 1);
}

bool check() {
    bool flagi = false;
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == 1) { flag = false; break; }
        }
        if (flag) { flagi = true; break; }
    }
    bool flagj = false;
    for (int i = 1; i <= m; i++) {
        bool flag = true;
        for (int j = 1; j <= n; j++) {
            if (c[j][i] == 1) { flag = false; break; }
        }
        if (flag) { flagj = true; break; }
    }
    if (flagi && !flagj) { return false; }
    if (flagj && !flagi) { return false; }
    return true;
}

bool checkk() {
    for (int i = 1; i <= n; i++) {
        int opt = 0;
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == 1) {
                if (opt <= 1) {
                    opt = 1;
                } else {
                    return false;
                }
            } else {
                if (opt == 0) {
                    opt = 0;
                } else {
                    opt = 2;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int opt = 0;
        for (int j = 1; j <= n; j++) {
            if (c[j][i] == 1) {
                if (opt <= 1) {
                    opt = 1;
                } else {
                    return false;
                }
            } else {
                if (opt == 0) {
                    opt = 0;
                } else {
                    opt = 2;
                }
            }
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str + 1);
        for (int j = 1; j <= m; j++) {
            vis[i][j] = c[i][j] = (str[j] == '#');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j]) {
                lx = rx = i; ly = ry = j;
                ans++; dfs(i, j);
            }
        }
    }
    if (!check()) { printf("-1\n"); return 0; }
    if (!checkk()) { printf("-1\n"); return 0; }
    printf("%d\n", ans);
    return 0;
}