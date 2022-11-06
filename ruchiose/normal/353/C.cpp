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

const int MAXN = 100010;

int N, A[MAXN], Suf[MAXN];
char S[MAXN];

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    Suf[0] = 0;
    fortodo(i, 1, N) Suf[i] = Suf[i - 1] + A[i];
    scanf("%s", S + 1);
    int ans = 0, tmp = 0;
    for (i = N; i; i--)
        if (S[i] == '1')
            {
                ans = max(ans, tmp + Suf[i - 1]);
                tmp += A[i];
            }
    ans = max(ans, tmp);
    printf("%d\n", ans);
}