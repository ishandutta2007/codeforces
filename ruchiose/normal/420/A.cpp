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

const string H = "AHIMOTUVWXY";

bool Irm(char s)
{
    int i;
    fortodo(i, 0, 10)
        if (s == H[i])
            return true;
    return false;
}

char S[100100];
int N, i, j;

int main()
{
    scanf("%s", S + 1);
    N = strlen(S + 1);
    for (i = 1, j = N; i < j; i++, j--)
        if (S[i] != S[j])
            {
                printf("NO\n");
                return 0;
            }
    fortodo(i, 1, N)
        if (!Irm(S[i]))
            {
                printf("NO\n");
                return 0;
            }
    printf("YES\n");
    return 0;
}