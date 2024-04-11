#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, K, A, i, j;

int main()
{
    scanf("%d%d", &N, &K);
    A = (N) * (N - 1) / 2;
    if (K >= A)
        {
            printf("no solution\n");
            return 0;
        }
    fortodo(i, 1, N)
        printf("0 %d\n", i);
}