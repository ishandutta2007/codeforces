#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(m));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
            grid[i][j] = (s[j] == '*');
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 1; j + 1 < m; j++) {
            if(grid[i][j] != 1)
                continue;
            grid[i][j] = min({grid[i + 1][j - 1], grid[i + 1][j], grid[i + 1][j + 1]}) + 1;
        }
    }

    int ans = 0; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans += grid[i][j];
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}