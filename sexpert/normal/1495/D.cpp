#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 505;
const ll MOD = 998244353;

int dis[MAX][MAX], n, m;
ll ans[MAX][MAX];
vector<array<int, 2>> ed;

ll solve(int u, int v) {
    vector<ll> op(n + 1), pth(n + 1);

    int cnt_p = 0;
    for(int i = 1; i <= n; i++) {
        if(dis[u][i] + dis[i][v] == dis[u][v]) {
            cnt_p++;
            op[i] = 1;
            pth[i] = 1;
        }
    }

    if(cnt_p > dis[u][v] + 1)
        return 0;

    for(auto [x, y] : ed) {
        if(dis[u][x] > dis[u][y])
            swap(x, y);
        if(pth[x] && pth[y])
            continue;
        if(dis[u][y] == dis[u][x] + 1 && dis[v][y] == dis[v][x] + 1)
            op[y]++;
    }

    ll ans = 1;
    for(int i = 1; i <= n; i++)
        ans = (ans * op[i]) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dis[i][j] = MOD;
        }
        dis[i][i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dis[x][y] = dis[y][x] = 1;
        ed.push_back({x, y});
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    for(int u = 1; u <= n; u++) {
        for(int v = u; v <= n; v++) {
            ll x = solve(u, v);
            ans[u][v] = ans[v][u] = x;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}