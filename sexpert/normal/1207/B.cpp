#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int grid[55][55], target[55][55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> target[i][j];

    vector<pair<int, int>> ans;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(target[i][j] == 1 && target[i + 1][j] == 1 && target[i][j + 1] == 1 && target[i + 1][j + 1] == 1) {
                grid[i][j] = grid[i + 1][j] = grid[i][j + 1] = grid[i + 1][j + 1] = 1;
                ans.push_back({i, j});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] != target[i][j]) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << '\n';
    }
}