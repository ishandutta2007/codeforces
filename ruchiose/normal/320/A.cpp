#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, i, j;
int D[12];

int main()
{
    scanf("%d", &N);
    D[0] = 1;
    D[1] = N;
    while (D[D[0]] > 9)
        {
            D[D[0] + 1] = D[D[0]] / 10;
            D[D[0]] %= 10;
            D[0]++;
        };
    fortodo(i, 1, D[0])
        if ((D[i] != 1) && (D[i] != 4))
            {
                printf("NO\n");
                return 0;
            };
    if (D[D[0]] == 4)
        {
            printf("NO\n");
            return 0;
        };
    for (i = D[0]; i >= 1; i--)
        {
            if (D[i] == 1)
                j = 0;
            else
                j++;
            if (j >= 3)
                {
                    printf("NO\n");
                    return 0;
                };
        };
    printf("YES\n");
    return 0;
};