#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int R, C, i, j, Ans, RC, CC;
char S[10];
int r[10], c[10];

int main()
{
    scanf("%d%d", &R, &C);
    fortodo(i, 0, C - 1) c[i] = 0;
    fortodo(i, 0, R - 1)
        {
            r[i] = 0;
            scanf("%s", &S);
            fortodo(j, 0, C - 1)
                if (S[j] == 'S')
                    {
                        r[i]++;
                        c[j]++;
                    };
        };
    RC = CC = 0;
    fortodo(i, 0, R - 1)
        if (r[i] != 0)
            RC++;
    fortodo(i, 0, C - 1)
        if (c[i] != 0)
            CC++;
    Ans = R * C - RC * CC;
    printf("%d\n", Ans);
    return 0;
};