#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i=0; i<n; i++)
            cin >> grid[i];
        
        vector<vector<bool>> vis(n, vector<bool>(m));
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (grid[i][j] == '1' && !vis[i][j]) {
                    if ((i > 0 && grid[i-1][j] == '1') || (j > 0 && grid[i][j-1] == '1')) {
                        cout << "NO\n";
                        goto done;
                    }
                    int k = i, l = j;
                    while (k < n && grid[k][j] == '1')
                        k++;
                    while (l < m && grid[i][l] == '1')
                        l++;
                    for (int a=i; a<k; a++)
                        for (int b=j; b<l; b++) {
                            if (grid[a][b] == '0' || vis[a][b]) {
                                cout << "NO\n";
                                goto done;
                            }
                            vis[a][b] = true;
                        }
                }
        cout << "YES\n";
        done:;
    }
    
    return 0;
}