#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 2e3 + 10;
int n, m;
int a[N][N];

int dist[2][N][N];

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

bool checkCell(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] != -1;
}

struct Point{
    int x, y;
};

void build(int it, Point a) {
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            dist[it][x][y] = -1;
        }
    }
    queue<Point> q;
    q.push(a);
    dist[it][a.x][a.y] = 0;
    while (!q.empty()) {
        auto a = q.front();
        // cerr << "a.x = " << a.x << " a.y = " << a.y << endl;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = a.x + dx[i];
            int ny = a.y + dy[i];
            if (!checkCell(nx, ny)) continue;
            // cerr << "puhh1" << endl;
            if (dist[it][nx][ny] != -1) continue;
            // cerr << "puhh2" << endl;
            dist[it][nx][ny] = dist[it][a.x][a.y] + 1;
            q.push({nx, ny});
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int w;
    cin >> n >> m;
    cin >> w;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    build(0, {0, 0});
    build(1, {n - 1, m - 1});
    ll ans = dist[0][n - 1][m - 1];
    if (ans == -1) ans = LONG_LONG_MAX;
    else ans *= w;
    ll L = LONG_LONG_MAX;
    ll R = LONG_LONG_MAX;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (dist[0][x][y] != -1 && a[x][y] > 0) {
                chkmin(L, (ll)dist[0][x][y] * w + a[x][y]);
            }
            if (dist[1][x][y] != -1 && a[x][y] > 0) {
                chkmin(R, (ll)dist[1][x][y] * w + a[x][y]);
            }
        }
    }
    if (max(L, R) < LONG_LONG_MAX) {
        chkmin(ans, L + R);
    }
    if (ans == LONG_LONG_MAX) ans = -1;
    cout << ans << endl;
    return 0;
}