#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t;
    string s;
    rep(z, t) {
        cin >> n >> s;
        int ans = n;
        rep(q, 4) {
            vector<int> dp(n + 1, n);
            dp[0] = 0;
            rep(i, n) {
                if (i >= 1)
                    dp[i + 1] = min(dp[i + 1], dp[i - 1] + (s[i] != 'L') + (s[i - 1] != 'R'));
                if (i >= 2)
                    dp[i + 1] = min(dp[i + 1], dp[i - 2] + (s[i] != 'L') + (s[i - 2] != 'R'));
                if (i >= 3)
                    dp[i + 1] = min(dp[i + 1], dp[i - 3] + (s[i] != 'L') + (s[i - 1] != 'L') + (s[i - 2] != 'R') + (s[i - 3] != 'R'));
            }
            ans = min(ans, dp[n]);
            s = s.substr(1) + s.substr(0, 1);
        }
        cout << ans << '\n';
    }
}