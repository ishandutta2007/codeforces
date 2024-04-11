#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<string> grid(n);
    for(auto &s : grid)
        cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        grid[i] += '*';
        int cnt = 0;
        for(int j = 0; j <= m; j++) {
            if(grid[i][j] == '.') {
                cnt++;
                continue;
            }
            if(y >= 2*x)
                ans += cnt*x;
            else {
                ans += (cnt/2) * y;
                ans += (cnt % 2) * x;
            }
            cnt = 0;
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