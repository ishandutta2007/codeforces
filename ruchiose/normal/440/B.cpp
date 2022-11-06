#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

i64 N, A[50010], S[50010];

int main()
{
    int i;
    scanf("%I64d", &N);
    fortodo(i, 1, N) scanf("%I64d", &A[i]);
    S[0] = 0;
    fortodo(i, 1, N) S[i] = S[i - 1] + A[i];
    i64 ans = 0;
    fortodo(i, 1, N - 1) ans += abs((S[N] / N * i) - S[i]);
    printf("%I64d\n", ans);
}