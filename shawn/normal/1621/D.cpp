#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector c(2 * n, vector<int>(2 * n));
        LL ans = 0;
        for (int i = 0; i < 2 * n; i += 1)
            for (int j = 0; j < 2 * n; j += 1) {
                cin >> c[i][j];
                if (i >= n and j >= n) ans += c[i][j];
            }
        cout << ans +
            min({c[0][n], c[0].back(), c[n - 1][n], c[n - 1].back(),
                 c[n][0], c[n][n - 1], c.back()[0], c.back()[n - 1]}) << "\n";
    }
    return 0;
}