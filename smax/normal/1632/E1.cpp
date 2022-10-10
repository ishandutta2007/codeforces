#include <bits/stdc++.h>
using namespace std;

int dist[3005];
vector<int> adj[3005];

void dfs1(int u, int p) {
    for (int v : adj[u])
        if (v != p) {
            dist[v] = dist[u] + 1;
            dfs1(v, u);
        }
}

int m;

pair<int, int> dfs2(int u, int p) {
    pair<int, int> ret(INT_MIN, INT_MIN);
    if (dist[u] > m)
        ret = {0, u};
    for (int v : adj[u])
        if (v != p) {
            auto cur = dfs2(v, u);
            cur.first++;
            ret = max(ret, cur);
        }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            adj[i].clear();
        for (int i=0; i<n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs1(0, -1);
        m = 1;
        for (int x=1; x<=n; x++) {
            while (true) {
                int u = dfs2(0, -1).second;
                if (u == INT_MIN)
                    break;
                int d = (dfs2(u, -1).first + 1) / 2;
                if (d + x <= m)
                    break;
                m++;
            }
            cout << m << " ";
        }
        cout << "\n";
    }

    return 0;
}