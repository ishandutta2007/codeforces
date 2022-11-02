#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 10;
int n, q, ts, st[N], en[N], R[N], C[N * 4], L[N * 4], Mn[N * 4];
vector < int > Adj[N], Q[N];
void PREDFS(int v, int p)
{
    st[v] = ts ++;
    for (int u : Adj[v])
        if (u != p) PREDFS(u, v);
    en[v] = ts;
}
void Build(int id = 1, int l = 0, int r = n)
{
    C[id] = r - l;
    if (r - l > 1)
        Build(id * 2, l, (l + r) >> 1), Build(id * 2 + 1, (l + r) >> 1, r);
}
void Shift(int id, int le, int ri)
{
    Mn[le] += L[id]; Mn[ri] += L[id];
    L[le] += L[id]; L[ri] += L[id]; L[id] = 0;
}
void Add(int le, int ri, int val, int id = 1, int l = 0, int r = n)
{
    if (ri <= l || r <= le)
        return ;
    if (le <= l && r <= ri)
    {
        L[id] += val;
        Mn[id] += val;
        return ;
    }
    Shift(id, id * 2, id * 2 + 1);
    Add(le, ri, val, id * 2, l, (l + r) >> 1);
    Add(le, ri, val, id * 2 + 1, (l + r) >> 1, r);
    Mn[id] = min(Mn[id * 2], Mn[id * 2 + 1]); C[id] = 0;
    if (Mn[id] == Mn[id * 2]) C[id] = C[id * 2];
    if (Mn[id] == Mn[id * 2 + 1]) C[id] += C[id * 2 + 1];
}
void DFS(int v, int p)
{
    if (Q[v].size()) Add(st[v], en[v], 1);
    for (int u : Q[v])
        Add(st[u], en[u], 1);
    R[v] = n - ((!Mn[1]) ? C[1] : 0);
    for (int u : Adj[v])
        if (u != p)
            DFS(u, v);
    if (Q[v].size()) Add(st[v], en[v], -1);
    for (int u : Q[v])
        Add(st[u], en[u], -1);
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1, v, u; i < n; i++)
        scanf("%d%d", &v, &u), Adj[v].pb(u), Adj[u].pb(v);
    for (int i = 0, v, u; i < q; i++)
        scanf("%d%d", &v, &u), Q[v].pb(u), Q[u].pb(v);
    PREDFS(1, 0); Build(); DFS(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%d ", max(R[i] - 1, 0));
    return (0);
}