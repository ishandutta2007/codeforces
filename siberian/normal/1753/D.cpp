#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull  = unsigned long long;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
    if (y < x) {
        x = y;
    }
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) {
        x = y;
    }
}

struct Point{
    int x, y;
    Point() = default;
    Point(int _x, int _y) : x(_x), y(_y) {}
    bool operator<(const Point& other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
};

int n, m;
int P, Q;
vector<vector<char>> a;

bool isIn(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<char> types = {'U', 'R', 'D', 'L'};

int getDir(char x) {
    return find(all(types), x) - types.begin();
}

const ll INF = 1e18;
vector<vector<ll>> dist;

vector<vector<Point>> other;

void build() {
    other.resize(n, vector<Point>(m));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (a[x][y] == '#' || a[x][y] == '.') {
                continue;
            }
            int dir = getDir(a[x][y]) ^ 2;
            other[x][y] = Point(x, y);
            other[x][y].x += dx[dir];
            other[x][y].y += dy[dir];
        }
    }
}

void dijkstra() {
    dist.assign(n, vector<ll>(m, INF));
    set<pair<ll, Point>> q;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (a[x][y] == '.') {
                q.insert({0, Point(x, y)});
                dist[x][y] = 0;
            }
        }
    }
    while (!q.empty()) {
        Point cur = q.begin()->second;
        ll len = q.begin()->first;
        q.erase(q.begin());
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (!isIn(nx, ny)) {
                continue;
            }
            if (a[nx][ny] == '.' || a[nx][ny] == '#') {
                continue;
            }
            Point to = other[nx][ny];
            ll cost = len + Q;
            if (to.x != nx + dx[dir] || to.y != ny + dy[dir]) {
                cost = len + P;
            }
            if (dist[to.x][to.y] <= cost) {
                continue;
            }
            q.erase({dist[to.x][to.y], to});
            dist[to.x][to.y] = cost;
            q.insert({dist[to.x][to.y], to});
        }
    }
}

ll ans;

void calcAns() {
    ans = INF;

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (!isIn(nx, ny)) {
                    continue;
                }
                chkmin(ans, dist[x][y] + dist[nx][ny]);
            }           
        }
    }

    if (ans == INF) {
        ans = -1;
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m;
    cin >> P >> Q;
    a.resize(n, vector<char>(m));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            cin >> a[x][y];
        }
    }
    build();
    dijkstra();
    calcAns();
    cout << ans << endl;
    return 0;
}