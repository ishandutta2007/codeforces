#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, i, j, A[101][101];

int main()
{
    scanf("%d%d", &N, &M);
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            scanf("%d", &A[i][j]);
    do
        {
            if (N % 2) break;
            fortodo(i, 1, N / 2)
                fortodo(j, 1, M)
                    if (A[i][j] != A[N + 1 - i][j])
                        goto toe;
            N /= 2; 
        }
    while (1);
toe:printf("%d\n", N);
}