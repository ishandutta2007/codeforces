#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 100010;
const int MAXM = 100010;
const int MAXP = 110;
const i64 INF = (i64)(1e+18);

int N, M, P;
int D[MAXN], T[MAXM], i;
i64 dp[MAXP][MAXM], sum[MAXM];

void dodp(int lyr, int L, int R, int opt_L, int opt_R)
{
    int B = (L + R) / 2;
    int i, opt = 0, t_R = min(opt_R, B - 1);
    dp[lyr][B] = INF;
    fortodo(i, opt_L, t_R)
        {
            i64 c = dp[lyr - 1][i] + /*max(*/(i64)T[B]/*, 0ll)*/ * (B - i) - (sum[B] - sum[i]);
            if (c < dp[lyr][B])
                {
                    dp[lyr][B] = c;
                    opt = i;
                }
        }
    if (L < B) dodp(lyr, L, B - 1, opt_L, opt);
    if (B < R) dodp(lyr, B + 1, R, opt, opt_R);
}

int main()
{
    scanf("%d%d%d", &N, &M, &P);
    D[1] = 0;
    fortodo(i, 2, N)
        {
            scanf("%d", &D[i]);
            D[i] += D[i - 1];
        }
    fortodo(i, 1, M)
        {
            int h, t;
            scanf("%d%d", &h, &t);
            T[i] = t - D[h];
        }
    sort(T + 1, T + M + 1);
    sum[0] = 0;
    fortodo(i, 1, M) sum[i] = sum[i - 1] + T[i];
    fortodo(i, 0, M)
        dp[0][i] = INF;
    dp[0][0] = 0;
    fortodo(i, 1, P)
        {
            dp[i][0] = 0;
            dodp(i, 1, M, 0, M - 1);
        }
    cout << dp[P][M] << endl;
}