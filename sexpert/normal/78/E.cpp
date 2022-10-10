#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300;
const int INF = 1e9;

struct edge{
    int to, rev, f, cap;
    edge(int to, int rev, int f, int cap) : to(to), rev(rev), f(f), cap(cap) {}
};
vector<edge> adj[MAXN];

void add_edge(int u, int v, int c, int rc = 0) {
    edge a(v, adj[v].size(), 0, c);
    edge b(u, adj[u].size(), 0, rc);
    adj[u].push_back(a);
    adj[v].push_back(b);
}

int dis[MAXN], ptr[MAXN], src, dst;

bool bfs() {
    memset(dis, -1, sizeof dis);
    dis[src] = 0;
    queue<int> q({src});
    while(q.size() && dis[dst] == -1) {
        int u = q.front(); q.pop();
        for(auto e : adj[u]) {
            int v = e.to;
            if(dis[v]==-1 && e.f < e.cap) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[dst] != -1;
}

int dfs(int u, int f) {
    if(u == dst || !f)
           return f;
    for(int &i = ptr[u]; i < adj[u].size(); i++){
        edge &e = adj[u][i];
        int v = e.to;
        if(dis[v] != dis[u] + 1)
                continue;
        if(int df = dfs(v, min(f, e.cap - e.f))) {
            e.f += df;
            adj[v][e.rev].f -= df;
            return df;
        }
    }
    return 0;
}

int mf() {
    int res = 0;
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        while(int df = dfs(src, INF))
            res += df;
    }
    return res;
}

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, m;
typedef vector<vector<int>> grid;
typedef array<int, 2> pa;
grid obs, tim, dii;

void gbfs(int r, int c, grid &dis, bool chk = false) {
    for(int i = 0; i < n; i++)
        fill(dis[i].begin(), dis[i].end(), -1);
    dis[r][c] = 0;
    queue<pa> q;
    q.push({r, c});
    while(q.size()) {
        auto p = q.front(); q.pop();
        if(chk && dis[p[0]][p[1]] == tim[p[0]][p[1]])
        	continue;
        pa r;
        for(int i = 0; i < 4; i++) {
            r = {p[0] + dx[i], p[1] + dy[i]};
            if(r[0] < 0 || r[0] >= n || r[1] < 0 || r[1] >= n || dis[r[0]][r[1]] != -1 || obs[r[0]][r[1]]) 
                continue;
            if(chk && tim[r[0]][r[1]] > -1 && dis[p[0]][p[1]] + 1 > tim[r[0]][r[1]])
            	continue;
            dis[r[0]][r[1]] = dis[p[0]][p[1]] + 1;
            q.push(r);
        }
    }
}

vector<string> lab, rea;

int main() {
    cin >> n >> m;
    lab.resize(n);
    rea.resize(n);
    for(auto &x : lab)
        cin >> x;
    for(auto &x : rea)
        cin >> x;
    obs.assign(n, vector<int>(n));
    tim.assign(n, vector<int>(n));
    dii.assign(n, vector<int>(n));
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		obs[i][j] = (lab[i][j] == 'Y');
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		if(lab[i][j] == 'Z')
    			gbfs(i, j, tim);
    src = 2*n*n + 5;
    dst = src + 1;
    for(int x = 0; x < n; x++) {
    	for(int y = 0; y < n; y++) {
    		if(lab[x][y] == 'Z' || lab[x][y] == 'Y')
    			continue;
    		add_edge(src, n*x + y, lab[x][y] - '0');
    		add_edge(n*n + n*x + y, dst, rea[x][y] - '0');
    		gbfs(x, y, dii, true);
    		for(int xp = 0; xp < n; xp++) {
    			for(int yp = 0; yp < n; yp++) {
    				if(dii[xp][yp] != -1 && dii[xp][yp] <= m) {
    					add_edge(n*x + y, n*n + n*xp + yp, INF);
    				}
    			}
    		}
    	}
    }
    cout << mf() << '\n';
}