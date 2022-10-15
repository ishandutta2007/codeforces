#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

int f[2005][5000];

int grid[2005][20];

int n, m;

int rotateR(int a)
{
    return (a >> 1) | ((a & 1) << (n-1));
}

int rotateL(int a)
{
    return ((a << 1) & (~(1 << n))) | ((a & (1 << (n-1))) >> (n-1));
}

int main()
{
    //n = 10;
    //printf("%d %d", rotateR(921), rotateL(543));
    int t;
    scanf("%d", &t);
    for (int data = 1; data <= t; data++) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < (1 << n); j++) f[i][j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &(grid[j][i]));
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < (1 << n); j++) { /* selected set for i */
                int vals = 0;
                for (int k = 0; k < n; k++) if (j & (1 << k)) vals += grid[i][k+1];
                int actj = j;
                for (int rotateamt = 0; rotateamt < n; rotateamt++) {
                    for (int k = 0; k < (1 << n); k++) {
                        if (actj & k) continue;
                        f[i][actj | k] = max(f[i][actj | k], f[i-1][k] + vals);
                    }
                    actj = rotateR(actj);
                }
            }
            //for (int j = 0; j < (1 << n); j++) { printf("%d ", f[i][j]); }
            //printf("\n");
        }
        printf("%d\n", f[m][(1<<n)-1]);
    }
    return 0;
}