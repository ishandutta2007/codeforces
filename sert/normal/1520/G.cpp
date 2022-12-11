#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;
using vvi = vector<vector<int>>;

const int dy[] = {1, 0, 0, -1};
const int dx[] = {0, 1, -1, 0};

vvi bfs(const vvi &field, int y, int x, ll w, ll &mn) {
    int n = field.size(), m = field[0].size();
    vvi dist(n, vector<int>(m, -1));
    dist[y][x] = 0;
    queue<pair<int, int>> q;
    q.emplace(y, x);
    while (!q.empty()) {
        tie(y, x) = q.front();
        if (field[y][x] > 0)
            mn = min(mn, w * dist[y][x] + field[y][x]);
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int xx = x + dx[dir], yy = y + dy[dir];
            if (0 <= yy && yy < n && 0 <= xx && xx < m && field[yy][xx] >= 0 && dist[yy][xx] == -1) {
                dist[yy][xx] = dist[y][x] + 1;
                q.emplace(yy, xx);
            }
        }
    }
    return dist;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const ll INF = (ll)1e18 + 41;
    int n, m, w;
    cin >> n >> m >> w;
    vvi field(n, vector<int>(m));
    for (auto &row : field) for (int &x : row) cin >> x;
    ll a1 = INF;
    ll a2 = INF;
    const auto &d0 = bfs(field, 0, 0, w, a1);
    const auto &d1 = bfs(field, n - 1, m - 1, w, a2);
    ll ans = (d1[0][0] == -1 ? INF : (ll)d1[0][0] * w);
    if (a1 < INF && a2 < INF) ans = min(ans, a1 + a2);
    cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
#ifdef SERT
    freopen("../kek/a.in", "r", stdin);
#endif
    solve();
}