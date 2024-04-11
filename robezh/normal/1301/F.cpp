#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1005, K = 45, INF = (int)1e9;

int n, m, k;
vector<pii> loc[K];
int a[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int dist[K][N][N];

bool in_bound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j]; a[i][j]--;
            loc[a[i][j]].push_back({i, j});
        }
    }
    rep(c, 0, k) {
        auto dis = dist[c];
        rep(i, 0, n) fill(dis[i], dis[i] + m, INF);
        vi cvis(k, 0);
        queue<pii> que;
        for(pii &p : loc[c]) {
            que.push(p);
            dis[p.first][p.second] = 0;
        }
        while(!que.empty()) {
            int x, y;
            tie(x, y) = que.front(); que.pop();
            if(!cvis[a[x][y]]) {
                cvis[a[x][y]] = 1;
                for(pii &p : loc[a[x][y]]) {
                    if(dis[p.first][p.second] == INF) {
                        dis[p.first][p.second] = dis[x][y] + 1;
                        que.push(p);
                    }
                }
            }
            for(int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if(in_bound(nx, ny) && dis[nx][ny] == INF) {
                    dis[nx][ny] = dis[x][y] + 1;
                    que.push({nx, ny});
                }
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        x0--, y0--, x1--, y1--;
        int res = abs(x1 - x0) + abs(y1 - y0);
        rep(c, 0, k) {
            res = min(res, dist[c][x0][y0] + 1 + dist[c][x1][y1]);
        }
        cout << res << '\n';
    }

}