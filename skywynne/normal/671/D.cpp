#include<bits/stdc++.h>
#define pb push_back
#define lc (id * 2)
#define rc (id * 2 + 1)
#define md ((l + r) >> 1)
using namespace std;
const int N = 3e5 + 5;
const long long INF = 1ll << 50;
int n, m, ts, st[N], en[N], Id[N], C[N];
long long dp[N], Lz[N * 4], Mn[N * 4];
vector < int > Adj[N], A[N], B[N];
inline void Shift(int id)
{
    Lz[lc] += Lz[id]; Mn[lc] += Lz[id];
    Lz[rc] += Lz[id]; Mn[rc] += Lz[id];
    Mn[lc] = min(Mn[lc], INF);
    Mn[rc] = min(Mn[rc], INF);
    Lz[id] = 0;
}
void Add(int le, int ri, long long val, int id = 1, int l = 0, int r = N)
{
    if (ri <= l || r <= le)
        return ;
    if (le <= l && r <= ri)
    {
        Lz[id] += val;
        Mn[id] += val;
        Mn[id] = min(Mn[id], INF);
        return ;
    }
    Shift(id);
    Add(le, ri, val, lc, l, md);
    Add(le, ri, val, rc, md, r);
    Mn[id] = min(Mn[lc], Mn[rc]);
}
long long Get(int le, int ri, int id = 1, int l = 0, int r = N)
{
    if (ri <= l || r <= le)
        return (INF);
    if (le <= l && r <= ri)
        return (Mn[id]);
    Shift(id);
    return (min(Get(le, ri, lc, l, md), Get(le, ri, rc, md, r)));
}
void DFS(int v, int p)
{
    st[v] = ts;
    for (int &i : A[v])
        Id[i] = ts ++;
    long long s = 0;
    for (int &u : Adj[v])
        if (u != p)
            DFS(u, v), s += dp[u];
    en[v] = ts;
    for (int &u : Adj[v])
        if (u != p)
            Add(st[u], en[u], s - dp[u]);
    for (int &i : A[v])
        Add(Id[i], Id[i] + 1, C[i] + s - INF);
    dp[v] = Get(st[v], en[v]);
    for (int &i : B[p])
        Add(Id[i], Id[i] + 1, INF - Get(Id[i], Id[i] + 1));
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, v, u; i < n; i++)
        scanf("%d%d", &v, &u), Adj[v].pb(u), Adj[u].pb(v);
    for (int i = 1, v, u; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &C[i]);
        if (v == u)
            m --, i--;
        else
            A[u].pb(i), B[v].pb(i);
    }
    fill(Mn, Mn + N * 4, INF);
    long long s = 0;
    for (int &u : Adj[1])
    {
        DFS(u, 1);
        if (dp[u] == INF)
            return !printf("-1");
        s += dp[u];
    }
    return !printf("%lld", s);
}