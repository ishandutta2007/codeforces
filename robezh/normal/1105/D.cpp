#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = 1005;

queue<P> que[9];
int n,m,p;
int s[N];
string c[N];
int dis[9][N][N];
bool vis[N][N];
bool bk[N][N];
int bel[N][N];
int cnt[9];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

bool good(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && !bk[i][j];
}

int main() {
    memset(dis, 0x3f, sizeof(dis));
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> p;
    for (int i = 0; i < p; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] >= '1' && c[i][j] <= '9') {
                int p = c[i][j] - '1';
                que[p].push({i, j});
                dis[p][i][j] = 0;
                bk[i][j] = true;
            }
            else if (c[i][j] == '#') vis[i][j] = true;
        }
    }
    for (int round = 1; round < N * N; round++) {
        for (int i = 0; i < p; i++) {
            int mxdis = int(min((1LL * round * s[i]), (ll)1e9));
            while (!que[i].empty()) {
                auto p = que[i].front();
                if (dis[i][p.first][p.second] > mxdis) break;
                que[i].pop();
                if (vis[p.first][p.second]) continue;
                vis[p.first][p.second] = true;
                cnt[i]++;
                for (int d = 0; d < 4; d++) {
                    int nx = p.first + dx[d], ny = p.second + dy[d];
                    if (good(nx, ny) && dis[i][nx][ny] > dis[i][p.first][p.second] + 1) {
                        dis[i][nx][ny] = dis[i][p.first][p.second] + 1;
                        que[i].push({nx, ny});
                    }
                }
            }
        }
    }
    for(int i = 0; i < p; i++) cout << cnt[i] << " ";
}