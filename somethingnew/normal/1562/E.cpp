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
vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}
void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> dp(n, vector<int>(n));
    int mxres = 0;
    for (int i = n - 1; i >= 0; --i) {
        string s2 = s.substr(i);
        vector<int> z = z_function(s2);
        for (int j = i + 1; j < n; ++j) {
            int k = z[j-i];
            if (s2[k] < s[j + k]) {
                dp[i][n-1-i] = max(dp[j][k] + 1, dp[i][n-1-i]);
            } else {
                if (k != 0)
                    dp[i][k-1] = max(dp[j][k] + 1, dp[i][k-1]);
            }
        }
        for (int j = n - 2 - i; j >= 0; --j) {
            dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
        }
    }
    for (auto i : dp)
        for (auto j : i)
            mxres = max(mxres, j);
    cout << mxres + 1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}