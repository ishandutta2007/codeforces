// Skywynne
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, q, k, S[N], D[2][N], MX[N];
vector < int > Adj[N];
vector < pair < int , int > > A;
void SSSP(int w, int st)
{
    queue < int > qu;
    D[w][st] = 0;
    qu.push(st);
    while (qu.size())
    {
        int v = qu.front();
        qu.pop();
        for (int u : Adj[v])
            if (D[w][u] > D[w][v] + 1)
                D[w][u] = D[w][v] + 1, qu.push(u);
    }
}
inline bool Solve(int md)
{
    for (int i = 0; i < (int)A.size(); i ++)
    {
        int lb = lower_bound(A.begin() + i + 1, A.end(), pair < int , int > {md - A[i].second, -1}) - A.begin();
        if (lb < (int)A.size() && MX[lb] + A[i].first >= md)
            return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i ++)
        cin >> S[i];
    for (int i = 1; i <= m; i ++)
    {
        int v, u;
        cin >> v >> u;
        Adj[v].push_back(u);
        Adj[u].push_back(v);
    }
    memset(D, 63, sizeof(D));
    SSSP(0, 1);
    SSSP(1, n);
    for (int i = 1; i <= k; i ++)
        A.push_back({D[0][S[i]], D[1][S[i]]});
    sort(A.begin(), A.end());
    for (int i = (int)A.size() - 1; ~ i; i --)
        MX[i] = max(MX[i + 1], A[i].second);
    int le = 0, ri = n, md;
    while (ri - le > 1)
    {
        md = (le + ri) >> 1;
        if (Solve(md))
            le = md;
        else
            ri = md;
    }
    return !printf("%d\n", min(le + 1, D[0][n]));
}