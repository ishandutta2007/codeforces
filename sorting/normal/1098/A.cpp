#include <bits/stdc++.h>

using namespace std;

const int k_Inf = 1e9 + 7;  

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> s(n + 1), ans(n + 1);

    for(int i = 2; i <= n; ++i){
        int p;
        cin >> p;

        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    for(int i = 1; i <= n; ++i)
        cin >> s[i];

    function<bool(int, int, int)> dfs = [&](int u, int p, int sum){
        if(s[u] != -1 && sum > s[u]) return false;

        if(s[u] == -1){
            ans[u] = k_Inf;
            for(int to: adj[u]){
                if(to == p) continue;
                ans[u] = min(ans[u], s[to] - sum);
            }

            if(ans[u] < 0) return false;
            if(ans[u] == k_Inf) ans[u] = 0;
            s[u] = sum + ans[u];
        }
        else ans[u] = s[u] - sum;

        for(int to: adj[u]){
            if(to == p) continue;
            if(!dfs(to, u, s[u])) return false;
        }

        return true;
    };

    if(!dfs(1, -1, 0)){
        cout << "-1\n";
        return 0;
    }

    /*
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    */

    long long sum = 0;
    for(int i = 1; i <= n; ++i)
        sum += ans[i];

    cout << sum << "\n";
}