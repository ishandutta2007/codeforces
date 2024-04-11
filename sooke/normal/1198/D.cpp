#include <bits/stdc++.h>

const int N = 51;

int n, a[N][N], sum[N][N], f[N][N][N][N];
bool vis[N][N][N][N];
char str[N];

inline int get(int x, int y, int r, int c) {
    int res = sum[r][c];
    if (x) { res -= sum[x - 1][c]; }
    if (y) { res -= sum[r][y - 1]; }
    if (x && y) { res += sum[x - 1][y - 1]; }
    return res;
}

int solve(int x, int y, int r, int c) {
    if (x > r || y > c || get(x, y, r, c) == 0) { return 0; }
    int lx = r - x + 1, ly = c - y + 1;
    if (get(x, y, r, c) == lx * ly) { return std::max(lx, ly); }
    if (vis[x][y][r][c]) { return f[x][y][r][c]; }
    int res = std::max(lx, ly); vis[x][y][r][c] = true;
    for (int i = x; i < r; i++) {
        res = std::min(res, solve(x, y, i, c) + solve(i + 1, y, r, c));
    }
    for (int i = y; i < c; i++) {
        res = std::min(res, solve(x, y, r, i) + solve(x, i + 1, r, c));
    }
    return f[x][y][r][c] = res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        for (int j = 0; j < n; j++) {
            sum[i][j] = a[i][j] = str[j] == '#';
            if (i) { sum[i][j] += sum[i - 1][j]; }
            if (j) { sum[i][j] += sum[i][j - 1]; }
            if (i && j) { sum[i][j] -= sum[i - 1][j - 1]; }
        }
    }
    printf("%d\n", solve(0, 0, n - 1, n - 1));
    return 0;
}