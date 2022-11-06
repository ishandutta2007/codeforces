// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int primes[17] = 
{2, 3, 5, 7, 11, 
 13, 17, 19, 23, 29, 
 31, 37, 41, 43, 47,
 53, 59};

int N, A[110], dp[110][1<<17], s[60];
const int Field = 0x1FFFF;

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 0, N - 1) scanf("%d", &A[i]);
    fortodo(i, 1, 59) s[i] = 0;
    fortodo(i, 0, 16)
        for (int j = primes[i]; j < 60; j += primes[i])
            s[j] |= 1 << i;
    int j, k;
    fortodo(i, 0, N)
        fortodo(j, 0, Field)
            dp[i][j] = 0x23333333;
    dp[0][0] = 0;
    fortodo(i, 0, N - 1)
        fortodo(k, 1, 59)
            for (int f = j = (Field ^ s[k]); ; j = (j - 1) & f)
                {
                    dp[i + 1][j ^ s[k]] = min(dp[i + 1][j ^ s[k]], dp[i][j] + abs(A[i] - k));
                    if (j == 0) break;
                }
    vector<int> RET;
    RET.clear();
    int ans = 0x23333333;
    int lv, u = 0;
    fortodo(i, 0, Field)
        if (ans > dp[N][i])
            {
                ans = dp[N][i];
                u = i;
            }
    for (lv = N - 1; lv >= 0; lv--)
        fortodo(k, 1, 59)
            if (((u & s[k]) == s[k]) && (dp[lv][u ^ s[k]] + abs(k - A[lv]) == dp[lv + 1][u]))
                {
                    RET.push_back(k);
                    u ^= s[k];
                    break;
                }
    fortodo(i, 1, N) printf("%d%s", RET[N - i], (i == N) ? "\n" : " ");
}