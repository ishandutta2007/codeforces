#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
using namespace std;

int N, C, i, j, X[101], ANS;

int main()
{
    scanf("%d%d", &N, &C);
    fortodo(i, 1, N) scanf("%d", &X[i]);
    ANS = C;
    fortodo(i, 2, N) ANS = max(ANS, X[i - 1] - X[i]);
    printf("%d\n", ANS - C);
};