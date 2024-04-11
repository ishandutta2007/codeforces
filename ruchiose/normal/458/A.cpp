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

const int N = 100005;
const int MAXN = 100020;
char S[MAXN], T[MAXN];
int s, t;

int u[MAXN], v[MAXN];

int main()
{
    scanf("%s%s", S + 1, T + 1);
    s = strlen(S + 1);
    t = strlen(T + 1);
    int i;
    fortodo(i, 0, N) u[i] = v[i] = 0;
    fortodo(i, 1, s) u[s - i] = S[i] - '0';
    fortodo(i, 1, t) v[t - i] = T[i] - '0';
    for (i = N; i; i--)
        if ((u[i]) && (u[i - 1]))
            for (int j = i; (u[j]) && (u[j - 1]); j += 2)
                {
                    u[j]--;
                    u[j - 1]--;
                    u[j + 1]++;
                } 
    for (i = N; i; i--)
        if ((v[i]) && (v[i - 1]))
            for (int j = i; (v[j]) && (v[j - 1]); j += 2)
                {
                    v[j]--;
                    v[j - 1]--;
                    v[j + 1]++;
                }
    for (i = N; i >= 0; i--)
        if (u[i] != v[i])
            {
                putchar((u[i] > v[i]) ? '>' : '<');
                puts("");
                return 0;
            }
    puts("=");
}