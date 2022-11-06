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

const int MAXN = 1010;

int N, M;
int V[MAXN];

int main()
{
    scanf("%d%d", &N, &M);
    int i;
    fortodo(i, 1, N) scanf("%d", &V[i]);
    int ans = 0;
    fortodo(i, 1, M)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            ans += min(V[u], V[v]);
        }
    printf("%d\n", ans);
}