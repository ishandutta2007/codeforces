#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define MODER 1000000007
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

char S[100];
int N, i, j, Pow[201], Ans;

int main()
{
    scanf("%s", &S);
    N = strlen(S);
    Pow[0] = 1;
    fortodo(i, 1, N * 2)
        Pow[i] = (Pow[i - 1] * 2) % MODER;
    Ans = 0;
    fortodo(i, 0, N - 1)
        if (S[i] == '1')
            {
                Ans += Pow[N * 2 - 2 - i];
                Ans %= MODER;
            };
    printf("%d\n", Ans);
    return 0;
};