#include <bits/stdc++.h>
using namespace std;
#define inf 1e9
#define N 31000
#define M 210
int f[N][M][2], g[N][M][2];
int main() {
    int n, K, val;
    //freopen("1.in", "r", stdin);
    scanf("%d%d", &n, &K);
    for(int i = 1; i <= K; i ++) for(int j = 0; j < 2; j ++) f[0][i][j] = g[0][i][j] = -inf;
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &val);
        for(int j = 1; j <= K; j ++) {

            int x = 2;
            if(j == 1 || j == K) x --;
            f[i][j][0] = max(f[i - 1][j][0] + x * val, g[i - 1][j - 1][1] + x * val);
            f[i][j][1] = max(f[i - 1][j][1] - x * val, g[i - 1][j - 1][0] - x * val);
            g[i][j][0] = max(g[i - 1][j][0], f[i][j][0]);
            g[i][j][1] = max(g[i - 1][j][1], f[i][j][1]);
            if(j > 1 && j < K) {
                g[i][j][0] = max(g[i][j][0], g[i - 1][j - 1][0]);
                g[i][j][1] = max(g[i][j][1], g[i - 1][j - 1][1]);
            }
            //printf("%d %d %d %d %d %d\n", i, j, f[i][j][0], f[i][j][1], g[i][j][0], g[i][j][1]);
        }
    }
    printf("%d\n", max(g[n][K][0], g[n][K][1]));
}