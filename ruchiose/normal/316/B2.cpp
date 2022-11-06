// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<bitset>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 1010;

int N, x, l;
int F[MAXN], C[MAXN];

bitset<MAXN> dp;

int Find(int x)
{
    return F[x] = ((F[x] == x) ? x : Find(F[x]));
}

int main()
{
    scanf("%d%d", &N, &x);
    int i;
    fortodo(i, 1, N)
        {
            scanf("%d", &F[i]);
            if (F[i] == 0) F[i] = i;
        }
    for (i = x, l = 0; F[i] != i; i = F[i], l++);
    fortodo(i, 1, N) C[i] = 0;
    fortodo(i, 1, N)
        if ((Find(i) == i) && (Find(x) != i))
            {
                int j, sz = 0;
                fortodo(j, 1, N)
                    if (Find(j) == i)
                        sz++;
                C[sz]++;    
            }
    dp.reset();
    dp.set(l + 1);
    fortodo(i, 1, N)
        for (int j = C[i]; j; j--)
            dp |= dp << i;
    fortodo(i, 1, N)
        if (dp[i])
            printf("%d\n", i);
}