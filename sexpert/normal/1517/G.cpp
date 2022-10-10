#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;
map<ii, int> idx;

const int MAXN = 2020;
const int INF = 1e9 + 10;

struct edge {
    int to, rev;
    ll f, cap;
};

vector<edge> adj[MAXN];

void add_edge(int u, int v, int c) {
    edge a({v, (int)adj[v].size(), 0, c});
    edge b({u, (int)adj[u].size(), 0, 0});
    adj[u].push_back(a);
    adj[v].push_back(b);
}

int dis[MAXN], ptr[MAXN], src, snk;

bool bfs() {
    memset(dis, -1, sizeof dis);
    queue<int> q({src});
    dis[src] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto e : adj[u]) {
            int v = e.to;
            if(dis[v] == -1 && e.f < e.cap) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[snk] != -1;
}

ll dfs(int s, ll f) {
    if(s == snk || !f)
        return f;
    for(int &i = ptr[s]; i < adj[s].size(); i++) {
        auto &e = adj[s][i];
        int v = e.to;
        if(dis[v] != dis[s] + 1)
            continue;
        if(ll df = dfs(v, min(f, e.cap - e.f))) {
            e.f += df;
            adj[e.to][e.rev].f -= df;
            return df;
        }
    }
    return 0;
}

ll mf() {
    ll res = 0;
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        while(ll df = dfs(src, INF))
            res += df;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<ii> ps;
    int n;
    cin >> n;

    vector<array<int, 3>> inp;
    ll tot = 0;

    for(int i = 0; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        ps.insert({x, y});
        inp.push_back({x, y, w});
        idx[{x, y}] = i;
        tot += w;
    }

    src = 2*n;
    snk = 2*n + 1;

    for(auto &[x, y, w] : inp) {
        int id = idx[{x, y}];
        add_edge(id, id + n, w);
        int xp = abs(x) % 2, yp = abs(y) % 2;
        if(xp) {
            if(yp) {
                // (1, 1)
                add_edge(id + n, snk, INF);
            }
            else {
                // (1, 0)
                add_edge(src, id, INF);
                if(ps.count({x + 1, y}))
                    add_edge(id + n, idx[{x + 1, y}], INF);
                if(ps.count({x - 1, y}))
                    add_edge(id + n, idx[{x - 1, y}], INF);
            }
        } else {
            if(yp) {
                // (0, 1)
                if(ps.count({x + 1, y}))
                    add_edge(id + n, idx[{x + 1, y}], INF);
                if(ps.count({x - 1, y}))
                    add_edge(id + n, idx[{x - 1, y}], INF);
            }
            else {
                // (0, 0)
                if(ps.count({x, y + 1}))
                    add_edge(id + n, idx[{x, y + 1}], INF);
                if(ps.count({x, y - 1}))
                    add_edge(id + n, idx[{x, y - 1}], INF);
            }
        }
    }

    cout << tot - mf() << '\n';
}