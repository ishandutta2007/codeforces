#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const i64 MAXN = 100010;
const i64 MAXE = MAXN << 1;

i64 N, M, D, i, j;
bool af[MAXN];
i64 e[MAXE], enxt[MAXE], head[MAXN], ec, dep[MAXN], f[MAXN];
i64 s[MAXN], s0;
i64 dp[MAXN], pd[MAXN];

void regi(i64 a, i64 b)
{
    e[++ec] = b;
    enxt[ec] = head[a];
    head[a] = ec;
}

void dfs(i64 cur, i64 p)
{
    s[++s0] = cur;
    dep[cur] = p;
    for (i64 E = head[cur]; E; E = enxt[E])
        if (dep[e[E]] == -1)
            {
                f[e[E]] = cur;
                dfs(e[E], p + 1);
            }
}

i64 cion[MAXN];

int main()
{
    scanf("%I64d%I64d%I64d", &N, &M, &D);
    fortodo(i, 1, N) head[i] = 0; ec = 0;
    fortodo(i, 1, N) af[i] = false;
    fortodo(i, 1, M)
        {
            i64 u;
            scanf("%I64d", &u);
            af[u] = true;
        }
    fortodo(i, 2, N)
        {
            i64 u, v;
            scanf("%I64d%I64d", &u, &v);
            regi(u, v); regi(v, u);
        }
    fortodo(i, 1, N) dep[i] = -1;
    f[1] = 0;
    s0 = 0;
    dfs(1, 0);
    for (i = N; i; i--)
        {
            dp[s[i]] = (af[s[i]]) ? 1 : 0;
            for (i64 E = head[s[i]]; E; E = enxt[E])
                if ((dep[e[E]] > dep[s[i]]) && (dp[e[E]]))
                    dp[s[i]] = max(dp[s[i]], dp[e[E]] + 1);
        }
    fortodo(i, 1, N)
        {
            cion[0] = 0;
            for (i64 E = head[s[i]]; E; E = enxt[E])
                if (dep[e[E]] > dep[s[i]])
                    cion[++cion[0]] = e[E];
            int n = cion[0];
            fortodo(j, 1, n)
                pd[cion[j]] = 0;
            i64 tmp = 0;
            fortodo(j, 1, n)
                {
                    pd[cion[j]] = max(pd[cion[j]], tmp);
                    if (dp[cion[j]])
                        tmp = max(tmp, dp[cion[j]] + 1);
                }
            tmp = 0;
            for (j = n; j; j--)
                {
                    pd[cion[j]] = max(pd[cion[j]], tmp);
                    if (dp[cion[j]])
                        tmp = max(tmp, dp[cion[j]] + 1);
                }
        }
    fortodo(i, 2, N)
        if (af[f[i]])
            pd[i] = max(pd[i], 1ll);
    fortodo(i, 2, N)
        if (pd[f[s[i]]])
            pd[s[i]] = max(pd[s[i]], pd[f[s[i]]] + 1);
    i64 count = 0;
    fortodo(i, 1, N)
        if (max(pd[i], dp[i] - 1) <= D)
            count++;
    printf("%I64d\n", count);
}