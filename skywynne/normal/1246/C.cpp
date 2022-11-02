// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 2019, Mod = 1e9 + 7;
int n, m, P[N][N], T[N][N], dp[N][N][2];
int CR[N][N], CC[N][N];
char A[N][N];
inline void Add(int &a, int b)
{
    a += b;
    if (a >= Mod)
        a -= Mod;
    if (a < 0)
        a += Mod;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%s", &A[i][1]);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            CR[i][j] = CR[i][j - 1] + (A[i][j] == 'R');
            CC[i][j] = CC[i - 1][j] + (A[i][j] == 'R');
        }
    if (A[n][m] == 'R')
        return !printf("0\n");
    if (n == 1 && m == 1)
        return !printf("1\n");
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            if (i == 1 && j == 1)
                dp[i][j][0] = dp[i][j][1] = 1;
            Add(P[i][j], P[i][j - 1]);
            Add(dp[i][j][1], P[i][j]);
            Add(T[i][j], T[i - 1][j]);
            Add(dp[i][j][0], T[i][j]);

            int cnt = CR[i][m] - CR[i][j];
            Add(P[i][j + 1], dp[i][j][0]);
            Add(P[i][m - cnt + 1], -dp[i][j][0]);
            cnt = CC[n][j] - CC[i][j];
            Add(T[i + 1][j], dp[i][j][1]);
            Add(T[n - cnt + 1][j], -dp[i][j][1]);
        }
    printf("%d\n", (dp[n][m][0] + dp[n][m][1]) % Mod);
    return 0;
}