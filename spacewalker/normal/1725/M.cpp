#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (int i = (x); i < (y); i++)
#define INF 1e18
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> li;
typedef vector<vector<li>> vv;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m; cin >> n >> m;
    vv adj(2 * n + 5);
    rep(i,0,m) {
        int a,b,w; cin >> a >> b >> w;
        a--, b--;
        adj[a].emplace_back(b, w);
        adj[n + b].emplace_back(n + a, w);
    }
    rep(i,0,n) {
        //cout << i << ' ' << n + i << '\n';
        adj[i].emplace_back(n + i, 0);
    }
    //for (auto &i : adj[0]) cout << i.first << ' ' << i.second << '\n';
    priority_queue<li, vector<li>, greater<li>> pq;
    vector<ll> d(2 * n + 5, INF);
    d[0] = 0;
    pq.push({d[0], 0});
    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist != d[u]) continue;
        //cout << "u = " << u << '\n';
        //cout << (int)(adj[u].size()) << '\n';
        for (int i = 0; i < adj[u].size(); i++) {
            auto [v,w] = adj[u][i];
            //if (!u) cout << u << ' ' << v << ' ' << w << '\n';
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                //if (!u) cout << u << ' ' << v << ' ' << w << '\n';
                pq.push({d[v], v});
            }
        }
    }
    //cout << d[5] << '\n';
    rep(i,1,n) {
        if (d[i + n] != INF) cout << d[i + n] << ' ';
        else cout << -1 << ' ';
    }
}