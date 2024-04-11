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

int n, m;
bool visited[50][50];
string grid[50];

bool valid(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < m && grid[r][c] != '#';
}

int dfs(int r, int c, char t) {
    if (!valid(r, c) || visited[r][c])
        return 0;

    visited[r][c] = true;
    return (grid[r][c] == t) + dfs(r - 1, c, t) + dfs(r + 1, c, t) + dfs(r, c - 1, t) + dfs(r, c + 1, t);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int numG = 0, numB = 0;
        for (int i=0; i<n; i++) {
            cin >> grid[i];
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 'G') numG++;
                if (grid[i][j] == 'B') numB++;
            }
        }
        if (numB == 0) {
            memset(visited, false, sizeof(visited));
            cout << (dfs(n - 1, m - 1, 'G') == numG ? "Yes" : "No") << "\n";
            continue;
        }

        bool ok = true;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (grid[i][j] == 'B')
                    for (int d=0; d<4; d++) {
                        int nr = i + dr[d], nc = j + dc[d];
                        if (valid(nr, nc)) {
                            if (grid[nr][nc] == 'G') {
                                ok = false;
                                break;
                            }
                            if (grid[nr][nc] == '.')
                                grid[nr][nc] = '#';
                        }
                    }

        memset(visited, false, sizeof(visited));
        ok &= (dfs(n - 1, m - 1, 'G') == numG);
        memset(visited, false, sizeof(visited));
        ok &= (dfs(n - 1, m - 1, 'B') == 0);
        cout << (ok ? "Yes" : "No") << "\n";
    }

    return 0;
}