// ItnoE
#include<bits/stdc++.h>
using namespace std;
const int N = 12, M = 2019, MXK = 1 << N;
int q, n, m, A[N][M], B[N * 2][N], P[M], MX[M], dp[MXK], dpt[MXK], dpq[MXK];
int main()
{
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d%d", &n, &m);
        memset(MX, 0, sizeof(MX));
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                scanf("%d", &A[i][j]), MX[j] = max(MX[j], A[i][j]);
        iota(P, P + m, 0);
        sort(P, P + m, [&](int i, int j){return (MX[i] > MX[j]);});
        m = min(n, m);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                B[i][j] = B[i + n][j] = A[i][P[j]];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; i ++)
        {
            memset(dpq, 0, sizeof(dpq));
            for (int j = 0; j < n; j ++)
            {
                memcpy(dpt, dp, sizeof(dp));
                for (int mask = 0; mask < (1 << n); mask ++)
                    for (int h = 0; h < n; h ++)
                        if ((mask >> h) & 1)
                            dpt[mask] = max(dpt[mask], dpt[mask ^ (1 << h)] + B[h + j][i]);
                for (int mask = 0; mask < (1 << n); mask ++)
                    dpq[mask] = max(dpq[mask], dpt[mask]);
            }
            memcpy(dp, dpq, sizeof(dp));
        }
        printf("%d\n", dp[(1 << n) - 1]);
    }
    return 0;
}