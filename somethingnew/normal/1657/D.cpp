#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
void solve() {
    int n, C;
    cin >> n >> C;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        mp[a] = max(mp[a], b * c);
    }
    vector<int> dp(C + 1, 0);
    for (auto i : mp) {
        for (int j = 0; j <= C; j += i.first) {
            dp[j] = max(dp[j], j / i.first * i.second);
        }
    }
    for (int i = 0; i < C; ++i) {
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, c;
        cin >> x >> c;
        x *= c;
        if (dp[C] <= x) {
            cout << "-1 ";
            continue;
        }
        int l = 0, r = C;
        while (l + 1 < r) {
            int M = (l + r) / 2;
            if (dp[M] > x) {
                r = M;
            } else {
                l = M;
            }
        }
        cout << r << ' ';
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}