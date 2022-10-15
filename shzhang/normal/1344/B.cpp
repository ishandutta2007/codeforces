#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

#define ll long long

int n, m;

char s[1005];
bool black[1005][1005];
int Left[1005][1005][2];
int Right[1005][1005][2];
int up[1005][1005][2];
int down[1005][1005][2];
bool south[1005][1005];
int row[1005], col[1005];
bool vis[1005][1005];

void dfs(int r, int c)
{
    if (vis[r][c]) return;
    if (!black[r][c]) return;
    vis[r][c] = true;
    dfs(r+1, c); dfs(r-1, c);
    dfs(r, c-1); dfs(r, c+1);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            black[i][j] = (s[j] =='#');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (black[i][j]) {
                Left[i][j][1] = Left[i][j-1][1] + 1;
                up[i][j][1] = up[i-1][j][1] + 1;
            }
            Left[i][j][0] = Left[i][j-1][0] + black[i][j];
            up[i][j][0] = up[i-1][j][0] + black[i][j];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (black[i][j]) {
                Right[i][j][1] = Right[i][j+1][1] + 1;
                down[i][j][1] = down[i+1][j][1] + 1;
            }
            Right[i][j][0] = Right[i][j+1][0] + black[i][j];
            down[i][j][0] = down[i+1][j][0] + black[i][j];
        }
    }
    //for (int i = 1; i <= 1000; i++) top[i] = mleft[i] = 100000;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (Left[i][j][0] == Left[i][j][1] &&
                Right[i][j][0] == Right[i][j][1] &&
                up[i][j][0] == up[i][j][1] &&
                down[i][j][0] == down[i][j][1]) {
                    south[i][j] = true;
                    row[i]++; col[j]++;
                    /*top[j] = min(top[j], i);
                    bot[j] = max(bot[j], i);
                    mleft[i] = min(mleft[i], j);
                    mright[i] = max(mright[i], j);*/
                    //printf("!");
                } else {
                    //printf(".");
                }
        }
        //printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        if (!row[i]) {
            printf("-1"); return 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!col[i]) {
            printf("-1"); return 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (black[i][j] && !vis[i][j]) {
                dfs(i, j); ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}