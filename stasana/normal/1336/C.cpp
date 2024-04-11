#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

const ll N = 3001;
const ll MOD = 998'244'353;

ll dp[N][N];

void solve() {
    string s, t;
    cin >> s >> t;
    for (ll i = 0; i <= (ll)s.size(); ++i) {
        dp[0][i] = 1;
    }
    for (ll i = 0; i < (ll)s.size(); ++i) {
        for (ll j = 1; j <= (ll)s.size(); ++j) {
            if (j <= t.size() && s[i] != t[j - 1]) {
                continue;
            }
            dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
        }
        for (ll j = 0; j <= (ll)s.size(); ++j) {
            ll id = i + j;
            if (id < t.size() && t[id] != s[i]) {
                continue;
            }
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
        }
    }
    ll result = 0;
    for (ll i = (ll)t.size(); i <= (ll)s.size(); ++i) {
        result = (dp[i][0] + result) % MOD;
    }
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    solve();
    
    return 0;
}