// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

typedef unsigned int u32;

u32 dp_pool[233333], *dp = dp_pool + 123333;

int N;
char ch[100010];

int main()
{
    scanf("%d%s", &N, ch + 1);
    int i;
    fortodo(i, -N, N) dp[i] = 0;
    dp[0] = 1;
    fortodo(i, 1, N)
        if (ch[i] == '?')
            {
                dp++;
                for (u32* j = dp + min(i, N - i); j != dp; j--)
                    *j += *(j - 2) * 25u;
            }
        else
            *(--dp) = 0;
    cout << dp[0] << endl;
}