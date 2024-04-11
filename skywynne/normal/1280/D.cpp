// In The Name Of The Queen
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int N = 3009;
const ll INF = 1e16;
int n, m, SZ[N], A[N];
ll dp2[N][N], dp2t[N];
pair < ll , ll > dp[N][N], dpt[N];
vector < int > Adj[N];
void DFS(int v, int p)
{
    SZ[v] = 1;
    dp[v][0] = {0, A[v]};
    dp2[v][1] = A[v] > 0;
    for (int u : Adj[v])
        if (u != p)
        {
            DFS(u, v);
            for (int b = 0; b <= min(m, SZ[v]); b ++)
            {
                for (int a = 0; a <= SZ[u] && a + b <= m; a ++)
                {
                    dpt[a + b] = max(dpt[a + b], {dp[v][b].x + dp[u][a].x, dp[v][b].y + dp[u][a].y});
                    dp2t[a + b + 1] = max(dp2t[a + b + 1], dp[v][b].x + dp[u][a].x + (dp[v][b].y + dp[u][a].y > 0));
                    dp2t[a + b] = max(dp2t[a + b], dp2[v][b] + dp2[u][a]);
                    dpt[a + b] = max(dpt[a + b], {dp[v][b].x + dp2[u][a], dp[v][b].y});
                }
            }
            SZ[v] += SZ[u];
            for (int i = 0; i <= min(m, SZ[v]); i ++)
            {
                dp[v][i] = dpt[i];
                dp2[v][i] = dp2t[i];
                dpt[i] = {-INF, -INF};
                dp2t[i] = -INF;
            }
        }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (; q; q --)
    {
        cin >> n >> m;
        for (int i = 1, a; i <= n; i ++)
            cin >> a, A[i] -= a;
        for (int i = 1, a; i <= n; i ++)
            cin >> a, A[i] += a;
        for (int i = 1; i < n; i ++)
        {
            int v, u;
            cin >> v >> u;
            Adj[v].push_back(u);
            Adj[u].push_back(v);
        }
        for (int j = 0; j <= m; j ++)
        {
            dp2t[j] = -INF;
            dpt[j] = {-INF, -INF};
            for (int i = 1; i <= n; i ++)
                dp[i][j] = {-INF, -INF}, dp2[i][j] = -INF;
        }
        DFS(1, 0);
        printf("%lld\n", dp2[1][m]);
        for (int i = 1; i <= n; i ++)
            Adj[i].clear(), A[i] = 0;
    }
    return 0;
}