#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 500;
const int INF = 1e9 + 10;
struct edge {
    int to, rev, f, cap;
};
vector<edge> adj[MAX];
void addEdge(int u, int v, int cap) {
    edge a = {v, (int)adj[v].size(), 0, cap};
    edge b = {u, (int)adj[u].size(), 0, 0};
    adj[u].push_back(a);
    adj[v].push_back(b);
}
int dis[MAX], ptr[MAX], src, dst;
bool bfs() {
    memset(dis, -1, sizeof dis);
    queue<int> q({src});
    dis[src] = 0;
    while(!q.empty() && dis[dst] == -1) {
        int u = q.front(); q.pop();
        for(auto e : adj[u]) {
            int v = e.to;
            if(dis[v] == -1 && e.f < e.cap) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[dst] != -1;
}
int dfs(int u, int f) {
    if(!f || u == dst)
        return f;
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<array<int, 4>> rects;
    vector<int> xs, ys;
    for(int i = 0; i < m; i++) {
        int p, q, r, s;
        cin >> p >> q >> r >> s;
        p--;
        q--;
        rects.push_back({p, q, r, s});
        xs.push_back(p);
        xs.push_back(r);
        ys.push_back(q);
        ys.push_back(s);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    auto it = unique(xs.begin(), xs.end());
    xs.resize(distance(xs.begin(), it));
    it = unique(ys.begin(), ys.end());
    ys.resize(distance(ys.begin(), it));
    //for(auto x : xs)
    //    cout << x << " ";
    //cout << endl;
    //for(auto y : ys)
    //    cout << y << " ";
    //cout << endl;
    int X = xs.size(), Y = ys.size();
    src = X + Y + 1;
    dst = X + Y + 2;
    for(int i = 0; i < m; i++) {
        int x1 = rects[i][0], x2 = rects[i][2], y1 = rects[i][1], y2 = rects[i][3];
        int xp = 0, yp = 0;
        while(xs[xp] < x1) xp++;
        while(ys[yp] < y1) yp++;
        for(int i = xp; xs[i] < x2; i++) {
            for(int j = yp; ys[j] < y2; j++) {
                addEdge(i, X + j, INF);
            }
        }
    }
    for(int i = 0; i < X - 1; i++)
        addEdge(src, i, xs[i + 1] - xs[i]);
    for(int i = 0; i < Y - 1; i++)
        addEdge(X + i, dst, ys[i + 1] - ys[i]);
    cout << mf() << endl;
}