#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, i, j;
int S[101], _S[21];
char opt[21][2];
int oper[21], oid, ot, oer;
int dp[1048576];
int bitcnt[1048576];

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d", &S[i]);
    scanf("%d", &M);
    fortodo(i, 1, M) scanf("%s%d", opt[i] + 1, &oper[i]);
    int field = (1 << M) - 1;
    sort(S + 1, S + N + 1);
    fortodo(i, 0, M - 1) _S[i] = S[N - i];
    bitcnt[0] = dp[0] = 0;
    fortodo(i, 1, field)
        {
            bitcnt[i] = bitcnt[i - (i & (-i))] + 1;
            oid = M + 1 - bitcnt[i];
            ot = (opt[oid][1] == 'p') ? 1 : 0;
            oer = oper[oid];
            if (oer == 1)
                {
                    dp[i] = -0x3FFFFFFF;
                    fortodo(j, 0, M - 1)
                        if ((1 << j) & i)
                            dp[i] = max(dp[i], dp[i - (1 << j)] + ot * _S[j]);
                }
            else
                {
                    dp[i] = 0x3FFFFFFF;
                    fortodo(j, 0, M - 1)
                        if ((1 << j) & i)
                            dp[i] = min(dp[i], dp[i - (1 << j)] - ot * _S[j]);
                }
        }
    printf("%d\n", dp[field]);
}