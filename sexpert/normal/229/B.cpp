#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 10;
vector<int> bad[MAXN];
int di[MAXN], pr[MAXN];
vector<ii> adj[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for(int u = 1; u <= n; u++) {
        int k;
        cin >> k;
        while(k--) {
            int t;
            cin >> t;
            bad[u].push_back(t);
        }
    }

    fill(di, di + MAXN, INT_MAX);
    priority_queue<ii, vector<ii>, greater<ii>> q;
    di[1] = 0;
    q.push({0, 1});
    while(q.size()) {
        auto p = q.top(); q.pop();
        int u = p.second, d = p.first;
        if(u == n)
            break;
        if(pr[u] || d > di[u])
            continue;
        for(int i = 0; i < bad[u].size(); i++) {
            if(bad[u][i] == di[u]) {
                int j = i;
                while(j + 1 < bad[u].size() && bad[u][j + 1] == bad[u][j] + 1)
                    j++;
                di[u] = bad[u][j] + 1;
                break;
            }
        }
        for(auto e : adj[u]) {
            int v = e.first, w = e.second;
            if(di[v] > di[u] + w) {
                di[v] = di[u] + w;
                q.push({di[v], v});
            }
        }
        pr[u] = 1;
    }
    cout << (di[n] == INT_MAX ? -1 : di[n]) << '\n';
}