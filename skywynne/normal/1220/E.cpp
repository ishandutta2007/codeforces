// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, q, st, cp = 1, A[N], Mn[N], H[N], C[N], SZ[N];
long long W[N];
vector < int > Ad[N], Adj[N];
void DFS(int v, int p)
{
    H[v] ++;
    Mn[v] = H[v];
    for (int u : Adj[v])
    {
        if (u == p)
            continue;
        if (!H[u])
            H[u] = H[v], DFS(u, v);
        Mn[v] = min({Mn[v], H[u], Mn[u]});
    }
}
void DFS2(int v, int ccp)
{
    SZ[ccp] ++;
    C[v] = ccp;
    W[ccp] += A[v];
    for (int u : Adj[v])
    {
        if (C[u])
            continue;
        if (Mn[u] < H[u])
            DFS2(u, ccp);
        else
            Ad[ccp].push_back(++ cp), DFS2(u, cp);
    }
}
pair < long long , long long > DFS3(int v)
{
    long long fSM = 0, fMX = 0, fi = W[v], sec = W[v];
    for (int u : Ad[v])
    {
        pair < long long , long long > tt = DFS3(u);
        if (SZ[u] > 1) SZ[v] = 2;
        if (SZ[u] > 1) fSM += tt.second, sec += tt.second, fMX = max(fMX, tt.first - tt.second);
        else fMX = max(fMX, tt.first);

    }
    fi += fSM + fMX;
    if (SZ[v] == 1)
        sec = -1e18;
    return make_pair(fi, sec);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= m; i ++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        Adj[v].push_back(u);
        Adj[u].push_back(v);
    }
    scanf("%d", &st);
    DFS(st, 0);
    DFS2(st, 1);
    pair < long long , long long > pr = DFS3(1);
    printf("%lld\n", max(pr.first, pr.second));
    return 0;
}