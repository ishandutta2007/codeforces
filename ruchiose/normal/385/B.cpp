#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
using namespace std;

char S[5001];
int N, i, j;

int L0, Loc[5001];
int Nxt[5001];

int main()
{
    scanf("%s", S + 1);
    N = strlen(S + 1);
    L0 = 0;
    fortodo(i, 4, N)
        if ((S[i - 3] == 'b') && (S[i - 2] == 'e') && (S[i - 1] == 'a') && (S[i] == 'r'))
            Loc[++L0] = i;
    if (L0 == 0)
        {
            printf("0\n");
            return 0;
        };
    fortodo(i, 1, N) Nxt[i] = 0;
    fortodo(i, 1, L0) Nxt[Loc[i] - 3] = Loc[i];
    for (i = N - 1; i; i--)
        if (Nxt[i] == 0)
            Nxt[i] = Nxt[i + 1];
    int ANS = 0;
    fortodo(i, 1, N)
        if (Nxt[i] != 0)
            ANS += N + 1 - Nxt[i];
    printf("%d\n", ANS);
};