#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> rct(n), cct(m);
    vector<vector<char>> board(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            cin >> board[i][j];
            if(board[i][j] == '*')
                rct[i]++, cct[j]++;
        }
    }

    int ans = 1e9;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '.')
                ans = min(ans, n + m - 1 - rct[i] - cct[j]);
            else
                ans = min(ans, n + m - 1 - rct[i] - cct[j] + 1);
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