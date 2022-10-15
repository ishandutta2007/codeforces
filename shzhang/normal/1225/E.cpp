#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MOD 1000000007

int rock[2005][2005];
int ssum[2005][2005];
int bsum[2005][2005]; /* 0 - first move down, 1 - first move right */
int fbsum[2005][2005][2];
int fssum[2005][2005][2];
int n, m;

char row[2005];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", row);
        for (int j = 0; j < m; j++) {
            rock[i][j+1] = (row[j] == 'R') ? 1 : 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            ssum[i][j] += ssum[i][j+1];
            if (rock[i][j]) ssum[i][j]++;
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = n; i >= 1; i--) {
            bsum[i][j] += bsum[i+1][j];
            if (rock[i][j]) bsum[i][j]++;
        }
    }
    if (rock[n][m]) {
        printf("0"); return 0;
    }
    if (n == m && n == 1) {
        printf("1"); return 0;
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", bsum[i][j]);
        }
        printf("\n");
    }*/
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            int f0 = 0, f1 = 0;
            if (rock[i][j]) bsum[i][j]--, ssum[i][j]--;
            if (i == n && j == m) {
                f0 = f1 = 1;
            } else {
                f0 = fbsum[i+1][j][1] - fbsum[n-bsum[i][j]+1][j][1];
                f0 %= MOD; f0 += MOD; f0 %= MOD;
                f1 = fssum[i][j+1][0] -fssum[i][m-ssum[i][j]+1][0];
                f1 %= MOD; f1 += MOD; f1 %= MOD;
            }

            if (i == 1 && j == 1) ans = f0 + f1;

            fbsum[i][j][0] = fbsum[i+1][j][0] + f0;
            if (fbsum[i][j][0] >= MOD) fbsum[i][j][0] -= MOD;
            fbsum[i][j][1] = fbsum[i+1][j][1] + f1;
            if (fbsum[i][j][1] >= MOD) fbsum[i][j][1] -= MOD;

            fssum[i][j][0] = fssum[i][j+1][0] + f0;
            if (fssum[i][j][0] >= MOD) fssum[i][j][0] -= MOD;
            fssum[i][j][1] = fssum[i][j+1][1] + f1;
            if (fssum[i][j][1] >= MOD) fssum[i][j][1] -= MOD;

            //printf("%d %d: %d %d\n", i, j, f0, f1);
        }
    }
    printf("%d", ans % MOD);
    return 0;
}