#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1024;
const int INF = 0x7f7f7f7f;

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int N, M;
char grid[MAXN][MAXN];

int dist[3][MAXN][MAXN];

bool seen[3];
int first[3][2];

int spath[3][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];

            if ('1' <= grid[i][j] && grid[i][j] <= '3') {
                int g = grid[i][j] - '1';
                if (seen[g]) continue;

                seen[g] = true;
                first[g][0] = i;
                first[g][1] = j;
            }
        }
    }

    memset(dist, 0x7f, sizeof(dist));
    for (int g = 0; g < 3; g++) {
        int sx = first[g][0], sy = first[g][1];
        dist[g][sx][sy] = 0;

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push(make_pair(0, make_pair(sx, sy)));

        while (!pq.empty()) {
            int len = -pq.top().first;
            int lx = pq.top().second.first;
            int ly = pq.top().second.second;

            pq.pop();
            if (dist[g][lx][ly] < len) continue;

            for (int d = 0; d < 4; d++) {
                int nx = lx + dir[d][0];
                int ny = ly + dir[d][1];

                if (nx < 0 || ny < 0 || nx == N  || ny == M) continue;
                if (grid[nx][ny] == '#') continue;

                int far = len + (grid[nx][ny] == '.');
                if (far < dist[g][nx][ny]) {
                    dist[g][nx][ny] = far;
                    pq.push(make_pair(-far, make_pair(nx, ny)));
                }
            }
        }
    }

    memset(spath, 0x7f, sizeof(spath));

    for (int g = 0; g < 3; g++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if ('1' <= grid[i][j] && grid[i][j] <= '3') {
                    int g2 = grid[i][j] - '1';
                    spath[g][g2] = min(spath[g][g2], dist[g][i][j]);
                }
            }
        }
    }

    vector<int> poss = { spath[0][1], spath[0][2], spath[1][2] };
    sort(poss.begin(), poss.end());

    if (poss.back() == INF) { cout << -1 << "\n"; return 0; }

    int ans = poss[0] + poss[1];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ll cand = 0;
            for (int g = 0; g < 3; g++) {
                cand += dist[g][i][j];
            }
            if (grid[i][j] == '.') cand -= 2;
            ans = min(ans, int(cand));
        }
    }

    cout << ans << "\n";
}