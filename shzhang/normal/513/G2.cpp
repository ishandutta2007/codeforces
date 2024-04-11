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

int ways[35][35][35][35];
double trans[35][35][35][35];
double f[250][35][35];

int n, k;
int perm[105];
int pos[105];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", perm + i);
        pos[perm[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            for (int l = 1; l <= n; l++) {
                for (int r = l; r <= n; r++) {
                    int newi = (l <= i && i <= r ? r - (i-l) : i);
                    int newj = (l <= j && j <= r ? r - (j-l) : j);
                    ways[i][j][newi][newj]++;
                }
            }
            for (int K = 1; K <= n; K++) {
                for (int l = 1; l <= n; l++) {
                    if (K == l) continue;
                    trans[i][j][K][l] = (double)ways[i][j][K][l] / (double)((n * (n+1)) / 2);
                }
            }
        }
    }
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (a > b) {
                f[0][a][b] = 1.0;
            } else {
                f[0][a][b] = 0.0;
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                if (a == b) continue;
                for (int c = 1; c <= n; c++) {
                    for (int d = 1; d <= n; d++) {
                        f[i][a][b] += f[i-1][c][d] * trans[a][b][c][d];
                    }
                }
            }
        }
    }
    double ans = 0.0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans += f[k][pos[i]][pos[j]];
        }
    }
    printf("%.15f", ans);
    return 0;
}