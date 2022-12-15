#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 3;
const int k_Inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;

        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < n - 1; ++i){
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

       function<int(int, int)> dfs = [&](int u, int p){
            if(u == b) return 0;

            int ans = k_Inf;
            for(int to: adj[u]){
                if(to == p) continue;
                ans = min(ans, dfs(to, u) + 1);
            }

            return ans;
        };

        int diam = 0;
        function<int(int, int)> find_diam = [&](int u, int p){
            int best = 0;
            for(int to: adj[u]){
                if(to == p) continue;
                int c = find_diam(to, u) + 1;
                diam = max(diam, best + c);
                best = max(best, c);
            }
            return best;
        };

        int dist = dfs(a, -1);
        find_diam(1, -1);

        if(dist <= da) cout << "Alice\n";
        else if(diam <= 2 * da) cout << "Alice\n";
        else if(db <= 2 * da) cout << "Alice\n";
        else cout << "Bob\n";
    }
}