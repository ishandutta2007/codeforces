#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

void dfs(int u, int p, int sum, int n, const vector<vector<int>> &adj, vector<int> &ans){
    int k = 0;
    for(int to: adj[u]){
        if(to == p) continue;
        if(sum == -1)
            dfs(to, u, 1, n, adj, ans);
        else
            dfs(to, u, -1, n, adj, ans);
        ++k;
    }
    ans[u] = (k + 1) * sum; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);
        vector<int> ans(n + 1);
        for(int i = 0; i < n - 1; ++i){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 1; i <= n; ++i)
            if(adj[i].size() >= 2){
                ans[i] = -(int)adj[i].size();
                for(int to: adj[i])
                    dfs(to, i, 1, n, adj, ans);
                break;
            }

        for(int i = 1; i <= n; ++i)
            cout << ans[i] << " ";
        cout << "\n";
    }
}