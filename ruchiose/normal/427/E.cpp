#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 1000010;

int N, M, i, j;
i64 A[MAXN], ANS, RET;

int main()
{
    scanf("%d%d", &N, &M);
    fortodo(i, 1, N) scanf("%I64d", &A[i]);
    ANS = 0;
    fortodo(i, 2, N)
        ANS += ((N - i) / M + 1) * (A[i] - A[i - 1]);
    RET = ANS;
    fortodo(i, 2, N)
        {
            ANS -= ((N - i) / M + 1) * (A[i] - A[i - 1]);
            ANS += ((i - 2) / M + 1) * (A[i] - A[i - 1]);
            RET = min(RET, ANS);
        }
    printf("%I64d\n", RET * 2);
}