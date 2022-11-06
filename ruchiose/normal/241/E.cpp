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
const int MAXM = 5010;
const int MAXE = MAXM << 1;

int N, M, u[MAXM], v[MAXM];
int e[MAXE], w[MAXE], enxt[MAXE], head[MAXN], ec;

void regi(int u, int v, int w)
{
    ec++;
    e[ec] = v; ::w[ec] = w;
    enxt[ec] = head[u]; head[u] = ec;
}

bool nchk[MAXN], tmp[MAXN];

int dist[MAXN], process[MAXN];
bool inq[MAXN];

#include<queue>

queue<int> Q;

void spfa()
{
    int i;
    fortodo(i, 1, N)
        {
            dist[i] = 0x23333333;
            process[i] = 0;
            inq[i] = false;
        }
    while (Q.size()) Q.pop();
    Q.push(1); dist[1] = 0; inq[1] = true;
    while (Q.size())
        {
            int u = Q.front(); Q.pop(); inq[u] = false;
            if (!nchk[u]) continue;
            if ((process[u]++) > N)
                {
                    printf("No\n");
                    exit(0);
                }
            for (int E = head[u]; E; E = enxt[E])
                if (dist[u] + w[E] < dist[e[E]])
                    {
                        dist[e[E]] = dist[u] + w[E];
                        if (!inq[e[E]])
                            {
                                Q.push(e[E]);
                                inq[e[E]] = true;
                            }
                    }
        }
}

int main()
{
    scanf("%d%d", &N, &M);
    int i;
    fortodo(i, 1, M) scanf("%d%d", &u[i], &v[i]);
    fortodo(i, 1, N) head[i] = 0; ec = 0;
    fortodo(i, 1, M)
        {
            regi(u[i], v[i], 2);
            regi(v[i], u[i], -1);
        }
    fortodo(i, 1, N) nchk[i] = false;
    nchk[1] = true;
    while (Q.size()) Q.pop();
    Q.push(1);
    while (Q.size())
        {
            int u = Q.front();
            Q.pop();
            for (int E = head[u]; E; E = enxt[E])
                if ((w[E] == 2) && (!nchk[e[E]]))
                    {
                        nchk[e[E]] = true;
                        Q.push(e[E]);
                    }
        }
    fortodo(i, 1, N) tmp[i] = false;
    tmp[N] = true;
    while (Q.size()) Q.pop();
    Q.push(N);
    while (Q.size())
        {
            int u = Q.front();
            Q.pop();
            for (int E = head[u]; E; E = enxt[E])
                if ((w[E] == -1) && (!tmp[e[E]]))
                    {
                        tmp[e[E]] = true;
                        Q.push(e[E]);
                    }
        }
    fortodo(i, 1, N) nchk[i] &= tmp[i];
    spfa();
    printf("Yes\n");
    fortodo(i, 1, M)
        if ((nchk[u[i]]) && (nchk[v[i]]))
            printf("%d\n", dist[v[i]] - dist[u[i]]);
        else
            printf("1\n");
}