#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 200010;

i64 N, K, i, j;
i64 A[MAXN], PartialD, LS0, D;

int main()
{
    scanf("%I64d%I64d", &N, &K);
    fortodo(i, 1, N) scanf("%I64d", &A[i]);
    PartialD = LS0 = 0;
    fortodo(i, 1, N)
        {
            D = PartialD - LS0 * (N - i) * A[i];
            if (D < K)
                printf("%I64d\n", i);
            else
                {
                    PartialD += A[i] * LS0;
                    LS0++;
                }
        }
}