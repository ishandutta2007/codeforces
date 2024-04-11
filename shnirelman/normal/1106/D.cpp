#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;

int main() {
    int n, m;
    cin >> n >> m;
    
    a.resize(n);
    
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        
        v--;
        u--;
        
        a[v].push_back(u);
        a[u].push_back(v);
    }
    
    for(int i = 0; i < n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    
    vector<bool> used(n, false);
    set<int> s;
    s.insert(0);
    vector<int> ans;
    while(!s.empty()) {
        int v = *s.begin();
        s.erase(s.begin());
        if(used[v])
            continue;
            
        ans.push_back(v + 1);
            
        used[v] = true;
        
        for(auto u : a[v])
            if(!used[u])
                s.insert(u);
    }
    
    for(auto an : ans)
        cout << an << ' ';
}