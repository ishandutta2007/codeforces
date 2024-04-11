#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int n, m, sz, dist[1000][1000];
bool grid[1000][1000], visited[1000][1000], inComp[1000][1000];
pair<int, int> match[1000][1000];

void dfs(int r, int c, bool color) {
    if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || grid[r][c] != color)
        return;

    visited[r][c] = true;
    sz++;
    for (int i=0; i<4; i++)
        dfs(r + dr[i], c + dc[i], color);

    if (sz > 1)
        inComp[r][c] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> n >> m >> t;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++)
            grid[i][j] = (s[j] == '1');
    }

    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            sz = 0;
            dfs(i, j, grid[i][j]);
            if (inComp[i][j]) {
                dist[i][j] = 0;
                q.push({i, j});
                match[i][j] = {i, j};
            }
        }

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
                match[nr][nc] = match[r][c];
            }
        }
    }

    while (t--) {
        int i, j;
        long long p;
        cin >> i >> j >> p;
        i--, j--;

        if (dist[i][j] == -1 || p < dist[i][j])
            cout << grid[i][j] << "\n";
        else
            cout << (grid[match[i][j].first][match[i][j].second] ^ (p % 2)) << "\n";
    }

    return 0;
}