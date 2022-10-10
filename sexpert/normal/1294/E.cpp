#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    int ans = 0;
    for(int col = 0; col < m; col++) {
        vector<int> cnt(n);
        int mn = n + 1;
        for(int i = 0; i < n; i++) {
            if(grid[i][col] % m != (col + 1) % m)
                continue;
            int x = (grid[i][col] - 1) / m;
            if(x > n - 1)
                continue;
            cnt[(i - x + n) % n]++;
        }
        for(int i = 0; i < n; i++)
            mn = min(mn, i + n - cnt[i]);
        ans += mn;
    }
    cout << ans << '\n';
}