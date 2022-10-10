#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<char>> grid(n, vector<char>(n, '0'));
    cout << ((k % n) ? 2 : 0) << '\n';
    for(int i = 0; i < k; i++) {
        int r = i % n, c = (r + (i / n)) % n;
        grid[r][c] = '1';
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << grid[i][j];
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