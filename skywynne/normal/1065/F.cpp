#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 10, LG = 21;
int n, k, B[N], H[N], C[N], F[N], P[N][LG];
vector < int > Adj[N];
priority_queue < pair < int , int > > Pq;
void PRE(int v)
{
    for (int i = 1; i < LG; i++)
        P[v][i] = P[P[v][i - 1]][i - 1];
    for (int &u : Adj[v])
        H[u] = H[v] + 1, PRE(u);
}
inline int Parent(int v, int k)
{
    for (int i = 0; i < LG; i++)
        if (k & (1 << i))
            v = P[v][i];
    return (v);
}
void DFS(int v)
{
    F[v] += C[v];
    for (int &u : Adj[v])
        F[u] += F[v], DFS(u);
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 2, p; i <= n; i++)
        scanf("%d", &p), Adj[p].pb(i), P[i][0] = p;
    PRE(1);
    for (int i = 1; i <= n; i++)
        if (!Adj[i].size())
            Pq.push({-H[i], i});
    for (int i = 1; i <= n; i++)
        B[i] = i;
    while (Pq.size())
    {
        int v = Pq.top().second; Pq.pop();
        int u = P[v][0];
        B[v] = B[Parent(v, min(k, H[v]))];
        while (u && H[B[u]] > H[B[v]])
            B[u] = B[v], u = P[u][0];
    }
    for (int i = 1; i <= n; i++)
        if (!Adj[i].size())
            C[B[i]] ++;
    DFS(1);
    int Mx = 0;
    for (int i = 1; i <= n; i++)
        Mx = max(Mx, F[i]);
    return !printf("%d", Mx);
}