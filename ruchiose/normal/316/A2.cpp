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

const int MAXN = 100010;
char S[MAXN];
int N, fact[11];

int main()
{
    scanf("%s", S + 1);
    N = strlen(S + 1);
    int c = 0, i;
    fact[0] = 1;
    fortodo(i, 1, 10) fact[i] = fact[i - 1] * i;
    fortodo(i, 1, N)
        if ((S[i] >= 'A') && (S[i] <= 'Z'))
            c |= 1 << (S[i] - 'A');
    c = __builtin_popcount(c);
    if ((S[1] >= 'A') && (S[i] <= 'Z'))
        printf("%d", fact[10] / fact[10 - c] - fact[9] / fact[10 - c]);
    else
        printf("%d", (fact[10] / fact[10 - c]) * ((S[1] == '?') ? 9 : 1));
    fortodo(i, 2, N)
        if (S[i] == '?')
            putchar('0');
    puts("");
}