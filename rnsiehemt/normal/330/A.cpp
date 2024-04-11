#include <cstdio>

int R, C;
char g[15][15];
bool d[15][15];

int main()
{
    scanf("%d%d", &R, &C);
    for (int y = 0; y < R; y++) scanf(" %s", g[y]);
    for (int y = 0; y < R; y++) {
        bool s = false;
        for (int x = 0; x < C; x++) if (g[y][x] == 'S') s = true;
        if (!s) for (int x = 0; x < C; x++) d[y][x] = true;
    }
    for (int x = 0; x < C; x++) {
        bool s = false;
        for (int y = 0; y < R; y++) if (g[y][x] == 'S') s = true;
        if (!s) for (int y = 0; y < R; y++) d[y][x] = true;
    }
    int ans = 0;
    for (int y = 0; y < R; y++) for (int x = 0; x < C; x++) if (d[y][x]) ans++;
    printf("%d\n", ans);
}