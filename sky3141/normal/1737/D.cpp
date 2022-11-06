#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 500 + 9;
constexpr LL INF = 1000000000000000000;

int n, m;
LL dis[N][N];
LL d2[N][N];
// bool vis[N];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dis[i][j] = INF;
            d2[i][j] = INF;
        }
        d2[i][i] = 0;
        // dis[i][i] = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = min(dis[u][v], (LL)w);
        d2[u][v] = d2[v][u] = 1;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
    // vector<int> d1(n + 1, n), dn(n + 1, n);
    // {
    //     queue<int> que;
    //     que.push(1);
    //     d1[1] = 0;
    //     while (!que.empty())
    //     {
    //         int cur = que.front();
    //         que.pop();
    //         for (int i = 1; i <= n; ++i)
    //         {
    //             if (d1[i] == n && dis[cur][i] < INF)
    //             {
    //                 d1[i] = d1[cur] + 1;
    //                 que.push(i);
    //             }
    //         }
    //     }
    // }
    // {
    //     queue<int> que;
    //     que.push(n);
    //     dn[n] = 0;
    //     while (!que.empty())
    //     {
    //         int cur = que.front();
    //         que.pop();
    //         for (int i = 1; i <= n; ++i)
    //         {
    //             if (dn[i] == n && dis[cur][i] < INF)
    //             {
    //                 dn[i] = dn[cur] + 1;
    //                 que.push(i);
    //             }
    //         }
    //     }
    // }
    LL ans = INF;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dis[i][j] < INF)
            {
                ans = min(ans, dis[i][j] * (d2[1][i] + d2[n][j] + 1));
                for (int k = 1; k <= n; ++k)
                {
                    ans = min(ans, dis[i][j] * (d2[1][k] + d2[k][n] + d2[i][k] + 2));
                    int t;
                    t = 1;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}