#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

const int MAXN = 1e5 + 10;
const ll INF = 1e18;
vector<ii> adj[MAXN];
vector<int> tr[MAXN];
ll dis[MAXN];
vector<ll> routes[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
        tr[x].push_back(0);
        tr[y].push_back(0);
    }
    for(int i = 0; i < k; i++) {
        int s, y;
        cin >> s >> y;
        routes[s].push_back(y);
        adj[1].push_back({s, y});
        tr[1].push_back(1);
        adj[s].push_back({1, y});
        tr[s].push_back(1);
    }
    fill(dis, dis + MAXN, INF);
    dis[1] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, 1});
    while(q.size()) {
        auto p = q.top(); q.pop();
        int u = p.second;
        ll w = p.first;
        if(w > dis[u])
            continue;
        for(auto e : adj[u]) {
            int v = e.first;
            ll w = e.second;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        sort(routes[i].begin(), routes[i].end());
        while(routes[i].size() > 1) {
            routes[i].pop_back();
            ans++;
        }
        if(routes[i].empty())
            continue;
        if(routes[i][0] > dis[i]) {
            ans++;
            continue;
        }
        for(int j = 0; j < adj[i].size(); j++) {
            auto e = adj[i][j];
            if(tr[i][j])
                continue;
            int v = e.first, w = e.second;
            if(dis[v] + w == dis[i]) {
                ans++;
                break;
            }
        }
    }
    cout << ans << '\n';
}