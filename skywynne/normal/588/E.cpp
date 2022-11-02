#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 10, LOG = 20;
int n, m, q, r, t, a, c, H[MXN], Log[MXN * 10], Pow[LOG], P[LOG][MXN];
vector < int > A, T, R, V[MXN], S[LOG][MXN];
vector < int > Merge(vector < int > X, vector < int > Y)
{
    vector < int > res;
    for (auto Z : Y)
        res.push_back(Z);
    for (auto Z : X)
        res.push_back(Z);
    sort(res.begin(), res.end());
    res.resize(distance(res.begin(), unique(res.begin(), res.end())));
    return res;
}
void DFS(int v, int p)
{
    int tmp = p;
    for (int i = 1; i < LOG; i++)
    {
        P[i][v] = P[i - 1][tmp];
        S[i][v] = Merge(S[i - 1][v], S[i - 1][tmp]);
        tmp = P[i][v];
        while (S[i][v].size() > 10)
            S[i][v].pop_back();
    }
    for (auto u : V[v])
        if (u != p)
            H[u] = H[v] + 1, DFS(u, v);
}
int LCA(int v, int u)
{
    if (H[v] < H[u])
        v ^= u, u ^= v, v ^= u;
    for (int i = LOG - 1; i >= 1; i--)
        if (P[i][v] != 0 && H[u] <= H[P[i][v]])
            v = P[i][v];
    if (v == u)
        return v;
    for (int i = LOG - 1; i >= 1; i--)
        if (P[i][v] != P[i][u])
            v = P[i][v], u = P[i][u];
    return (P[1][v]);
}
vector < int > Query(int v, int u)
{
    if (v == u)
        return S[0][v];
    int lg = Log[H[v] - H[u]], p = v;
    vector < int > res;
    while (H[p] != Pow[lg] + H[u])
        p = P[Log[H[p] - (H[u] + Pow[lg])] + 1][p];
    res = Merge(S[lg + 1][v], S[lg + 1][p]);
    return res;
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    Pow[0] = 1;
    for (int i = 1; i < LOG; i++)
        Pow[i] = Pow[i - 1] * 2, Log[Pow[i]] = i;
    for (int i = 2; i < MXN; i++)
    {
        if (Log[i] != 0)
            r = Log[i];
        else
            Log[i] = r;
    }
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &r, &t);
        V[r].push_back(t);
        V[t].push_back(r);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &r);
        if (S[0][r].size() < 10)
            S[0][r].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        P[0][i] = i;
    DFS(1, 0);
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d%d", &r, &t, &a);
        c = LCA(r, t);
        T = Query(r, c);
        R = Query(t, c);
        A = Merge(T, R);
        printf("%d ", min(a, (int)A.size()));
        for (int j = 0; j < min(a, (int)A.size()); j++)
            printf("%d ", A[j]);
        printf("\n");
    }
    return (0);
}