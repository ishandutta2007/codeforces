#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, A[N], P[N];
bool M[N];
long long D[N];
vector < pair < int , int > > Adj[N];
void DFS(int v, int p, long long d)
{
    D[v] = max(D[v], d);
    for (auto &u : Adj[v])
        if (u.first != p)
            DFS(u.first, v, d + u.second);
}
bool CMP(int i, int j)
{
    return (D[i] < D[j]);
}
int Find(int v)
{
    return (P[v] < 0 ? v : (P[v] = Find(P[v])));
}
inline int Solve(long long L)
{
    int pt = n, Mx = 0;
    memset(P, -1, sizeof(P));
    for (int i = n; i; i--)
    {
        while (pt && D[A[i]] - D[A[pt]] <= L)
        {
            M[A[pt]] = 1;
            for (auto &u : Adj[A[pt]])
                if (M[u.first])
                    P[A[pt]] += P[Find(u.first)], P[Find(u.first)] = A[pt];
            Mx = max(Mx, -P[A[pt]]); pt --;
        }
        P[Find(A[i])] ++; M[A[i]] = 0;
    }
    return Mx;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int v, u, w;
        scanf("%d%d%d", &u, &v, &w);
        Adj[v].push_back({u, w});
        Adj[u].push_back({v, w});
    }
    int root = 0;
    DFS(1, 0, 0);
    for (int i = 1; i <= n; i++)
        if (D[root] <= D[i])
            root = i;
    DFS(root, 0, 0);
    for (int i = 1; i <= n; i++)
        if (D[root] <= D[i])
            root = i;
    DFS(root, 0, 0);
    for (int i = 1; i <= n; i++)
        A[i] = i;
    sort(A + 1, A + n + 1, CMP);
    int q; scanf("%d", &q);
    for (long long l; q; q --)
        scanf("%lld", &l), printf("%d\n", Solve(l));
    return (0);
}