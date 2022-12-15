#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if(n % 2 == 0){
        cout << "First" << endl;
        for(int _ = 0; _ < 2; ++_)
            for(int i = 1; i <= n; ++i)
                cout << i << " ";
        cout << endl;
        return 0;
    }

    cout << "Second" << endl;
    
    vector<int> p(2 * n + 1);
    vector<bool> used(2 * n + 1, false);
    vector<vector<int>> adj(2 * n + 1);

    vector<int> prev(n + 1, -1);
    vector<int> ans(n + 1, -1);

    for(int i = 1; i <= 2 * n; ++i){
        cin >> p[i];
        if(prev[p[i]] == -1)
            prev[p[i]] = i;
        else{
            adj[prev[p[i]]].push_back(i);
            adj[i].push_back(prev[p[i]]);
            //cout << "edge " << i << " " << prev[p[i]] << endl;
        }

        if(i <= n){
            adj[i].push_back(i + n);
            adj[i + n].push_back(i);
            //cout << "edge " << i << " " << i + n << endl;
        }
    }

    function<void(int, bool)> dfs = [&](int u, bool in){
        used[u] = true;
        if(in) ans[p[u]] = u; 

        for(int to: adj[u]){
            if(used[to]) continue;
            dfs(to, !in);
        }
    };

    for(int i = 1; i <= 2 * n; ++i)
        if(!used[i])
            dfs(i, true);

    long long sum = 0;
    for(int i = 1; i <= n; ++i)
        sum += ans[i];

    assert(sum % n == 0);

    if(sum % (2 * n)){
        for(int i = 1; i <= n; ++i)
            ans[i] = -ans[i];
        for(int i = 1; i <= 2 * n; ++i)
            ans[p[i]] += i;
    }

    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
}