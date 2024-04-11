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

const int MAXN = 1000100;

int N;
char S[MAXN];
int CntF, ltime;

int main()
{
    scanf("%s", S + 1);
    N = strlen(S + 1);
    CntF = ltime = 0;
    int i;
    fortodo(i, 1, N)
        if (S[i] == 'F')
            if (CntF++)
                ltime = (i == CntF) ? 0 : max(ltime + 1, i - CntF);
            else
                ltime = i - 1;
    printf("%d\n", ltime);
}