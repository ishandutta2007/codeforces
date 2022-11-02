// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, m, q, ts, P[N], A[N], sz[N], H[N], MH[N];
vector < int > vec, Adj[N];
void DFS(int v)
{
    sz[v] = 1;
    MH[v] = H[v];
    for (int u : Adj[v])
    {
        H[u] = H[v] + 1;
        DFS(u);
        sz[v] += sz[u];
        MH[v] = max(MH[v], MH[u]);
    }
}
inline bool CMP(int i, int j)
{
    return (MH[i] < MH[j]);
}
void DFS2(int v)
{
    A[ts ++] = v;
    sort(Adj[v].begin(), Adj[v].end(), CMP);
    int last = 0;
    for (int u : Adj[v])
        DFS2(u);
    for (int u : Adj[v])
    {
        for (int i = 0; i < last; i ++)
            vec.push_back(u);
        last = MH[u] - H[v];
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i ++)
        scanf("%d", &P[i]), Adj[P[i]].push_back(i);
    DFS(0); DFS2(0);
    for (int i = 0; i < ts; i ++)
        printf("%d ", A[i]);
    printf("\n%d\n", (int)vec.size());
    for (int v : vec)
        printf("%d ", v);
    printf("\n");
    return 0;
}