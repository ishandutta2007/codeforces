#include<bits/stdc++.h>
using namespace std;
const int N = 16, MXN = 10004;
int n, m, A[N][MXN], E[N][N], dp[1 << N][N][N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    if (n == 1)
    {
        int Mn = INT_MAX;
        for (int i = 0; i < m - 1; i++)
            Mn = min(Mn, abs(A[0][i] - A[0][i + 1]));
        return !printf("%d", Mn);
    }
    memset(E, 63, sizeof(E));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int h = 0; h < m; h++)
                E[i][j] = min(E[i][j], abs(A[i][h] - A[j][h]));
    for (int mask = 1; mask < (1 << n); mask ++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && (mask >> i & 1) && (mask >> j & 1))
                {
                    if (__builtin_popcount(mask) == 2)
                        dp[mask][i][j] = E[i][j];
                    else
                        for (int h = 0; h < n; h++)
                            if (h != i && h != j && (mask >> h & 1))
                                dp[mask][i][j] = max(dp[mask][i][j], min(E[i][h], dp[mask ^ (1 << i)][h][j]));
                }
    int Mx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                int Mn = dp[(1 << n) - 1][i][j];
                for (int h = 0; h < m - 1; h++)
                    Mn = min(Mn, abs(A[i][h + 1] - A[j][h]));
                Mx = max(Mx, Mn);
            }
    return !printf("%d", Mx);
}