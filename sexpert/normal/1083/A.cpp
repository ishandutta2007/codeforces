#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5;
int wt[MAXN];
ll path[MAXN], mx = 0;
vector<pair<int, ll>> adj[MAXN];

void dfs(int s, int p = 0) {
    path[s] = wt[s];
    ll best = 0;
    for(auto e : adj[s]) {
        int v = e.first;
        ll w = e.second;
        if(v != p) {
            dfs(v, s);
            best = max(best, path[v] - w);
        }
    }
    path[s] += best;
    bool sbst = false;
    ll tot = 0;
    for(auto e : adj[s]) {
        int v = e.first;
        ll w = e.second;
        if(v == p)
            continue;
        if(!sbst && path[v] - w == best)
            sbst = true;
        else
            tot = max(tot, path[v] - w);
    }
    mx = max(mx, tot + path[s]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> wt[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs(1);
    cout << mx << endl;
}