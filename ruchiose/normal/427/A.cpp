#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, C, A, i, v;

int main()
{
    scanf("%d", &N);
    C = A = 0;
    fortodo(i, 1, N)
        {
            scanf("%d", &v);
            C += v;
            if (C < 0)
                {
                    A -= C;
                    C = 0;
                }
        }
    printf("%d\n", A);
}