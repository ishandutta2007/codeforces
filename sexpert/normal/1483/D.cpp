#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 605;
const ll INF = 1e18;
ll dis[MAXN][MAXN], we[MAXN][MAXN], L[MAXN][MAXN], gay[MAXN][MAXN], n, m;
vector<array<int, 2>> edges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            gay[i][j] = -INF;
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        dis[x][y] = dis[y][x] = we[x][y] = we[y][x] = w;
        edges.push_back({x, y});
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        L[u][v] = L[v][u] = l;
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    for(int x = 1; x <= n; x++)
        for(int v = 1; v <= n; v++)
            for(int y = 1; y <= n; y++)
                gay[x][v] = max(gay[x][v], L[x][y] - dis[v][y]);

    int ans = 0;
    for(auto [u, v] : edges) {
        bool good = false;
        for(int i = 0; i < 2; i++) {
            for(int x = 1; x <= n; x++)
                if(dis[x][u] + we[u][v] <= gay[x][v])
                    good = true;
            swap(u, v);
        }
        if(good)
            ans++;
    }
    cout << ans << '\n';
}