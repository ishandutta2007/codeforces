#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5, LG = 18;
int n, q, ts, st[N], en[N], sz[N], H[N], V[N], U[N], P[N][LG];
long long D[N], D2[N];
long double E[N];
vector < int > Adj[N], Q[N];
void DFS(int v, int p)
{
    st[v] = ts ++; sz[v] = 1; P[v][0] = p;
    for (int i = 1; i < LG; i++)
        P[v][i] = P[P[v][i -1]][i -1];
    for (int i = 0; i < Adj[v].size(); i++)
        if (Adj[v][i] == p)
            swap(Adj[v][i], Adj[v].back()), Adj[v].pop_back();
    for (int &u : Adj[v])
        H[u] = H[v] + 1, DFS(u, v), sz[v] += sz[u], D[v] += D[u] + sz[u];
    en[v] = ts;
}
inline bool Sub(int v, int u)
{
    return (st[v] <= st[u] && en[u] <= en[v]);
}
inline int LCA(int v, int u)
{
    if (H[v] < H[u])
        return (LCA(u, v));
    for (int i = 0; i < LG; i++)
        if ((H[v] - H[u]) & (1 << i))
            v = P[v][i];
    if (v == u)
        return (v);
    for (int i = LG - 1; ~i; i--)
        if (P[v][i] != P[u][i])
            v = P[v][i], u = P[u][i];
    return (P[v][0]);
}
inline int Dist(int v, int u)
{
    return (H[v] + H[u] - H[LCA(v, u)] * 2);
}
inline int Getpar(int v, int u)
{
    int le = 0, ri = Adj[v].size(), md;
    while (ri - le > 1)
    {
        md = (le + ri) >> 1;
        if (st[Adj[v][md]] <= st[u])
            le = md;
        else
            ri = md;
    }
    return (Adj[v][le]);
}
void DFS2(int v)
{
    for (int &i : Q[v])
    {
        int u = V[i] ^ U[i] ^ v;
        if (!Sub(v, u))
            E[i] += (long double)D[v] / sz[v];
        else
        {
            int par = Getpar(v, u);
            E[i] += (long double)(D[v] - D[par] - sz[par] + D2[v]) / (n - sz[par]);
        }
    }
    for (int &u : Adj[v])
        D2[u] += D[v] - D[u] - sz[u] + D2[v] + (n - sz[u]), DFS2(u);
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1, v, u; i < n; i++)
        scanf("%d%d", &v, &u), Adj[v].pb(u), Adj[u].pb(v);
    for (int i = 1; i <= q; i++)
        scanf("%d%d", &V[i], &U[i]), Q[V[i]].pb(i), Q[U[i]].pb(i);
    DFS(1, 0); DFS2(1);
    for (int i = 1; i <= q; i++)
    {
        E[i] += Dist(V[i], U[i]) + 1;
        printf("%.10lf\n", (double)E[i]);
    }
    return (0);
}