#include <bits/stdc++.h>

using namespace std;

const int M = 998244353;

vector<vector<int>> a;
vector<int> used;
int ans, c1, c2;

void dfs(int v, int d) {
    used[v] = d;
    
    if(d == 0)
        c1++;
    else 
        c2++;
    
    for(auto u : a[v]) {
        if(used[u] == -1) 
            dfs(u, d ^ 1);
        else if(used[u] != (d ^ 1))
            ans = 0;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    a.erase(a.begin(), a.end());
    used.erase(used.begin(), used.end());
    ans = 1;
    
    a.resize(n);
    used.resize(n, -1);
    
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        
        v--;
        u--;
        
        a[v].push_back(u);
        a[u].push_back(v);
    }
    
    for(int i = 0; i < n; i++) {
        if(used[i] == -1) {
            c1 = 0, c2 = 0;
            dfs(i, 0);
            int r1 = 1, r2 = 1;
            for(int j = 0; j < c1; j++)
                r1 = r1 * 2 % M;
            for(int j = 0; j < c2; j++)
                r2 = r2 * 2 % M;
            
            ans = ans * 1ll * (r1 + r2) % M;
        }
        
    }
    
    cout << ans << endl;
    
}

int main() {
    int t;
    cin >> t;
    
    while(t--)
        solve();
}