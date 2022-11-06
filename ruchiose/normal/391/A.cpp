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

int N, i, Cnt, h;
char S[103];

int main()
{
    scanf("%s", S + 1);
    N = strlen(S + 1);
    h = 1; Cnt = 0;
    fortodo(i, 2, N + 1)
        if (S[i - 1] != S[i])
            {
                Cnt += 1 - ((i - h) & 1);
                h = i;
            }
    cout << Cnt << endl;
}