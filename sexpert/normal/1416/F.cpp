#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
string to = "ULRD";
struct edge {
    int to, rev, f, cap;
};
vector<edge> adj[MAXN];

void add_edge(int u, int v, int c) {
    edge a = {v, (int)adj[v].size(), 0, c};
    edge b = {u, (int)adj[u].size(), 0, 0};
    adj[u].push_back(a);
    adj[v].push_back(b);
}

int ptr[MAXN], dis[MAXN], src, dst, nod;

bool bfs() {
    fill(dis, dis + nod, -1);
    queue<int> q({src});
    dis[src] = 0;
    while(q.size() && dis[dst] == -1) {
        int u = q.front(); q.pop();
        for(auto e : adj[u]) {
            if(dis[e.to] == -1 && e.f < e.cap) {
                dis[e.to] = dis[u] + 1;
                q.push(e.to);
            }
        }
    }
    return dis[dst] != -1;
}

int dfs(int u, int f) {
    if(u == dst || !f)
        return f;
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
        auto &e = adj[u][i];
        if(dis[e.to] != dis[u] + 1)
            continue;
        if(int pushed = dfs(e.to, min(f, e.cap - e.f))) {
            e.f += pushed;
            adj[e.to][e. rev].f -= pushed;
            return pushed;
        }
    }
    return 0;
}

int maxflow() {
    int res = 0;
    while(bfs()) {
        fill(ptr, ptr + nod, 0);
        while(int flow = dfs(src, INT_MAX))
            res += flow;
    }
    return res;
}

void solve() {
    int n, m, sz;
    cin >> n >> m;
    sz = n * m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> cost = grid, dem = grid;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];


    nod = sz + 4;
    src = sz + 2;
    dst = sz + 3;
    int fs = sz, ft = sz + 1;

    for(int i = 0; i < nod; i++)
        adj[i].clear();

    auto coord = [&](int i, int j) { return m*i + j; };
    vector<array<int, 4>> edges;
    array<int, 2> cnt = {0, 0};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bool drop = false;
            for(int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if(ni < 0 || ni >= n || nj < 0 || nj >= m)
                    continue;
                if(grid[i][j] > grid[ni][nj])
                    drop = true;
                if(grid[i][j] == grid[ni][nj] && (ni > i || nj > j))
                    edges.push_back({i, j, ni, nj});
            }
            if(!drop)
                dem[i][j] = 1;
            int u = coord(i, j);
            if(dem[i][j]) {
                if((i + j) % 2 == 0) {
                    //cout << "edge s' to " << u << '\n';
                    add_edge(src, u, 1);
                    cnt[0]++;
                }
                else {
                    //cout << "edge " << u << " to t'\n";
                    add_edge(u, dst, 1);
                    cnt[1]++;
                }
            }
            else {
                if((i + j) % 2 == 0) 
                    add_edge(fs, u, 1);
                else
                    add_edge(u, ft, 1);
            }
        }
    }

    add_edge(fs, dst, cnt[0]);
    add_edge(src, ft, cnt[1]);
    add_edge(ft, fs, 4 * sz);

    for(auto &[x1, y1, x2, y2] : edges) {
        int u = coord(x1, y1), v = coord(x2, y2);
        if((x1 + y1) % 2 == 0) {
            //cout << "edge " << x1 << " " << y1 << " -> " << x2 << " " << y2 << '\n';
            add_edge(u, v, 1);
        }
        else {
            //cout << "edge " << x2 << " " << y2 << " -> " << x1 << " " << y1 << '\n';
            add_edge(v, u, 1);
        }
    }

    bool good = true;
    int mf = maxflow();
    //cout << mf << '\n';
    for(auto &e : adj[src]) {
        //cout << e.to << " " << e.f << "/" << e.cap << '\n';
        if(e.f < e.cap)
            good = false;
    }

    if(!good) {
        cout << "NO\n";
        return;
    }
    else
        cout << "YES\n";

    vector<vector<char>> dir(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i + j) % 2)
                continue;
            int u = coord(i, j);
            for(auto &e : adj[u]) {
                int v = e.to;
                if(v >= sz || e.f != e.cap)
                    continue;
                int ni = v/m, nj = v%m;
                cost[i][j] = 1;
                cost[ni][nj] = grid[i][j] - 1;
                if(ni == i + 1) {
                    dir[i][j] = 'D';
                    dir[i + 1][j] = 'U';
                }
                if(ni == i - 1) {
                    dir[i][j] = 'U';
                    dir[i - 1][j] = 'D';
                }
                if(nj == j + 1) {
                    dir[i][j] = 'R';
                    dir[i][j + 1] = 'L';
                }
                if(nj == j - 1) {
                    dir[i][j] = 'L';
                    dir[i][j - 1] = 'R';
                }
                //cout << i << " " << j << " matched with " << v/m << " " << v%m << " " << e.f << " " << e.cap << '\n';
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(cost[i][j])
                continue;
            for(int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if(ni < 0 || ni >= n || nj < 0 || nj >= m)
                    continue;
                if(grid[i][j] > grid[ni][nj]) {
                    dir[i][j] = to[d];
                    cost[i][j] = grid[i][j] - grid[ni][nj];
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << cost[i][j] << " ";
        }
        cout << '\n';
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << dir[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}