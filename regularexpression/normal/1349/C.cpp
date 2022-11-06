#include<bits/stdc++.h>
using namespace std;

const int N = 1007;
const long long INF = 2e18 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, t;
char a[N][N];
long long dist[N][N];

inline bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

inline bool good(int x, int y) {
    for (int i = 0; i < 4; i++) {
        if (check(x + dx[i], y + dy[i]) && a[x][y] == a[x + dx[i]][y + dy[i]]) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            dist[i][j] = INF;
        }
    }
    deque<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (good(i, j)) {
                dist[i][j] = 0;
                q.emplace_back(i, j);
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (check(xx, yy) && dist[x][y] + 1 < dist[xx][yy]) {
                dist[xx][yy] = dist[x][y] + 1;
                q.emplace_back(xx, yy);
            }
        }
    }
    while (t--) {
        int i, j;
        long long p;
        cin >> i >> j >> p;
        i--;
        j--;
        p--;
        if (p < dist[i][j]) cout << a[i][j] << '\n'; else {
            p -= dist[i][j];
            if (p & 1) cout << a[i][j]; else cout << (a[i][j] == '0' ? '1' : '0');
            cout << '\n';
        }
    }
    return 0;
}