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

#include<queue>

const int MAXN = 310;
const int MAXE = MAXN << 1;

int N, V, M, A[MAXN], B[MAXN];

struct Disjoint
{
    int F[MAXN];
    void init()
    {
        int i;
        fortodo(i, 1, N) F[i] = i;
    }
    int Find(int x)
    {
        return F[x] = ((F[x] == x) ? x : Find(F[x]));
    }
    bool Cnx(int x, int y)
    {
        return Find(x) == Find(y);
    }
    void Union(int x, int y)
    {
        F[Find(x)] = Find(y);
    }
};

bool Active[MAXN];
int head[MAXN], e[MAXE], enxt[MAXE], ec;

void regi(int u, int v)
{
    e[++ec] = v; enxt[ec] = head[u]; head[u] = ec;
}

int ANS[600000], *ans = ANS;
int degActive[MAXN];

Disjoint getConnectivity()
{
    Disjoint G;
    G.init();
    int i;
    fortodo(i, 1, N) if (Active[i])
        for (int E = head[i]; E; E = enxt[E]) if (Active[e[E]])
            G.Union(i, e[E]);
    return G;
}

const int INF = 1111111111;

void In(int subj, int obj, int value)
{
    if (A[obj] < value)
        {
            int needAbsorb = value - A[obj];
            Active[obj] = false;
            int supply[MAXN], i;
            fortodo(i, 1, N) supply[i] = 0;
            Disjoint subs = getConnectivity();
            fortodo(i, 1, N)
                supply[subs.Find(i)] = min(INF, supply[subs.Find(i)] + A[i]);
            for (int E = head[obj]; E; E = enxt[E])
                if (Active[e[E]])
                    {
                        int delta = min(needAbsorb, supply[subs.Find(e[E])]);
                        In(obj, e[E], delta);
                        if ((needAbsorb -= delta) == 0) break;
                    }
            Active[obj] = true;
        }
    ans[0] = obj; A[obj] -= value;
    ans[1] = subj; A[subj] += value;
    ans[2] = value;
    ans += 3;
}

void Out(int subj, int obj, int value)
{
    if (A[obj] + value > V)
        {
            int needReserve = A[obj] + value - V;
            Active[obj] = false;
            int supply[MAXN], i;
            fortodo(i, 1, N) supply[i] = 0;
            Disjoint subs = getConnectivity();
            fortodo(i, 1, N)
                supply[subs.Find(i)] = min(INF, supply[subs.Find(i)] + V - A[i]);
            for (int E = head[obj]; E; E = enxt[E])
                if (Active[e[E]])
                    {
                        int delta = min(needReserve, supply[subs.Find(e[E])]);
                        Out(obj, e[E], delta);
                        if ((needReserve -= delta) == 0) break;
                    }
            Active[obj] = true;
        }
    ans[0] = subj; A[subj] -= value;
    ans[1] = obj; A[obj] += value;
    ans[2] = value;
    ans += 3;
}

int main()
{
    scanf("%d%d%d", &N, &V, &M);
    int i;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    fortodo(i, 1, N) scanf("%d", &B[i]);
    Disjoint G;
    G.init();
    fortodo(i, 1, N) head[i] = degActive[i] = 0; ec = 0;
    fortodo(i, 1, N) Active[i] = true;
    fortodo(i, 1, M)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (!G.Cnx(u, v))
                {
                    regi(u, v);
                    regi(v, u);
                    degActive[u]++;
                    degActive[v]++;
                    G.Union(u, v);
                }
        }
    i64 sumA[MAXN], sumB[MAXN];
    fortodo(i, 1, N) sumA[i] = sumB[i] = 0;
    fortodo(i, 1, N)
        {
            sumA[G.Find(i)] += A[i];
            sumB[G.Find(i)] += B[i];
        }
    fortodo(i, 1, N)
        if (sumA[i] != sumB[i])
            {
                printf("NO\n");
                return 0;
            }
    queue<int> Q;
    while (Q.size()) Q.pop();
    fortodo(i, 1, N)
        if (degActive[i] < 2)
            Q.push(i);
    while (Q.size())
        {
            int u = Q.front();
            Active[u] = false;
            Q.pop();
            if (degActive[u])
                {
                    int v;
                    for (int E = head[u]; E; E = enxt[E])
                        if (Active[e[E]])
                            {
                                v = e[E];
                                break;
                            }
                    degActive[v]--;
                    if (degActive[v] == 1)
                        Q.push(v);
                    if (A[u] == B[u]) continue;
                    if (A[u] < B[u])
                        In(u, v, B[u] - A[u]);
                    else
                        Out(u, v, A[u] - B[u]);
                }
        }
    printf("%d\n", (ans - ANS) / 3);
    for (int* trid = ANS; trid != ans; trid += 3)
        printf("%d %d %d\n", trid[0], trid[1], trid[2]);
}