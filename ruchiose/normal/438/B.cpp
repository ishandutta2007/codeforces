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
const int MAXE = 200010;

int N, M, A[MAXN];
int head[MAXN], e[MAXE], enxt[MAXE], ec;

int F[MAXN], sz[MAXN], entries[MAXN], rank[MAXN];

int Find(int x)
{
    return F[x] = ((F[x] == x) ? x : Find(F[x]));
}

bool cmp_Az(int x, int y)
{
    return A[x] > A[y];
}

int main()
{
    scanf("%d%d", &N, &M);
    int i;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    fortodo(i, 1, N) head[i] = 0; ec = 0;
    fortodo(i, 1, M)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            e[++ec] = v; enxt[ec] = head[u]; head[u] = ec;
            e[++ec] = u; enxt[ec] = head[v]; head[v] = ec;
        }
    i64 sum = 0;
    fortodo(i, 1, N)
        {
            F[i] = i;
            sz[i] = 1;
        }
    fortodo(i, 1, N) entries[i] = i;
    sort(entries + 1, entries + N + 1, cmp_Az);
    fortodo(i, 1, N) rank[entries[i]] = i;
    fortodo(i, 1, N)
        {
            int u = entries[i], v;
            for (int E = head[u]; E; E = enxt[E])
                if (rank[v = e[E]] < i)
                    {
                        int uu = Find(u), vv = Find(v);
                        if (uu != vv)
                            {
                                sum += (i64)A[u] * (i64)sz[uu] * sz[vv];
                                F[uu] = vv;
                                sz[vv] += sz[uu];
                            }
                    }
        }
    double ans = double(sum) / ((i64)N * (N - 1ll) / 2);
    printf("%.10f\n", ans);
}