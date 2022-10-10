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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

typedef tuple<pair<int, int>, int, int, int> node;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    for (int i=0; i<n; i++)
        cin >> grid[i];
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;

    vector<vector<vector<pair<int, int>>>> dist(n, vector<vector<pair<int, int>>>(m, vector<pair<int, int>>(4, {INF, INF})));
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.emplace(dist[x1][y1][0] = {0, 0}, x1, y1, 0);
    while (!pq.empty()) {
        auto [d, r, c, dir] = pq.top();
        pq.pop();
        if (d > dist[r][c][dir])
            continue;
        for (int i=0; i<4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            pair<int, int> nd = i == dir ? make_pair(d.first, d.second + 1) : make_pair(d.first + (d.second > 0), 1);
            if (nd.second == k) {
                nd.first++;
                nd.second = 0;
            }
            if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] == '.' && nd < dist[nr][nc][i])
                pq.emplace(dist[nr][nc][i] = nd, nr, nc, i);
        }
    }

    pair<int, int> ret(INF, INF);
    for (int i=0; i<4; i++)
        ret = min(ret, dist[x2][y2][i]);
    cout << (ret.first == INF ? -1 : ret.first + (ret.second > 0)) << "\n";

    return 0;
}