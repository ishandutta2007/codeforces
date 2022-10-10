#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 200;
const int INF = 1e9;

struct edge {
    int to, rev, f, cap;
};
vector<edge> adj[MAXN];

void addEdge(int u, int v, int cap) {
    //cout << u << "->" << v << " with cap " << cap << endl;
    edge a = {v, (int)adj[v].size(), 0, cap};
    edge b = {u, (int)adj[u].size(), 0, 0};
    adj[u].push_back(a);
    adj[v].push_back(b);
}

int dis[MAXN], ptr[MAXN], dst, src;

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
    if(u == dst || !f) return f;
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
        edge &e = adj[u][i];
        int v = e.to;
        if(dis[v] != dis[u] + 1) continue;
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

set<int> pf;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    src = n + 1, dst = n + 2;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<ii> edges(m);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if(v % 2) swap(u, v);
        edges[i] = {u, v};
    }
    for(auto x : a) {
        int k = x;
        for(int d = 2; d * d <= x; d++) {
            if(k % d) continue;
            pf.insert(d);
            while(k % d == 0) k /= d;
        }
        if(k > 1)
            pf.insert(k);
    }
    ll ans = 0;
    for(int p : pf) {
        //cout << p << endl;
        for(int i = 0; i < 200; i++)
            adj[i].clear();
        for(int i = 1; i <= n; i++) {
            int ct = 0, x = a[i - 1];
            while(x % p == 0) {
                x /= p;
                ct++;
            }
            if(ct) {
                if(i % 2) addEdge(src, i, ct);
                else addEdge(i, dst, ct);
            }
        }
        for(auto p : edges)
            addEdge(p.first, p.second, 100);
        ans += mf();
    }
    cout << ans << endl;
}