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

int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};
string ds = "DLRU";

int dist[1000][1000], pred[1000][1000];
string grid[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    int sr = -1, sc = -1;
    for (int i=0; i<n; i++) {
        cin >> grid[i];
        for (int j=0; j<m; j++)
            if (grid[i][j] == 'X')
                sr = i, sc = j;
    }

    if (k % 2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    auto ok = [&] (int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < m && grid[r][c] != '*';
    };

    memset(dist, 127, sizeof(dist));
    queue<pair<int, int>> q;
    dist[sr][sc] = 0;
    q.push({sr, sc});
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (ok(nr, nc) && (dist[r][c] + 1 < dist[nr][nc] || (dist[r][c] + 1 == dist[nr][nc] && 3 - i < pred[nr][nc]))) {
                dist[nr][nc] = dist[r][c] + 1;
                pred[nr][nc] = 3 - i;
                q.push({nr, nc});
            }
        }
    }

    int r = sr, c = sc;
    while (k > 0) {
        int dir = -1;
        for (int i=0; i<4; i++)
            if (ok(r + dr[i], c + dc[i])) {
                dir = i;
                break;
            }
        if (dir == -1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        r += dr[dir];
        c += dc[dir];
        cout << ds[dir];
        k--;
        if (dist[r][c] == k) {
            while (r != sr || c != sc) {
                dir = pred[r][c];
                cout << ds[dir];
                r += dr[dir];
                c += dc[dir];
            }
            k = 0;
        }
    }
    cout << "\n";

    return 0;
}