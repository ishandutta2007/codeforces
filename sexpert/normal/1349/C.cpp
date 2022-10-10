#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1e9;
int nc, n, m, t;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
vector<vector<char>> grid;
vector<vi> vis, cp, d0, d1;
vector<int> sz;

void flood(int x, int y, int c, int tr) {
    cp[x][y] = c;
    sz[c]++;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] - '0' != tr || cp[nx][ny])
            continue;
        flood(nx, ny, c, tr);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> t;
    grid.assign(n, vector<char>(m));
    vis.assign(n, vi(m, -1));
    cp.assign(n, vi(m));
    d0.assign(n, vi(m, INF));
    d1.assign(n, vi(m, INF));
    sz.resize(n*m + 10);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!cp[i][j]) {
                nc++;
                flood(i, j, nc, grid[i][j] - '0');
            }
        }
    }
    queue<ii> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '0' && sz[cp[i][j]] > 1) {
                q.push({i, j});
                d0[i][j] = 0;
            }
        }
    }
    while(q.size()) {
        auto p = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || d0[nx][ny] != INF)
                continue;
            q.push({nx, ny});
            d0[nx][ny] = d0[p.first][p.second] + 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '1' && sz[cp[i][j]] > 1) {
                q.push({i, j});
                d1[i][j] = 0;
            }
        }
    }
    while(q.size()) {
        auto p = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || d1[nx][ny] != INF)
                continue;
            q.push({nx, ny});
            d1[nx][ny] = d1[p.first][p.second] + 1;
        }
    }
    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << d0[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << d1[i][j] << " ";
        }
        cout << endl;
    }*/
    while(t--) {
        int r, c;
        ll ti;
        cin >> r >> c >> ti;
        r--;
        c--;
        if(sz[cp[r][c]] == 1) {
            int ch = min(d0[r][c], d1[r][c]);
            if(ch != INF && ch <= ti)
                cout << (((ll)(grid[r][c] - '0')) ^ ((ti - ch) & 1LL)) << '\n';
            else
                cout << grid[r][c] << '\n';
            continue;
        }
        cout << (((ll)(grid[r][c] - '0')) ^ (ti & 1LL)) << '\n';
    }
}