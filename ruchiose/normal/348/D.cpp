#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const i64 MOD = 1000000007;
const int MAXN = 3010;

int N, M, i, j;
bool mv[MAXN][MAXN];
char S[MAXN];
i64 dp1[MAXN][MAXN], dp2[MAXN][MAXN];

int main()
{
    scanf("%d%d", &N, &M);
    fortodo(i, 1, N)
        {
            scanf("%s", S + 1);
            fortodo(j, 1, M) mv[i][j] = (S[j] == '.');
        }
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            dp1[i][j] = dp2[i][j] = 0;
    dp1[1][1] = dp2[1][1] = 1;
    fortodo(i, 1, N)
        fortodo(j, 2, M)
            if (mv[i][j])
                {
                    dp1[i][j] = dp1[i][j - 1];
                    if (i > 1) dp1[i][j] += dp1[i - 1][j];
                    dp1[i][j] %= MOD;
                }
    fortodo(i, 2, N)
        fortodo(j, 1, M)
            if (mv[i][j])
                {
                    dp2[i][j] = dp2[i - 1][j];
                    if (j > 1) dp2[i][j] += dp2[i][j - 1];
                    dp2[i][j] %= MOD;
                }
    i64 ans = dp1[N - 1][M] * dp2[N][M - 1] - dp1[N][M - 1] * dp2[N - 1][M];
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}