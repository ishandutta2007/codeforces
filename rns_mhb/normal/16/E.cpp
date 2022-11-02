#include <bits/stdc++.h>
using namespace std;

#define N 262150
#define K 20

int n;
int bit[N];
int c[K];
double p[K][K];
double dp[K][N], f[K][N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i < N; i ++) bit[i] = bit[i>>1] + (i & 1);
    for (int i = 1; i < K; i ++) c[i] = i * (i - 1) / 2;
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++) scanf("%lf", &p[i][j]);
    for (int mask = 1; mask < (1 << n); mask ++)
    for (int i = 0; i < n; i ++) {
        if (!(mask & (1 << i))) {
            dp[i][mask] = 0;
            continue;
        }
        if (!(mask ^ (1 << i))) {
            dp[i][mask] = 1;
            f[i][mask] = 0;
            continue;
        }
        dp[i][mask] = 0;
        f[i][mask] = 0;
        for (int j = 0; j < n; j ++) if (j != i && (mask & (1 << j))) {
            dp[i][mask] += 1.0 / c[bit[mask]] * p[i][j] * dp[i][mask^(1<<j)];
            dp[i][mask] += f[j][mask^(1<<i)] * dp[i][mask^(1<<j)] * c[bit[mask]-1] / c[bit[mask]];
            f[i][mask] += 1.0 / c[bit[mask]] * p[j][i];
        }
    }
    for (int i = 0; i < n; i ++) printf("%.12lf ", dp[i][(1<<n)-1]);
    return 0;
}