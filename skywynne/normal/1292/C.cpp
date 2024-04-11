// Skywynne
#include<bits/stdc++.h>
using namespace std;
const int N = 3003;
int n, m, q, A[N], D[N][N], SZ[N][N];
long long Mx, dp[N][N];
vector < int > Adj[N];
inline bool CMP(pair < int , int > a, pair < int , int > b)
{
    return (D[a.first][a.second] < D[b.first][b.second]);
}
void DFS(int v, int p, int root)
{
    SZ[root][v] = 1;
    for (int u : Adj[v])
        if (u != p)
        {
            D[root][u] = D[root][v] + 1;
            DFS(u, v, root);
            SZ[root][v] += SZ[root][u];
        }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i ++)
    {
        int v, u;
        cin >> v >> u;
        Adj[v].push_back(u);
        Adj[u].push_back(v);
    }
    vector < pair < int , int > > vec;
    for (int i = 1; i <= n; i ++)
        DFS(i, 0, i);
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            vec.push_back({i, j});
    sort(vec.begin(), vec.end(), CMP);
    for (auto X : vec)
    {
        int v = X.first;
        int u = X.second;
        dp[v][u] = max(dp[v][u], dp[u][v]);
        if (D[v][u] == 1)
            dp[v][u] = SZ[v][u] * (n - SZ[v][u]);

        int k = D[v][u];

        int fromv, fromu;
        for (int to : Adj[u])
            if (D[v][to] == D[v][u] - 1)
                fromu = to;
        for (int to : Adj[v])
            if (D[u][to] == D[u][v] - 1)
                fromv = to;

        for (int to : Adj[u])
            if (D[v][to] == D[v][u] + 1)
                dp[v][to] = max(dp[v][to], dp[v][u] + SZ[u][to] * SZ[fromv][v]);
        for (int to : Adj[v])
            if (D[u][to] == D[u][v] + 1)
                dp[u][to] = max(dp[u][to], dp[v][u] + SZ[v][to] * SZ[fromu][u]);
        Mx = max(Mx, dp[v][u]);
    }
    printf("%lld\n", Mx);
    return 0;
}