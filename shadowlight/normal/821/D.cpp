#include <bits/stdc++.h>

#define ll long long
#define TASKNAME ""

const int INF = 1e9 + 7;
const double EPS = 1e-8;
const int MAXN = 1e6 + 7;

using namespace std;
int n, m, k;

bool isCorrect(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

vector <int> dx = {0, -1, 0, 1};
vector <int> dy = {1, 0, -1, 0};
const int D = 4;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    cin >> n >> m >> k;
    vector <vector <int> > line(n), col(m);
    map <pair <int, int>, int> exist, dist, used;
    deque <pair <int, int> > q;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        line[x].push_back(y);
        col[y].push_back(x);
        exist[{x, y}] = 1;
    }
    int fl = !exist[{n - 1, m - 1}];
    dist[{0, 0}] = 0;
    q.push_front({0, 0});
    int ans = INF;
    while (!q.empty()) {
        auto p = q.front();
        q.pop_front();
        int x = p.first, y = p.second;
        //cout << x << " " << y << " " << dist[{x, y}] << endl;
        if (x == n - 1 && y == m - 1) {
            cout << dist[{x, y}];
            return 0;
        }
        if (x >= n - 3 + fl || y >= m - 3 + fl) {
            if (dist[{x, y}] >= ans) {
                cout << ans;
                return 0;
            } else {
                ans = dist[{x, y}] + 1;
            }
        }
        if (used[{x, y}] == 2) continue;
        used[{x, y}] = 2;
        for (int d = 0; d < D; d++) {
            int x1 = x + dx[d], y1 = y + dy[d];
            if (!isCorrect(x1, y1)) continue;
            if (!exist[{x1, y1}]) continue;
            if (used[{x1, y1}] == 2) continue;
            used[{x1, y1}] = 1;
            dist[{x1, y1}] = dist[{x, y}];
            q.push_front({x1, y1});
        }
        for (int i = max(x - 2, 0); i <= min(x + 2, n - 1); i++) {
            for (int &y1 : line[i]) {
                int x1 = i;
                if (y1 == -1) continue;
                if (used[{x1, y1}]) {
                    y1 = -1;
                    continue;
                }
                used[{x1, y1}] = 1;
                dist[{x1, y1}] = dist[{x, y}] + 1;
                q.push_back({x1, y1});
            }
        }
        for (int i = max(y - 2, 0); i <= min(y + 2, m - 1); i++) {
            for (int &x1 : col[i]) {
                int y1 = i;
                if (x1 == -1) continue;
                if (used[{x1, y1}]) {
                    x1 = -1;
                    continue;
                }
                used[{x1, y1}] = 1;
                dist[{x1, y1}] = dist[{x, y}] + 1;
                q.push_back({x1, y1});
            }
        }
    }
    if (ans == INF) {
        cout << -1;
    } else {
        cout << ans;
    }
}