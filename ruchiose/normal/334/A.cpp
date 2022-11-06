#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define fordtdo(i, f, t) for (i = f; i >= t; i--)
using namespace std;

int N, B, i, j;

int main()
{
    scanf("%d", &N);
    B = B * B;
    fortodo(i, 0, N - 1)
        {
            fortodo(j, 1, (N / 2))
                printf("%d ", i * (N / 2) + j);
            fordtdo(j, (N / 2), 1)
                printf("%d%s", (N * N + 1) - (i * (N / 2) + j), (j == 1) ? "\n" : " ");
        };
    return 0;
};