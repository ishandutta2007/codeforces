// Megumin

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<bool>> dp(n, vector<bool>(5));
    vector<vector<int>> p(n, vector<int>(5));
    dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = true;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int q = 0; q < 5; ++q) {
                if (j == q) {
                    continue;
                }
                if (a[i] > a[i - 1]) {
                    if (j <= q) {
                        continue;
                    }
                }
                if (a[i] < a[i - 1]) {
                    if (j >= q) {
                        continue;
                    }
                }
                if (dp[i - 1][q]) {
                    dp[i][j] = true;
                    p[i][j] = q;
                }
            }
        }
    }
    int x = -1;
    for (int i = 0; i < 5; ++i) {
        if (dp[n - 1][i]) {
            x = i;
        }
    }
    if (x == -1) {
        cout << -1;
        return 0;
    }
    int y = n - 1;
    vector<int> res;
    while (y > 0) {
        res.emplace_back(x + 1);
        x = p[y][x];
        --y;
    }
    cout << x + 1;
    reverse(res.begin(), res.end());
    for (auto i : res) {
        cout << " " << i;
    }
    return 0;
}