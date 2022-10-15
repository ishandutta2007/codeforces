#include <bits/stdc++.h>

inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

const int N = 1e3 + 5;

int n, m, q, dis[N][N];
bool ok[N][N];
char c[N][N];

void bfs() {
    std::queue<std::pair<int, int>> que;
    memset(dis, 60, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 1 || y < 1 || x > n || y > m) { continue; }
                if (c[i][j] == c[x][y]) { ok[i][j] = ok[x][y] = true; }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ok[i][j]) {
                dis[i][j] = 0;
                que.push({i, j});
            }
        }
    }
    for (; !que.empty(); que.pop()) {
        int i = que.front().first, j = que.front().second;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 1 || y < 1 || x > n || y > m) { continue; }
            if (dis[x][y] > dis[i][j] + 1) {
                dis[x][y] = dis[i][j] + 1;
                que.push({x, y});
            }
        }
    }
}

int main() {
    n = read(); m = read(); q = read();
    for (int i = 1; i <= n; i++) { scanf("%s", c[i] + 1); }
    bfs();
    for (; q; q--) {
        int x = read(), y = read();
        long long t = read();
        if (t < dis[x][y] || dis[x][y] > 1e8) { printf("%d\n", c[x][y] - '0'); continue; }
        printf("%lld\n", (c[x][y] - '0') ^ ((t - dis[x][y]) & 1));
    }
    return 0;
}