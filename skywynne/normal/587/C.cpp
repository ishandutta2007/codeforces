// For old time sakes ...
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 100005, LG = 17, MXS = N * LG * 2;
int n, m, q, H[N], P[N][LG];
int ts, root[N], L[MXS], R[MXS], S[MXS];
vector < int > res, A[N], Adj[N];
int Set(int i, int id, int l = 0, int r = m)
{
    int _id = ++ ts;
    L[_id] = L[id];
    R[_id] = R[id];
    S[_id] = S[id] + 1;
    if (r - l > 1 && i < (l + r >> 1))
        L[_id] = Set(i, L[id], l, l + r >> 1);
    else if (r - l > 1)
        R[_id] = Set(i, R[id], l + r >> 1, r);
    return _id;
}
void DFS(int v, int p)
{
    P[v][0] = p; H[v] = H[p] + 1;
    for (int i = 1; i < LG; i++)
        P[v][i] = P[P[v][i - 1]][i - 1];
    root[v] = root[p];
    for (int &id : A[v])
        root[v] = Set(id, root[v]);
    for (int &u : Adj[v])
        if (u != p)
            DFS(u, v);
}
inline int LCA(int v, int u)
{
    if (H[v] < H[u])
        return LCA(u, v);
    for (int i = 0; i < LG; i++)
        if ((H[v] - H[u]) >> i & 1)
            v = P[v][i];
    if (v == u)
        return v;
    for (int i = LG - 1; ~i; i--)
        if (P[v][i] != P[u][i])
            v = P[v][i], u = P[u][i];
    return P[v][0];
}
void Solve(int k, int rv, int ru, int rl, int rp, int l = 0, int r = m)
{
    if (S[rv] + S[ru] - S[rl] - S[rp] == 0)
        return ;
    if (r - l < 2)
        {res.pb(l); return ;}
    Solve(k, L[rv], L[ru], L[rl], L[rp], l, l + r >> 1);
    if (res.size() < k)
        Solve(k, R[rv], R[ru], R[rl], R[rp], l + r >> 1, r);
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i < n; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        Adj[v].pb(u);
        Adj[u].pb(v);
    }
    for (int i = 0, v; i < m; i++)
        scanf("%d", &v), A[v].pb(i);
    DFS(1, 0);
    for (; q; q --)
    {
        int v, u, k;
        scanf("%d%d%d", &v, &u, &k);
        int lca = LCA(v, u), p = P[lca][0];
        Solve(k, root[v], root[u], root[lca], root[p]);
        printf("%d", (int)res.size());
        for (int &id : res)
            printf(" %d", id + 1);
        printf("\n");
        res.clear();
    }
    return 0;
}