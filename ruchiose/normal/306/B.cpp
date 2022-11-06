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

int N, M, S[200010], E[200010], e[2000010], id[2000010];
int F[2000010], C[2000010];

bool Use[200010];
#include<vector>
vector<int> unused;

int main()
{
    scanf("%d%d", &N, &M);
    int i;
    fortodo(i, 1, N + 1) F[i] = 0;
    fortodo(i, 1, M)
        {
            int a, l;
            scanf("%d%d", &a, &l);
            S[i] = a;
            E[i] = l;
            F[S[i]]++;
            F[a + l]--;
        }
    fortodo(i, 2, N + 1) F[i] += F[i - 1];
    C[0] = 0;
    fortodo(i, 1, N)
        if (F[i])
            C[i] = ++C[0];
    fortodo(i, 1, M)
        {
            S[i] = C[S[i]];
            E[i] += S[i];
        }
    fortodo(i, 1, N)
        {
            e[i] = i;
            id[i] = 0;
        }
    fortodo(i, 1, M)
        if (e[S[i]] < E[i])
            {
                e[S[i]] = E[i];
                id[S[i]] = i;
            }
    fortodo(i, 2, N)
        if (e[i - 1] > e[i])
            {
                e[i] = e[i - 1];
                id[i] = id[i - 1];
            }
    fortodo(i, 1, M) Use[i] = false;
    for (int i = 1; i <= C[0]; i = e[i]) Use[id[i]] = true;
    unused.clear();
    fortodo(i, 1, M) if (!Use[i]) unused.push_back(i);
    int s = unused.size();
    printf("%d\n", s);
    fortodo(i, 0, s - 1)
        printf("%d%s", unused[i], (i == s - 1) ? "\n" : " ");
}