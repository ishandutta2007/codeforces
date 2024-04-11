#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n, m, k;

int f[505][505][25];
int hor[505][505], ver[505][505];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    if (k % 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("-1 ");
            }
            printf("\n");
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            scanf("%d", &(hor[i][j]));
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &(ver[i][j]));
        }
    }
    for (int x = 2; x <= k; x += 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j][x] = 1000000000;
                if (i > 1) {
                    f[i][j][x] = min(f[i][j][x], f[i-1][j][x-2] + 2 * ver[i-1][j]);
                }
                if (i < n) {
                    f[i][j][x] = min(f[i][j][x], f[i+1][j][x-2] + 2 * ver[i][j]);
                }
                if (j > 1) {
                    f[i][j][x] = min(f[i][j][x], f[i][j-1][x-2] + 2 * hor[i][j-1]);
                }
                if (j < m) {
                    f[i][j][x] = min(f[i][j][x], f[i][j+1][x-2] + 2 * hor[i][j]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", f[i][j][k]);
        }
        printf("\n");
    }
    return 0;
}