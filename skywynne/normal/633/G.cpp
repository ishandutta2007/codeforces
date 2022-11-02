#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 3, M = 1003;
int n, m, q, ts, A[N], st[N], en[N], L[N * 4], Mr[N];
vector < int > Adj[N];
bitset < M > T, P, R, S[N * 4];
void DFS(int v, int p)
{
    st[v] = ts ++;
    for (int &u : Adj[v])
        if (u != p)
            DFS(u, v);
    en[v] = ts;
}
inline void Update(int id, int val)
{
    L[id] = (L[id] + val) % m;
    S[id] = (S[id] >> (m - val)) | (S[id] << val);
    S[id] &= T;
}
inline void Shift(int id, int lc, int rc)
{
    Update(lc, L[id]); Update(rc, L[id]); L[id] = 0;
}
void Add(int le, int ri, int val, int id = 1, int l = 0, int r = n)
{
    if (ri <= l || r <= le)
        return ;
    if (le <= l && r <= ri)
    {
        Update(id, val);
        return ;
    }
    int lc = id * 2, rc = lc + 1, md = (l + r) >> 1;
    Shift(id, lc, rc);
    Add(le, ri, val, lc, l, md);
    Add(le, ri, val, rc, md, r);
    S[id] = S[lc] | S[rc];
}
void Get(int le, int ri, int id = 1, int l = 0, int r = n)
{
    if (ri <= l || r <= le)
        return ;
    if (le <= l && r <= ri)
    {
        R |= S[id];
        return ;
    }
    int lc = id * 2, rc = lc + 1;
    Shift(id, lc, rc);
    Get(le, ri, lc, l, (l + r) >> 1);
    Get(le, ri, rc, (l + r) >> 1, r);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]), A[i] %= m;
    for (int i = 1, v, u; i < n; i++)
        scanf("%d%d", &v, &u), Adj[v].pb(u), Adj[u].pb(v);
    for (int i = 2; i < m; i++)
        if (!Mr[i])
        {
            P[i] = 1;
            for (int j = i + i; j < m; j += i)
                Mr[j] = 1;
        }
    for (int i = 0; i < m; i++)
        T[i] = 1;
    DFS(1, 0);
    for (int i = 1; i < N * 4; i++)
        S[i] = 1;
    for (int i = 1; i <= n; i++)
        Add(st[i], st[i] + 1, A[i]);
    scanf("%d", &q);
    for (int tp, v, val; q; q --)
    {
        scanf("%d%d", &tp, &v);
        if (tp == 1)
            scanf("%d", &val), Add(st[v], en[v], val % m);
        else
            R = 0, Get(st[v], en[v]), printf("%d\n", (R & P).count());
    }
    return (0);
}