#include <cstdio>
#include <algorithm>

using namespace std;

bool query(int x1, int y1, int x2, int y2)
{
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans == 1;
}

bool grid1[55][55];
bool grid2[55][55];
bool dp1[55][55][55][55];
bool dp2[55][55][55][55];
int n;

void dp(bool grid[55][55], bool dp[55][55][55][55])
{
    for (int dist = 0; dist <= 2 * n - 2; dist++) {
        for (int x1 = 1; x1 <= n; x1++) {
            for (int y1 = 1; y1 <= n; y1++) {
                for (int x2 = x1; x2 <= min(n, x1 + dist); x2++) {
                    int y2 = y1 + dist - x2 + x1;
                    if (y2 > n) continue;
                    dp[x1][y1][x2][y2] = (grid[x1][y1] == grid[x2][y2] &&
                        (dist < 2 || dp[x1+1][y1][x2-1][y2] || dp[x1+1][y1][x2][y2-1] ||
                         dp[x1][y1+1][x2-1][y2] || dp[x1][y1+1][x2][y2-1]));
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    grid1[1][1] = 1;
    for (int x = 3; x <= n; x += 2) {
        grid1[x][1] = query(x-2, 1, x, 1) ? grid1[x-2][1] : !grid1[x-2][1];
    }
    for (int x = 2; x <= n; x += 2) {
        grid1[x][2] = query(x-1, 1, x, 2) ? grid1[x-1][1] : !grid1[x-1][1];
    }
    for (int x = 1; x <= n; x++) {
        for (int y = 3; y <= n; y++) {
            if ((x + y) & 1) continue;
            grid1[x][y] = query(x, y-2, x, y) ? grid1[x][y-2] : !grid1[x][y-2];
        }
    }
    for (int x = 3; x <= n; x += 2) {
        grid1[x][2] = query(x-2, 2, x, 2) ? grid1[x-2][2] : !grid1[x-2][2];
    }
    for (int x = 2; x <= n; x += 2) {
        grid1[x][1] = query(x, 1, x+1, 2) ? grid1[x+1][2] : !grid1[x+1][2];
    }
    for (int x = 1; x <= n; x++) {
        for (int y = 3; y <= n; y++) {
            if (!((x + y) & 1)) continue;
            grid1[x][y] = query(x, y-2, x, y) ? grid1[x][y-2] : !grid1[x][y-2];
        }
    }
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            if ((x + y) & 1) {
                grid2[x][y] = !grid1[x][y];
            } else {
                grid2[x][y] = grid1[x][y];
            }
        }
    }
    dp(grid1, dp1);
    dp(grid2, dp2);
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", grid1[i][j] ? 1 : 0);
        }
        printf("\n");
    }*/
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= n; y1++) {
            for (int x2 = x1; x2 <= n; x2++) {
                for (int y2 = y1; y2 <= n; y2++) {
                    if (x2 - x1 + y2 - y1 <= 1) continue;
                    if (dp1[x1][y1][x2][y2] != dp2[x1][y1][x2][y2]) {
                        bool val = query(x1, y1, x2, y2);
                        printf("!\n");
                        if (val == dp1[x1][y1][x2][y2]) {
                            for (int i = 1; i <= n; i++) {
                                for (int j = 1; j <= n; j++) {
                                    printf("%d", grid1[i][j] ? 1 : 0);
                                }
                                printf("\n");
                            }
                        } else {
                            for (int i = 1; i <= n; i++) {
                                for (int j = 1; j <= n; j++) {
                                    printf("%d", grid2[i][j] ? 1 : 0);
                                }
                                printf("\n");
                            }
                        }
                        fflush(stdout);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}