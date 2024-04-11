#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;
int maxd, maxv, dist[MAXN], pre[MAXN], vist[MAXN];
vector<int> adj[MAXN];

void dfs(int s, int p = 0) {
    dist[s] = (p == 0 ? 0 : dist[p] + 1);
    vist[s] = 1;
    pre[s] = p;
    if(dist[s] > maxd) {
        maxd = dist[s];
        maxv = s;
    }
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
    }
}

pair<int, int> diameter(int s) {
    maxd = -1;
    dfs(s);
    int ex = maxv, diam;
    maxd = -1;
    dfs(ex);
    ex = maxv, diam = maxd;
    for(int i = 0; i < diam/2; i++)
        ex = pre[ex];
    return {diam, ex};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int, int>> diams;
    for(int v = 1; v <= n; v++) {
        if(!vist[v])
            diams.push_back(diameter(v));
    }
    sort(diams.rbegin(), diams.rend());
    int ans = diams[0].first;
    for(int i = 1; i < diams.size(); i++)
        ans = max(ans, (ans + 1)/2 + (diams[i].first + 1)/2 + 1);
    cout << ans << endl;
    for(int i = 1; i < n - m; i++)
        cout << diams[0].second << " " << diams[i].second << endl;
}