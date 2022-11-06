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

int N;
int succ[100010], F[100010], context[100010];

int Find(int x)
{
    return F[x] = ((F[x] == x) ? x : Find(F[x]));
}

int main()
{
    scanf("%d", &N);
    if (N & 1)
        {
            puts("-1");
            return 0;
        }
    int n = N / 2, i;
    fortodo(i, 0, n - 1)
        {
            succ[i] = i * 2;
            succ[i + n] = i * 2 + 1;
        }
    fortodo(i, 0, N - 1) F[i] = context[i] = i;
    fortodo(i, 0, N - 1) F[Find(i)] = Find(succ[i]);
    fortodo(i, 0, n - 1)
        if (Find(i * 2) != Find(i * 2 + 1))
            {
                swap(succ[i * 2], succ[i * 2 + 1]);
                swap(context[i * 2], context[i * 2 + 1]);
                F[Find(i * 2)] = Find(i * 2 + 1);
            }
    printf("0");
    for (int y = succ[(context[0]) ? 1 : 0]; context[y]; y = succ[y]) printf(" %d", context[y]);
    printf(" 0\n");
}