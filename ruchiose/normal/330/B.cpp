#include<iostream>
#include<cstdio>
#include<cstdlib>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, i, j, U, V;
bool BANNED[1001];

int main()
{
    scanf("%d%d", &N, &M);
    fortodo(i, 1, N) BANNED[i] = false;
    fortodo(i, 1, M)
        {
            scanf("%d%d", &U, &V);
            BANNED[U] = BANNED[V] = true;
        };
    fortodo(i, 1, N)
        if (!BANNED[i])
            {
                printf("%d\n", N - 1);
                fortodo(j, 1, N)
                    if (i != j)
                        printf("%d %d\n", i, j);
                return 0;
            };
};