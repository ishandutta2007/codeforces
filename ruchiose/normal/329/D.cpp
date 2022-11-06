// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int main()
{
    int N, X;
    scanf("%d%d", &N, &X);
    if (N == 5)
        {
            puts(">...v");
            puts("v.<..");
            puts("..^..");
            puts(">....");
            puts("..^.<");
            puts("1 1");
            return 0;
        }
    if (N == 3)
        {
            puts(">vv");
            puts("^<.");
            puts("^.<");
            puts("1 3");
            return 0;
        }
    int i, j;
    int K = N / 2;
    int A, B;
    if (K % 2 == 0)
        {
            A = K;
            B = K / 2 - 1;
        }
    else
        {
            A = K - 1;
            B = (K - 1) / 2;
        }
    fortodo(i, 1, N)
        {
            if (i == 1)
                putchar('>');
            else
                if ((i % 2 == 0) && (i <= B * 2 + 2))
                    putchar('.');
                else
                    putchar('^');
            if (i % 2 == 1)
                {
                    putchar('>');
                    fortodo(j, 1, A) putchar('>');
                    fortodo(j, 1, B - 1)
                        {
                            putchar('.');
                            putchar('>');
                        }
                    putchar('.');
                    putchar('v');
                }
            else
                {
                    if (i == N)
                        putchar('<');
                    else
                        putchar('v');
                    putchar('.');
                    fortodo(j, 1, B - 1)
                        {
                            putchar('<');
                            putchar('.');
                        }
                    fortodo(j, 1, A + 1) putchar('<');
                }
            puts("");
        }
    printf("1 1\n");
}