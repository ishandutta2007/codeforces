#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
int n, k, Mod, des, A[N], M[N], Pw[N], Inv[N], H[N], sz[N], In[N], Out[N], up[N], dn[N];
long long tot;
vector < int > Adj[N];
map < int , int > U, C, T;
inline int Power(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = 1ll * a * a % Mod)
        if (b & 1) ret = 1ll * ret * a % Mod;
    return (ret);
}
void PREDFS(int v, int p = -1)
{
    sz[v] = 1;
    for (int &u : Adj[v])
        if (!M[u] && u != p)
            PREDFS(u, v), sz[v] += sz[u];
}
int GetCentroid(int v, int p = -1, int _n = -1)
{
    if (p == -1)
        PREDFS(v), _n = sz[v];
    for (int &u : Adj[v])
        if (!M[u] && u != p && sz[u] * 2 > _n)
            return (GetCentroid(u, v, _n));
    return (v);
}
void DFS(int v, int p)
{
    H[v] = H[p] + 1;
    dn[v] = (1ll * dn[p] * k + A[v]) % Mod;
    up[v] = (1ll * Pw[H[p]] * A[v] + up[p]) % Mod;
    U[up[v]] ++;
    for (int &u : Adj[v])
        if (!M[u] && u != p)
            DFS(u, v);
}
void Add(int v, int p, int w)
{
    U[up[v]] += w;
    for (int &u : Adj[v])
        if (!M[u] && u != p)
            Add(u, v, w);
}
void Finalize(int v, int p)
{
    ///u ~~> v : ok
    ///up[u] * k ^ (H[v] + 1) + dn[v] = des
    ///~~> up[u] = (des - dn[v]) * (1 / k) ^ (H[v] + 1)
    int trg = 1ll * (des - dn[v] + Mod) * Inv[H[v] + 1] % Mod;
    In[v] += U[trg]; C[trg] ++; T[trg] --;
    for (int &u : Adj[v])
        if (!M[u] && u != p)
            Finalize(u, v);
}
void Absorb(int v, int p, map < int , int > &Mp)
{
    Out[v] += Mp[up[v]];
    for (int &u : Adj[v])
        if (!M[u] && u != p)
            Absorb(u, v, Mp);
}
void Solve(int v)
{
    H[v] = up[v] = 0;
    dn[v] = A[v];
    for (int &u : Adj[v])
        if (!M[u])
            DFS(u, v);
    int trg = 1ll * (des - dn[v] + Mod) * Inv[H[v] + 1] % Mod;
    In[v] += U[trg];
    U[up[v]] ++;
    for (int &u : Adj[v])
        if (!M[u])
        {
            Add(u, v, -1);
            Finalize(u, v);
            Absorb(u, v, T);
            Add(u, v, 1);
            T.clear();
        }
    Out[v] += C[0];
    C[trg] ++;
    for (int &u : Adj[v])
        if (!M[u])
            Absorb(u, v, C);
    C.clear();
    U.clear();
}
void Decompose(int v)
{
    v = GetCentroid(v);
    M[v] = 1; Solve(v);
    for (int &u : Adj[v])
        if (!M[u])
            Decompose(u);
}
int main()
{
    scanf("%d%d%d%d", &n, &Mod, &k, &des);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1, v, u; i < n; i++)
        scanf("%d%d", &v, &u), Adj[u].pb(v), Adj[v].pb(u);
    for (int i = Pw[0] = Inv[0] = 1; i < N; i++)
        Pw[i] = 1ll * Pw[i -1] * k % Mod, Inv[i] = Power(Pw[i], Mod - 2);
    Decompose(1);
    for (int i = 1; i <= n; i++)
    {
        if (A[i] == des)
            In[i] ++, Out[i] ++;
        tot -= 2ll * Out[i] * (n - Out[i]) + 2ll * In[i] * (n - In[i]) + 1ll * In[i] * (n - Out[i]) + 1ll * Out[i] * (n - In[i]);
    }
    tot >>= 1; tot += 1ll * n * n * n;
    return !printf("%lld", tot);
}