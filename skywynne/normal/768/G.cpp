#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 73;
int n, root, sz[N], Ptr[N], MN[N], MX[N], R[N];
vector < int > Adj[N];
set < int > S[N];
multiset < int > P, A;
void Del(multiset < int > &SS, int val)
{
    auto it = SS.lower_bound(val);
    if (it != SS.end() && (*it) == val)
        SS.erase(it);
}
inline int Get(int a, int b, int c)
{
    return (max(a + c, b - a));
}
void DFS(int v)
{
    sz[v] = 1; MN[v] = N;
    for (int &u : Adj[v])
        DFS(u), sz[v] += sz[u], MN[v] = min(MN[v], sz[u]);
    for (int i = 0; i < Adj[v].size(); i++)
        if (sz[Adj[v][i]] > sz[Adj[v].back()])
            swap(Adj[v][i], Adj[v].back());
    if (v != root) MN[v] = min(MN[v], n - sz[v]), MX[v] = n - sz[v];
    Ptr[v] = v;
    if (Adj[v].size())
    {
        int &rc = Adj[v].back();
        MX[v] = max(MX[v], sz[rc]), Ptr[v] = Ptr[Adj[v].back()];
        if (MX[v] == sz[rc])
        {
            auto it = S[Ptr[rc]].upper_bound((MX[v] - MN[v]) >> 1);
            if (it != S[Ptr[rc]].end())
                R[v] = Get((*it), sz[rc], MN[v]);
            if (it != S[Ptr[rc]].begin())
                it --, R[v] = min(R[v], Get((*it), sz[rc], MN[v]));
        }
    }
    for (int &u : Adj[v])
        if (u != Adj[v].back())
        {
            for (int X : S[Ptr[u]])
                S[Ptr[v]].insert(X);
            S[Ptr[u]].clear();
        }
    S[Ptr[v]].insert(sz[v]);
}
void Add(int v, int w)
{
    if (w) A.insert(sz[v]);
    else Del(A, sz[v]);
    for (int &u : Adj[v])
        Add(u, w);
}
void DFS2(int v)
{
    if (!Adj[v].size())
    {
        A.insert(sz[v]);
        return ;
    }
    if (MX[v] == n - sz[v])
    {
        auto it = A.upper_bound((MX[v] - MN[v]) >> 1);
        if (it != A.end())
            R[v] = min(R[v], Get(*it, n - sz[v], MN[v]));
        if (it != A.begin())
            it --, R[v] = min(R[v], Get(*it, n - sz[v], MN[v]));
        it = P.upper_bound((MX[v] - MN[v]) / 2 + sz[v]);
        if (it != P.end())
            R[v] = min(R[v], Get((*it) - sz[v], n - sz[v], MN[v]));
        if (it != P.begin())
            it --, R[v] = min(R[v], Get((*it) - sz[v], n - sz[v], MN[v]));
    }
    int &rc = Adj[v].back();
    for (int &u : Adj[v])
        if (u != rc)
            Add(u, 1);
    P.insert(sz[v]);
    DFS2(rc);
    for (int &u : Adj[v])
        if (u != rc)
            Add(u, 0), DFS2(u);
    Del(P, sz[v]);
    A.insert(sz[v]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1, v, u; i <= n; i++)
        scanf("%d%d", &v, &u), Adj[v].pb(u);
    memset(R, 1, sizeof(R));
    root = Adj[0][0]; DFS(root);
    for (int i = 1; i <= n; i++)
        S[i].clear();
    DFS2(root);
    for (int i = 1; i <= n; i++)
    {
        if (!Adj[i].size() || (root == i && Adj[i].size() == 1))
        {
            printf("%d\n", n - 1);
            continue;
        }
        bool w = 0;
        if (MX[i] == n - sz[i])
            w = 1;
        else
            R[i] = max(R[i], n - sz[i]);
        for (int &u : Adj[i])
        {
            if (MX[i] == sz[u] && !w)
                w = 1;
            else
                R[i] = max(R[i], sz[u]);
        }
        R[i] = min(R[i], MX[i]);
        printf("%d\n", R[i]);
    }
    return (0);
}