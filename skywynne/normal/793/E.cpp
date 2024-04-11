#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5005;
int n, ts, A[4], B[4], sz[N], st[N], en[N];
vector < int > T, Adj[N];
bitset < N > M;
void DFS(int v)
{
    st[v] = ts ++;
    sz[v] += (!Adj[v].size());
    for (int &u : Adj[v])
    {
        DFS(u);
        if (v == 1)
            for (int i = 0; i < 4; i++)
                if (!B[i] && sz[A[i]])
                    B[i] = u;
        sz[v] += sz[u];
    }
    en[v] = ts;
}
bool Sub(int v, int u)
{
    return (st[v] <= st[u] && en[u] <= en[v]);
}
void DFS2(int v, int a)
{
    for (int &u : Adj[v])
    {
        if (!Sub(u, a))
            T.pb(sz[u]);
        else
            DFS2(u, a);
    }
}
bool KnapSack(int a, int b, int c)
{
    T.clear(); M = 0;
    for (int &u : Adj[1])
        if (u != B[0] && u != B[1] && u != B[2] && u != B[3])
            T.pb(sz[u]);
    int target = sz[1] / 2 - sz[B[c]] - 1; M[0] = 1;
    DFS2(B[a], A[a]); DFS2(B[b], A[b]);
    for (int &val : T)
        M |= (M << val);
    return (target >= 0 && (bool)M[target]);
}
int main()
{
    scanf("%d%d%d%d%d", &n, &A[0], &A[1], &A[2], &A[3]);
    for (int i = 2, p; i <= n; i++)
        scanf("%d", &p), Adj[p].pb(i);
    DFS(1);
    if (sz[1] & 1) return puts("NO");
    if (KnapSack(0, 1, 2) && KnapSack(2, 3, 1))
        return puts("YES");
    return puts("NO");
}