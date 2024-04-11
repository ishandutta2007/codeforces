#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
void upd(int &a, int b) {
    a = min(a, b);
}
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    if (k % 2) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << "-1 ";
            }
            cout << '\n';
        }
        return;
    }
    vector<vector<int>> up(n - 1, vector<int>(m)), next(n, vector<int>(m-1));
    for (auto &i : next) {
        for (auto &j : i) {
            cin >> j; j *= 2;
        }
    }
    for (auto &i : up) {
        for (auto &j : i) {
            cin >> j; j *= 2;
        }
    }
    k /= 2;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1)));
    for (int kk = 1; kk <= k; ++kk) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j][kk] = INT_MAX;
                if (i != 0) {
                    upd(dp[i][j][kk], dp[i-1][j][kk-1] + up[i-1][j]);
                }
                if (i != n - 1) {
                    upd(dp[i][j][kk], dp[i+1][j][kk-1] + up[i][j]);
                }
                if (j != 0) {
                    upd(dp[i][j][kk], dp[i][j - 1][kk-1] + next[i][j-1]);
                }
                if (j != m - 1) {
                    upd(dp[i][j][kk], dp[i][j + 1][kk-1] + next[i][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dp[i][j].back() << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}