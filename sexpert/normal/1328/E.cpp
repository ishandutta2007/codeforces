    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
     
    const int MAXN = 2e5 + 10;
    vector<int> adj[MAXN];
    int par[MAXN], h[MAXN], tin[MAXN], tout[MAXN], cur;
     
    void dfs(int s, int p = 0, int he = 0) {
        h[s] = he;
        par[s] = p;
        tin[s] = ++cur;
        for(auto v : adj[s])
            if(v != p)
                dfs(v, s, he + 1);
        tout[s] = cur;
    }
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1);
        while(m--) {
            int k;
            cin >> k;
            vector<int> v(k);
            for(auto &x : v)
                cin >> x;
            sort(v.begin(), v.end(), [](int a, int b) {return h[a] > h[b]; });
            int u = par[v[0]];
            if(u == 0) {
                cout << "YES\n";
                continue;
            }
            bool bad = false;
            for(auto x : v) {
                int y = par[x];
                if(y == 0)
                    continue;
                if(tin[y] > tin[u] || tout[y] < tin[u]) {
                    bad = true;
                    break;
                }
            }
            cout << (bad ? "NO\n" : "YES\n");
        }
    }