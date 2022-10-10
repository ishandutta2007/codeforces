#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int n, m, sentinel, visited[100][100];
string grid[100];

bool dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m)
        return 1;   // new ending
    if (visited[r][c])
        return visited[r][c] == sentinel;   // cycle
    visited[r][c] = sentinel;
    if (grid[r][c] == 'C')
        return visited[r][c] == sentinel;
    bool ret = true;
    if (grid[r][c] == 'U')
        ret = dfs(r - 1, c);
    else if (grid[r][c] == 'R')
        ret = dfs(r, c + 1);
    else if (grid[r][c] == 'D')
        ret = dfs(r + 1, c);
    else    // L
        ret = dfs(r, c - 1);
    return ret;
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
        for (int i=0; i<n; i++)
            cin >> grid[i];

        sentinel = 0;
        memset(visited, 0, sizeof(visited));
        int ret = -1;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (!visited[i][j]) {
                    sentinel++;
                    ret += dfs(i, j);
                }
        cout << ret << "\n";
    }

    return 0;
}