#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, i, O, X, Y, Z, A[100010];

int main()
{
    scanf("%d%d", &N, &M);
    fortodo(i, 1, N) scanf("%d", &A[i]);
    O = 0;
    fortodo(i, 1, M)
        {
            scanf("%d%d", &X, &Y);
            if (X == 1)
                {
                    scanf("%d", &Z);
                    A[Y] = Z - O;
                }
            if (X == 2) O += Y;
            if (X == 3)
                printf("%d\n", A[Y] + O);
        }
}