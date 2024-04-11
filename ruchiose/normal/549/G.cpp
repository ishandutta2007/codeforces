// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
using namespace std;

int N, A[233333];

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 1, N)
        {
            int a;
            scanf("%d", &a);
            A[i] = a + i;
        }
    sort(A + 1, A + N + 1);
    fortodo(i, 2, N)
        if (A[i - 1] == A[i])
            {
                printf(":(\n");
                return 0;
            }
    fortodo(i, 1, N)
        printf("%d%s", A[i] - i, (i == N) ? "\n" : " ");
    return 0;
}