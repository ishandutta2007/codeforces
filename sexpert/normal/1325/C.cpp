#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
map<ii, int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<ii> edges;
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a, b});
    }
    for(int u = 1; u <= n; u++) {
        if(adj[u].size() >= 3) {
            int cur = 0;
            for(auto v : adj[u]) {
                int x = min(u, v), y = max(u, v);
                ans[{x, y}] = cur++;
            }
            for(auto e : edges) {
                int x = min(e.first, e.second), y = max(e.first, e.second);
                if(!ans.count({x, y}))
                    ans[{x, y}] = cur++;
                cout << ans[{x, y}] << '\n';
            }
            return 0;
        }
    }
    for(int i = 0; i < n - 1; i++)
        cout << i << '\n';
}