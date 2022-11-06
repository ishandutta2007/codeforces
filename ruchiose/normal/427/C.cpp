#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 100010;
const int MAXM = 300010;
const i64 MOD = 1000000007;

int N, M, i, j, C[MAXN];
int head[MAXN], e[MAXM][2], enxt[MAXM], ec;

void regi(int u, int v)
{
    ec++;
    e[ec][0] = u; e[ec][1] = v;
    enxt[ec] = head[u]; head[u] = ec;
}

int bt[MAXN], st[MAXN], stm, stk[MAXN], isk[MAXN];

i64 mincost, mcways;

void pack(int x)
{
    i64 mininum = 0x7FFFFFFF, w = 0;
    int u;
    do
        {
            u = stk[stk[0]];
            stk[0]--;
            isk[u] = 0;
            if (mininum > C[u])
                {
                    mininum = C[u];
                    w = 0;
                }
            if (mininum == C[u]) w++;
        }
    while (u != x);
    mincost += mininum;
    mcways = mcways * w % MOD;
}

void visit(int x)
{
    stm++;
    bt[x] = st[x] = stm;
    stk[++stk[0]] = x;
    isk[x] = 1;
    for (int E = head[x]; E; E = enxt[E])
        {
            int nx = e[E][1];
            if ((bt[nx]) && (isk[nx]))
                st[x] = min(st[x], bt[nx]);
            if (bt[nx] == 0)
                {
                    visit(nx);
                    st[x] = min(st[x], st[nx]);
                }
        }
    if (bt[x] == st[x]) pack(x);
}

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d", &C[i]);
    scanf("%d", &M);
    fortodo(i, 1, N) head[i] = 0; ec = 0;
    fortodo(i, 1, M)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            regi(u, v);
        }
    stm = stk[0] = 0;
    fortodo(i, 1, N) bt[i] = 0;
    mincost = 0; mcways = 1;
    fortodo(i, 1, N)
        if (bt[i] == 0)
            visit(i);
    printf("%I64d %I64d\n", mincost, mcways);
}