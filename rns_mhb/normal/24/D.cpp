#include <bits/stdc++.h>
using namespace std;

#define N 1005

int n, m, x, y;
double dp[N][N];

int main() {
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = n - 1; i >= x; i --) {
        for (int runs = 0; runs <= 50; runs ++) {
            for (int j = 1; j <= m; j ++) {
                int deg = 4;
                if (j == 1 || j == m) deg = 3;
                if (m == 1) deg = 2;
                dp[i][j] = 1 + 1.0 * (dp[i][j-1] + dp[i][j] + dp[i][j+1] + dp[i+1][j]) / deg;
            }
        }
    }
    printf("%.12lf\n", dp[x][y]);
    return 0;
}