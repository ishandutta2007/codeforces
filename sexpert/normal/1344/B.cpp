#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0}, n, m;
vector<string> grid;
vector<vector<int>> vis;

void dfs(int x, int y) {
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || grid[nx][ny] == '.')
            continue;
        dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    grid.resize(n);
    vis.assign(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        cin >> grid[i];
    int erow = 0, ecol = 0;
    for(int i = 0; i < n; i++) {
        int l = 0, r = m - 1;
        while(l < m && grid[i][l] != '#')
            l++;
        while(r >= 0 && grid[i][r] != '#')
            r--;
        if(l == m) {
            erow = 1;
            continue;
        }
        for(int j = l; j <= r; j++) {
            if(grid[i][j] != '#') {
                cout << "-1\n";
                return 0;
            }
        }
    }
    for(int j = 0; j < m; j++) {
        int u = 0, d = n - 1;
        while(u < n && grid[u][j] != '#')
            u++;
        while(d >= 0 && grid[d][j] != '#')
            d--;
        if(u == n) {
            ecol = 1;
            continue;
        }
        for(int i = u; i <= d; i++) {
            if(grid[i][j] != '#') {
                cout << "-1\n";
                return 0;
            }
        }
    }
    if(erow ^ ecol) {
        cout << "-1\n";
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '#' && !vis[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
}