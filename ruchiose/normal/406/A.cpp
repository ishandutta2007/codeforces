#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, Q, Aij, Unu, i, j, u, v;

int main()
{
    scanf("%d", &N);
    Unu = 0;
    fortodo(i, 1, N)
        fortodo(j, 1, N)
            {
                scanf("%d", &Aij);
                if (i == j) Unu ^= Aij;
            }
    for (scanf("%d", &Q); Q; Q--)
        {
            scanf("%d", &u);
            if (u == 3)
                putchar(Unu + '0');
            else
                {
                    Unu ^= 1;
                    scanf("%d", &v);
                }
        }
    printf("\n");
}