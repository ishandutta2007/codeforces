#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> ans(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans[i][j] = ((i + j) % 2 ? 'W' : 'B');
        }
    }
    if(m % 2 == 0)
        ans[0][m - 1] = 'B';
    else if(n % 2 == 0)
        ans[n - 1][0] = 'B';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}