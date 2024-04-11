// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
using namespace std;

int N, K, C[2];

void S()
{
    int p;
    if (C[0] < C[1])
        p = (C[0]) ? 0 : 1;
    else
        p = (C[1]) ? 1 : 0;
    C[p]--;
}

void T_PRE()
{
    if (C[0] < C[1])
        C[1]--;
    else
        C[0]--;
}

bool T_FINAL(bool FIRST_T)
{
    bool WANT_CHANGE = (FIRST_T == (C[1] % 2 == 0));
    return (WANT_CHANGE) ? C[1] : C[0];
}

int main()
{
    scanf("%d%d", &N, &K);
    C[0] = C[1] = 0;
    int i;
    fortodo(i, 1, N)
        {
            int v;
            scanf("%d", &v);
            C[v & 1]++;
        }
    if (N == K)
        {
            if (C[1] & 1)
                printf("Stannis\n");
            else
                printf("Daenerys\n");
            return 0;
        }
    bool FIRST_T = ((N & 1) != (K & 1));
    bool T_MOVE = FIRST_T;
    while (N > K + 1)
        {
            if (T_MOVE)
                T_PRE();
            else
                S();
            T_MOVE ^= true;
            N--;
        }
    if (T_FINAL(FIRST_T))
        printf("%s\n", (FIRST_T) ? "Stannis" : "Daenerys");
    else
        printf("%s\n", (!FIRST_T) ? "Stannis" : "Daenerys");
    return 0;
}