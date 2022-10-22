#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for(int i = 0; i  < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
            
    for(int i = 0; i  < n; i++)
        for(int j = 0; j < m; j++)
            cin >> b[i][j];
          
    bool ans = true;
    
    for(int i = 0; i < n; i++) {
        int cur = 0;
        for(int j = 0; j < m; j++)
            cur += (a[i][j] != b[i][j]);
        
        ans &= (cur % 2 == 0);
    }
    
    for(int j = 0; j < m; j++) {
        int cur = 0;
        for(int i = 0; i < n; i++)
            cur += (a[i][j] != b[i][j]);
        
        ans &= (cur % 2 == 0);
    }
        
    cout << (ans ? "YES" : "NO");
}