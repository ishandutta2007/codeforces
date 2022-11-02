// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 3691, Mod = 998244353;
int n, m, q, M[2][N], dpt[N][N], C[N][N], F[N], dp[2][N][N];
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= q; i ++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        M[0][a] = M[0][c] = M[1][b] = M[1][d] = 1;
    }
    for (int i = 0; i < N; i ++)
    {
        C[0][i] = C[i][i] = 1;
        for (int j = 1; j < i; j ++)
        {
            C[j][i] = C[j][i - 1] + C[j - 1][i - 1];
            if (C[j][i] >= Mod)
                C[j][i] -= Mod;
        }
    }
    for (int i = F[0] = 1; i < N; i ++)
        F[i] = 1LL * F[i - 1] * i % Mod;
    int len[2] = {n, m};
    for (int w = 0; w <= 1; w ++)
    {
        memset(dpt, 0, sizeof(dpt));
        dpt[0][0] = 1;
        for (int i = 1; i <= len[w]; i ++)
        {
            for (int j = 0; j <= i / 2; j ++)
            {
                dpt[i][j] = dpt[i - 1][j];
                if (j > 0 && i > 1 && !M[w][i] && !M[w][i - 1])
                {
                    dpt[i][j] += dpt[i - 2][j - 1];
                    if (dpt[i][j] >= Mod)
                        dpt[i][j] -= Mod;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= len[w]; i ++)
            if (!M[w][i]) cnt ++;
        for (int i = 0; i <= len[w]; i ++)
            for (int j = 0; j <= cnt - i * 2; j ++)
                dp[w][i][j] = dpt[len[w]][i] * 1LL * C[j][cnt - i * 2] % Mod;
    }
    int tot = 0;
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
            tot = (tot + 1LL * dp[0][i][j] * dp[1][j][i] % Mod * F[i] % Mod * F[j]) % Mod;
    printf("%d\n", tot);
    return 0;
}