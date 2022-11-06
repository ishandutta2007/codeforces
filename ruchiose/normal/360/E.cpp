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

const int MAXN = 11000;
const int MAXE = 11000;
const int MAXK = 110;

int N, M, K, S1, S2, F, f[MAXK], l[MAXK], r[MAXK];
int e[MAXE], w[MAXE], enxt[MAXE], head[MAXE], ec;

void init()
{
    int i;
    fortodo(i, 1, N) head[i] = 0; ec = 0;
}

void regi(int u, int v, int c)
{
    ec++;
    e[ec] = v; w[ec] = c;
    enxt[ec] = head[u]; head[u] = ec;
}

const i64 BigLL = 1LL<<50;

i64 D1[MAXN], D2[MAXN];

typedef pair<i64,int> PLI;

#include<set>
set<PLI> cand;

void Dijkstra(int S, i64 *dist)
{
    cand.clear();
    int i;
    fortodo(i, 1, N) dist[i] = BigLL;
    dist[S] = 0;
    fortodo(i, 1, N) cand.insert(make_pair(dist[i], i));
    while (cand.size())
        {
            PLI f = *(cand.begin());
            cand.erase(f);
            for (int E = head[f.second]; E; E = enxt[E])
                if (f.first + w[E] < dist[e[E]])
                    {
                        cand.erase(make_pair(dist[e[E]], e[E]));
                        dist[e[E]] = f.first + w[E];
                        cand.insert(make_pair(dist[e[E]], e[E]));
                    }
        }
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    scanf("%d%d%d", &S1, &S2, &F);
    init();
    int i;
    fortodo(i, 1, M)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            regi(u, v, w);
        }
    fortodo(i, 1, K)
        {
            int v;
            scanf("%d%d%d%d", &f[i], &v, &l[i], &r[i]);
            regi(f[i], v, r[i]);
        }
    // ^v^
    Dijkstra(S1, D1);
    Dijkstra(S2, D2);
    do
        {
            bool Updated = false;
            fortodo(i, 1, K)
                if ((D1[f[i]] < D2[f[i]]) && (w[M + i] != l[i]))
                    {
                        w[M + i] = l[i];
                        Updated = true;
                    }
            if (!Updated) break;
            Dijkstra(S1, D1);
            Dijkstra(S2, D2);
        }
    while (1);
    if (D1[F] < D2[F])
        {
            printf("WIN\n");
            fortodo(i, 1, K)
                printf("%d%s", w[M + i], (i == K) ? "\n" : " ");
            return 0;
        }
    // ^v^
    fortodo(i, 1, K) w[M + i] = r[i];
    // -.-
    Dijkstra(S1, D1);
    Dijkstra(S2, D2);
    do
        {
            bool Updated = false;
            fortodo(i, 1, K)
                if ((D1[f[i]] <= D2[f[i]]) && (w[M + i] != l[i]))
                    {
                        w[M + i] = l[i];
                        Updated = true;
                    }
            if (!Updated) break;
            Dijkstra(S1, D1);
            Dijkstra(S2, D2);
        }
    while (1);
    if (D1[F] <= D2[F])
        {
            printf("DRAW\n");
            fortodo(i, 1, K)
                printf("%d%s", w[M + i], (i == K) ? "\n" : " ");
            return 0;
        }
    // -.-
    printf("LOSE\n");
}