// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
#define mp make_pair
using namespace std;

const int MOD = 1000000007;

int N, i, j, P[1001];
int DP[1001];

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d", &P[i]);
    fortodo(i, 1, N)
        {
            DP[i] = 2; // thru Pi & Leave
            fortodo(j, P[i], i - 1)
                DP[i] = (DP[i] + DP[j]) % MOD;
        }
    int ANS = 0;
    fortodo(i, 1, N)
        ANS = (ANS + DP[i]) % MOD;
    printf("%d\n", ANS);
    return 0;
}