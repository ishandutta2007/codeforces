#include <bits/stdc++.h>

const int maxn = 43;

int Y, X, Q, g[maxn][maxn], up[maxn][maxn], upright[maxn][maxn][maxn][maxn], ans[maxn][maxn][maxn][maxn];

int main() {
    scanf("%d%d%d", &Y, &X, &Q);
    for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) {
        char c; scanf(" %c", &c);
        g[y][x] = c - '0';
    }
    for (int y = Y-1; y >= 0; y--) for (int x = 0; x < X; x++) {
        if (g[y][x] == 0) up[y][x] = (y+1 < Y ? up[y+1][x] + 1 : 1);
        else up[y][x] = 0;
    }
    //for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) printf("%d%c", up[y][x], " \n"[x == X-1]);
    for (int x0 = X; x0 >= 0; x0--) for (int y0 = 0; y0 < Y; y0++) {
        for (int y1 = y0+1; y1 <= Y; y1++) for (int x1 = x0+1; x1 <= X; x1++) {
            int k = std::min(up[y0][x0], y1-y0);
            upright[y0][x0][y1][x1] = upright[y0][x0+1][y0+k][x1] + k;
        }
    }
    for (int y1 = Y; y1 > 0; y1--) for (int x1 = X; x1 > 0; x1--) {
        for (int y0 = y1-1; y0 >= 0; y0--) for (int x0 = x1-1; x0 >= 0; x0--) {
            ans[y0][x0][y1][x1] = ans[y0+1][x0][y1][x1] + ans[y0][x0+1][y1][x1] - ans[y0+1][x0+1][y1][x1] + upright[y0][x0][y1][x1];
        }
    }
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a--; b--;
        printf("%d\n", ans[a][b][c][d]);
    }
}