#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
vector<pair<int, int>> e;
int ans = 0;

void get(vector<int> b) {
    if(b.size() == 7) {
        set<pair<int, int>> s;
        for(auto [u, v] : e) {
            pair<int, int> p = {b[v], b[u]};
            if(p.first > p.second)
                swap(p.first, p.second);
                
            s.insert(p);
        }
        
        ans = max(ans, int(s.size()));
    } else {
        for(int i = 1; i <= 6; i++) {
            b.push_back(i);
            get(b);
            b.pop_back();
        }
    }
}

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
        e.emplace_back(v, u);
    }
    
    if(n <= 6) {
        cout << m;
        return 0;
    }
    
    get(vector<int>());
    
    cout << ans;
}