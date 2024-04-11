#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[64], dis[150], par[150];
vector<int> adj[150];

int bfs(int s) {
    memset(dis, -1, sizeof dis);
    memset(par, -1, sizeof par);
    dis[s] = 0;
    int ans = 20000;
    queue<int> q({s});
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if(v != par[u] && dis[v] != -1)
                ans = min(ans, dis[u] + dis[v] + 1);
            if(dis[v] == -1) {
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> v;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if(x)
            v.push_back(x);
    }

    for(auto x : v)
        for(int d = 0; d <= 61; d++)
            if(x & (1LL << d))
                cnt[d]++;

    for(int d = 0; d <= 61; d++) {
        if(cnt[d] >= 3) {
            cout << "3\n";
            return 0;
        }
    }

    int m = v.size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(i != j && (v[i] & v[j])) {
                //cout << i << " -> " << j << '\n';
                adj[i].push_back(j);
            }
        }
    }
    int ans = 20000;
    for(int i = 0; i < m; i++)
        ans = min(ans, bfs(i));

    if(ans == 20000)
        cout << "-1\n";
    else
        cout << ans << '\n';
}