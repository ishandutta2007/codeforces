#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> ii;

const int MAXN = 2005;
const ll INF = 1e18;
vector<pair<int, ll>> adj[MAXN];
ll dis[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll mi = INF;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            ll w;
            cin >> w;
            mi = min(mi, w);
            adj[i].push_back({i + j, w});
            adj[i + j].push_back({i, w});
        }
        
    }
    for(int i = 1; i <= n; i++) {
        ll sw = INF;
        for(auto &x : adj[i]) {
            x.second -= mi;
            sw = min(sw, 2LL * x.second);
        }
        //for(auto x : adj[i])
        //    cout << i << " " << x.first << " " << x.second << endl;
        adj[0].push_back({i, sw});
        //cout << 0 << " " << i << " " << sw << endl;
    }
    fill(dis, dis + MAXN, INF);
    priority_queue<ii, vector<ii>, greater<ii>> q;
    dis[0] = 0;
    q.push({0, 0}); 
    while(q.size()) {
        auto p = q.top(); q.pop();
        int u = p.second;
        if(dis[u] < p.first)
            continue;
        for(auto e : adj[u]) {
            int v = e.first; ll w = e.second;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << dis[i] + mi * (n - 1) << '\n';
}