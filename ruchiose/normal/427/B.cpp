#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 210000;

int N, T, C, i, A[MAXN], dp[MAXN];

int main()
{
    scanf("%d%d%d", &N, &T, &C);
    fortodo(i, 1, N)
        scanf("%d", &A[i]);
    dp[0] = 0;
    fortodo(i, 1, N)
        if (A[i] <= T)
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = 0;
    int ret = 0;
    fortodo(i, 1, N)
        if (dp[i] >= C)
            ret++;
    printf("%d\n", ret);
}