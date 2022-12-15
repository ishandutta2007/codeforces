#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> v(m);
        for(int i = 0; i < m; ++i)
            cin >> v[i].first >> v[i].second;

        vector<vector<int>> idx(n + 1);
        for(int i = 0; i < m; ++i){
            idx[v[i].first].push_back(i);
            idx[v[i].second].push_back(i);
        }

        vector<vector<int>> adj(m);
        for(int i = 1; i <= n; ++i)
            if(idx[i].size() == 2 && idx[i][0] != idx[i][1]){
                adj[idx[i][0]].push_back(idx[i][1]);
                adj[idx[i][1]].push_back(idx[i][0]);
            }

        vector<bool> vis(m, false);

        function<bool(int, int)> is_cycle = [&](int x, int par = -1){
            bool ret = false;
            vis[x] = true;
            for(int to: adj[x])
                if(to != par){
                    if(vis[to]) ret = true;
                    else ret |= is_cycle(to, x);
                }
            return ret;
        };

        int ans = m;
        for(int i = 0; i < m; ++i)
            if(!vis[i]){
                bool b_cycle = is_cycle(i, -1);
                ans += b_cycle;
            }
        for(int i = 0; i < m; ++i)
            if(v[i].first == v[i].second)
                --ans;

        cout << ans << "\n";
    }
}