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
int solve(vector<int> a, int n) {
    int mod = 998244353;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));
    for (int len = 0; len < n; ++len) {
        for (int i = 0; i + len < n; ++i) {
            int j = i + len;
            int minp = i;
            for (int k = i; k <= j; ++k) {
                if (a[minp] > a[k])
                    minp = k;
            }
            int resl, resr = dp[minp + 1][j];
            if (minp == 0)
                resl = 1;
            else
                resl = dp[i][minp - 1];
            for (int k = minp - 1; k >= i; --k) {
                if (k == 0)
                    resl += dp[k][minp - 1];
                else
                    resl += dp[k][minp - 1] * dp[i][k - 1] % mod;
            }
            for (int k = minp + 1; k <= j; ++k) {
                resr += dp[minp + 1][k] * dp[k + 1][j] % mod;
            }
            resl %= mod;
            resr %= mod;
            dp[i][j] = resl * resr % mod;
        }
    }
    return dp[0][n - 1];
}
int recslv(vector<int> a) {
    int mod = 998244353;
    vector<int> nums(505, -1);
    int l = -1, r = - 1;
    for (int i = 0; i < a.size(); ++i) {
        if (nums[a[i]] != -1) {
            l = nums[a[i]] + 1;
            r = i;
            break;
        }
        nums[a[i]] = i;
    }
    if (l == -1)
        return solve(a, a.size());
    vector<int> b, c;
    for (int i = l; i < r; ++i) {
        b.push_back(a[i]);
        if (a[i] < a[l - 1])
            return 0;
    }
    for (int i = 0; i + 1 < l; ++i) {
        c.push_back(a[i]);
    }
    for (int i = r; i < a.size(); ++i) {
        c.push_back(a[i]);
    }
    return recslv(b) * recslv(c) % mod;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (a.empty() or a.back() != x)
            a.push_back(x);
    }
    if (a.size() > 5000) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < a.size(); ++i) {
        int mn = a[i];
        for (int j = i + 1; j < a.size(); ++j) {
            mn = min(a[j], mn);
            if (a[i] == a[j] and mn < a[i]){
                cout << 0;
                return 0;
            }
        }
    }
    cout << recslv(a);
}