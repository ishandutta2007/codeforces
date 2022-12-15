#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        set<pair<char, char>> s;
        bool ok = true;
        for(int i = 0; i < n; ++i){
            if(a[i] > b[i]){
                cout << "-1\n";
                ok = false;
                break;
            }
            if(a[i] == b[i]) continue;
            s.insert({a[i], b[i]});
        }

        if(!ok) continue;

        vector<vector<int>> adj(20 + 1);

        for(auto p: s){
            adj[p.first - 'a'].push_back(p.second - 'a');
            adj[p.second - 'a'].push_back(p.first - 'a');
        }

        vector<bool> used(20 + 1);

        function<int(int)> dfs =[&](int u){
            used[u] = true;

            int ans = 1;
            for(int to: adj[u]){
                if(used[to]) continue;
                ans += dfs(to);
            }
            return ans;
        };

        int ans = 0;
        for(int i = 0; i < 20; ++i){
            if(used[i]) continue;
            ans += dfs(i) - 1;
        }

        cout << ans << "\n";
    }
}