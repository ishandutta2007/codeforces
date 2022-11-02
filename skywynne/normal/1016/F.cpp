#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 3e5 + 3;
int n, q, ts, Done, st[N], en[N], sz[N], P[N];
long long Mn = 1e18, Best = 1e18, D[N];
vector < pair < int , long long > > Adj[N];
void PREDFS(int v, int p)
{
    st[v] = ts ++; sz[v] = 1; P[v] = p;
    for (int i = 0; i < Adj[v].size(); i++)
        if (Adj[v][i].x == p)
            Adj[v].erase(Adj[v].begin() + i);
    for (auto &u : Adj[v])
        D[u.x] = D[v] + u.y, PREDFS(u.x, v), sz[v] += sz[u.x];
    en[v] = ts;
}
inline bool Sub(int v, int u)
{
    return (st[v] <= st[u] && en[u] <= en[v]);
}
void DFS(int v)
{
    if (!Sub(v, n) && sz[v] >= 2)
        Done = 1;
    if (Adj[v].size() > 2)
        Done = 1;
    if (Adj[v].size() == 2 && Sub(Adj[v][1].x, n))
        swap(Adj[v][0], Adj[v][1]);
    for (auto &u : Adj[v])
        DFS(u.x);
}
void DFS2(int v)
{
    if (!Adj[v].size())
        return ;
    if (v == n)
    {
        Best = - Adj[v][0].y;
        Mn = min(Mn, Adj[P[v]][0].y - Adj[v][0].y);
        return ;
    }
    auto &u = Adj[v][0];
    DFS2(u.x);
    Best += u.y;
    if (u.x != n)
        Mn = min(Mn, u.y + Adj[u.x][0].y);
    if (Adj[v].size() == 1)
        return ;
    Mn = min(Mn, u.y - Adj[v][1].y);
    if (P[v])
        Mn = min(Mn, Adj[P[v]][0].y - Adj[v][1].y);
    Mn = min(Mn, Best - Adj[v][1].y);
    Best = min(Best, - Adj[v][1].y);
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1, v, u, w; i < n; i++)
        scanf("%d%d%d", &v, &u, &w), Adj[v].pb({u, w}), Adj[u].pb({v, w});
    PREDFS(1, 0); DFS(1);
    if (Adj[n].size() > 1) Done = 1;
    if (Done) Mn = 0;
    if (!Done) DFS2(1);
    for (int w; q; q --)
    {
        scanf("%d", &w);
        if (w >= Mn)
            printf("%lld\n", D[n]);
        else
            printf("%lld\n", D[n] - Mn + w);
    }
    return (0);
}