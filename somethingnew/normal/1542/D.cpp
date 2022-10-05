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
#define int long long
using namespace std;
int mod = 998244353;
int solve(vector<int> a, int num) {
    int cntx = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == num)
            cntx++;
    }
    vector<vector<int>> dp(cntx + 1, vector<int>(a.size() + 2));
    dp[0][0] = 1;
    for (auto i : a) {
        if (i == 0) {
            dp[0][0] *= 2;
            dp[0][0] %= mod;
            for (int j = 0; j < dp.size(); ++j) {
                if (j != 0) {
                    dp[j - 1][0] += dp[j][0];
                    dp[j - 1][0] %= mod;
                }
                for (int k = 1; k < dp[0].size(); ++k) {
                    dp[j][k-1] += dp[j][k];
                    dp[j][k-1] %= mod;
                }
            }
        } else if (i == num) {
            for (int j = dp.size() - 1; j > 0; --j) {
                for (int k = 0; k < dp[0].size(); ++k) {
                    dp[j][k] += dp[j - 1][k];
                    dp[j][k] %= mod;
                }
            }
        } else if (i < num) {
            for (int j = dp.size() - 1; j >= 0; --j) {
                for (int k = dp[0].size() - 1; k > 0; --k) {
                    dp[j][k] += dp[j][k - 1];
                    dp[j][k] %= mod;
                }
            }
        } else {
            for (int j = 0; j < dp.size(); ++j) {
                for (int k = 0; k < dp[0].size(); ++k) {
                    dp[j][k] += dp[j][k];
                    dp[j][k] %= mod;
                }
            }
        }
    }
    int res = 0;
    for (int j = 0; j < dp.size(); ++j) {
        for (int k = 0; k < dp[0].size(); ++k) {
            res += dp[j][k] * num % mod * j;
            res %= mod;
        }
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    for (int i = 0; i < n; ++i) {
        char t;
        cin >> t;
        if (t == '-')
            continue;
        cin >> a[i];
        st.insert(a[i]);
    }
    int ans = 0;
    for (auto i : st) {
        ans += solve(a, i);
        ans %= mod;
    }
    cout << ans;
}