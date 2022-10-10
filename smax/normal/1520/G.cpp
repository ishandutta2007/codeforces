#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, w;
    cin >> n >> m >> w;
    vector<vector<int>> a(n, vector<int>(m));
    vector<pair<int, int>> portals;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
            if (a[i][j] > 0)
                portals.emplace_back(i, j);
        }

    auto ok = [&] (int r, int c) -> bool {
        return 0 <= r && r < n && 0 <= c && c < m && a[r][c] != -1;
    };

    vector<long long> dist(n * m + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    auto relax = [&] (int u, long long d) -> void {
        if (d < dist[u])
            pq.emplace(dist[u] = d, u);
    };

    pq.emplace(dist[0] = 0, 0);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        if (u == n * m) {
            // portal hub
            for (auto [x, y] : portals)
                relax(x * m + y, d + a[x][y]);
        } else {
            int r = u / m, c = u % m;
            for (int i=0; i<4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (ok(nr, nc))
                    relax(nr * m + nc, d + w);
            }
            if (a[r][c] > 0)
                relax(n * m, d + a[r][c]);
        }
    }
    cout << (dist[n * m - 1] == INF ? -1 : dist[n * m - 1]) << "\n";

    return 0;
}