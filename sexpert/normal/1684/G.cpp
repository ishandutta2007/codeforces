#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> v(n), taken(n);

    vector<int> big, small;
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(3LL * v[i] > m)
            big.push_back(i);
        else
            small.push_back(i);
    }

    for(int i = 0; i < n; i++) {
        if(2LL * v[i] + 1 > m) {
            cout << "-1\n";
            return 0;
        }
    }

    src = n;
    dst = n + 1;
    nod = dst + 1;
    int bigs = big.size();

    for(int i = 0; i < big.size(); i++) {
        for(int j = 0; j < small.size(); j++) {
            ll a = v[big[i]], b = v[small[j]];
            if(b + 2LL * a > m)
                continue;
            if(a % b != 0)
                continue;
            add_edge(i, bigs + j, 1);
        }
    }

    for(int i = 0; i < big.size(); i++)
        add_edge(src, i, 1);

    for(int i = 0; i < small.size(); i++)
        add_edge(bigs + i, dst, 1);

    int mf = maxflow();
    if(mf != bigs) {
        cout << "-1\n";
        return 0;
    }

    vector<array<ll, 2>> ans;
    for(int i = 0; i < bigs; i++) {
        for(auto &e : adj[i]) {
            if(e.f > 0) {
                ll a = big[i];
                ll b = small[e.to - bigs];
                taken[a] = 1;
                taken[b] = 1;
                a = v[a];
                b = v[b];
                ans.push_back({b + a, b + 2*a});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(!taken[i]) {
            ans.push_back({3LL * v[i], 2LL * v[i]});
        }
    }

    cout << ans.size() << '\n';
    for(auto &[a, b] : ans) {
        cout << a << " " << b << '\n';
    }
}