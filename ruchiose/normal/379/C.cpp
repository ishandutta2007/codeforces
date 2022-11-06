// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
#define mp make_pair
using namespace std;

bool Cmp_pf(pair<int,int> A, pair<int,int> B)
{
    return A.first < B.first;
}

int N, Ai, i, j;
pair<int,int> U[300010];
int Ret[300010];

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N)
        {
            scanf("%d", &Ai);
            U[i] = mp(Ai, i);
        }
    sort(U + 1, U + N + 1, Cmp_pf);
    int Last = 0;
    fortodo(i, 1, N)
        if (Last >= U[i].first)
            Ret[U[i].second] = Last = Last + 1;
        else
            Ret[U[i].second] = Last = U[i].first;
    fortodo(i, 1, N)
        printf("%d%s", Ret[i], (i == N) ? "\n" : " ");
    return 0;
}