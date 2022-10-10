#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to, rev, flow, cap;
    edge(int t, int r, int f, int c) : to(t), rev(r), flow(f), cap(c){}
};

const int MAXN = 1e5 + 10;
const int INF = 1e9 + 7;
vector<edge> adj[MAXN];
int dis[MAXN], ptr[MAXN], src, dst;

void add_edge(int u, int v, int cap, int rcap = 0) {
    edge a(v, adj[v].size(), 0, cap);
    edge b(u, adj[u].size(), 0, rcap);
    adj[u].push_back(a);
    adj[v].push_back(b);
}

bool bfs() {
    memset(dis, -1, sizeof dis);
    dis[src] = 0;
    queue<int> q({src});
    while(q.size() && dis[dst] == -1) {
        int u = q.front(); q.pop();
        for(auto e : adj[u]) {
            int v = e.to;
            if(dis[v] == -1 && e.flow < e.cap) {
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
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
        edge &e = adj[u][i];
        int v = e.to;
        if(dis[v] != dis[u] + 1)
            continue;
        if(int df = dfs(v, min(f, e.cap - e.flow))) {
            e.flow += df;
            adj[v][e.rev].flow -= df;
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

int n, b, q;

int main() {
    src = 20020;
    dst = src + 1;
    cin >> n >> b >> q;
    for(int i = 0; i < 5; i++)
        add_edge(src, i, n/5);
    vector<pair<int, int>> qs;
    while(q--) {
        int x, y;
        cin >> x >> y;
        qs.push_back({x, y});
    }
    qs.push_back({b, n});
    sort(qs.begin(), qs.end());
    int p = 1, tot = 0, ve = 5;
    for(auto q : qs) {
        if(q.second < tot) {
            cout << "unfair\n";
            return 0;
        }
        vector<int> cnt(5);
        add_edge(ve, dst, q.second - tot);
        tot = q.second;
        while(p <= q.first) {
            cnt[p % 5]++;
            p++;
        }
        for(int i = 0; i < 5; i++)
            add_edge(i, ve, cnt[i]);
        ve++;
    }
    cout << (mf() == n ? "fair" : "unfair") << '\n';
}