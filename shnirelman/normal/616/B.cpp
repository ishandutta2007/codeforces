#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int cur = a[i][0];
        for(int j = 1; j < m; j++)
            cur = min(cur, a[i][j]);

        ans = max(ans, cur);
    }

    cout << ans;
}