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
        
        if (grid[0][0] == '1') {
            cout << "-1\n";
            continue;
        }
        
        vector<array<int, 4>> ret;
        for (int i=n-1; i>=0; i--)
            for (int j=m-1; j>=0; j--)
                if (grid[i][j] == '1') {
                    if (i > 0) {
                        ret.push_back({i - 1, j, i, j});
                    } else {
                        assert(j > 0);
                        ret.push_back({i, j - 1, i, j});
                    }
                }
        
        cout << ret.size() << "\n";
        for (auto [a, b, c, d] : ret)
            cout << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << "\n";
    }
    
    return 0;
}