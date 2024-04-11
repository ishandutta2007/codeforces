#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

int n, m;
int s = 0;
int g[20][20];

int pw[20];

int d[1 << 15];

int calc(int mask)
{
    if (d[mask] != -1) return d[mask];
    int bits = 0;
    for (int i = 0; i < n; i ++)
        if ((mask & (1 << i)) == 0 && pw[i] % 2 == 1)
            bits ++;
    if (bits == 0)
    {
        d[mask] = 0;
        return 0;
    }

    d[mask] = 1000000000;
    for (int i = 0; i < n; i ++)
        for (int j = i + 1; j < n; j ++)
            if ((mask & (1 << i)) == 0 && (mask & (1 << j)) == 0 && pw[i] % 2 == 1 && pw[j] % 2 == 1)
                d[mask] = min(d[mask], calc(mask | (1 << i) | (1 << j)) + g[i][j]);
    return d[mask];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            g[i][j] = 1000000000;
    for (int i = 1; i <= m; i ++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        x --, y --;
        g[x][y] = min(g[x][y], w);
        g[y][x] = min(g[y][x], w);
        pw[x] ++, pw[y] ++;
        s += w;
    }

    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            for (int k = 0; k < n; k ++)
                g[j][k] = min(g[j][k], g[j][i] + g[i][k]);

    for (int i = 1; i < n; i ++)
        if (g[0][i] == 1000000000 && pw[i] != 0)
        {
            printf("-1\n");
            return 0;
        }

    for (int i = 0; i < (1 << n); i ++)
        d[i] = -1;
    s += calc(0);
    printf("%d\n", s);
    return 0;
}