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
bool clearRow[1000], clearCol[1000], visited[1000][1000];
string grid[1000];

void dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || grid[r][c] == '.')
        return;

    visited[r][c] = true;
    for (int i=0; i<4; i++)
        dfs(r + dr[i], c + dc[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> grid[i];

    for (int i=0; i<n; i++) {
        int cnt = 0;
        for (int j=0; j<m; j++)
            if (grid[i][j] == '#') {
                cnt++;
                while (j < m - 1 && grid[i][j+1] == '#')
                    j++;
            }
        if (cnt >= 2) {
            cout << "-1\n";
            return 0;
        }
        clearRow[i] = (cnt == 0);
    }

    for (int j=0; j<m; j++) {
        int cnt = 0;
        for (int i=0; i<n; i++)
            if (grid[i][j] == '#') {
                cnt++;
                while (i < n - 1 && grid[i+1][j] == '#')
                    i++;
            }
        if (cnt >= 2) {
            cout << "-1\n";
            return 0;
        }
        clearCol[j] = (cnt == 0);
        if (clearCol[j]) {
            bool ok = false;
            for (int i=0; i<n; i++)
                ok |= clearRow[i];
            if (!ok) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    for (int i=0; i<n; i++)
        if (clearRow[i]) {
            bool ok = false;
            for (int j=0; j<m; j++)
                ok |= clearCol[j];
            if (!ok) {
                cout << "-1\n";
                return 0;
            }
        }

    int ret = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (grid[i][j] == '#' && !visited[i][j]) {
                ret++;
                dfs(i, j);
            }

    cout << ret << "\n";

    return 0;
}