#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 3013;
const li INF = 4e18;
const int M = 998244353;

int sum(int a, int b) {
    int res = a + b;

    if(res >= M)
        res -= M;

    return res;
}

int dp[N][N];

void solve() {
    string s, t;
    cin >> s>> t;

    int n = s.length(), m = t.length();

    for(int i = 0; i <= n; i++)
        dp[0][i] = 1;

    int ans = 0;
    for(int i = 0; i < n; i++) {

        for(int j = 0; j <= n; j++) {
//            cout << i << ' ' << j << ' ' << dp[i][j] << endl;

            int l = j - 1;
            int r = j + i;
//            cout << l << ' ' << r << endl;
            if(l > -1 && (l < m && s[i] == t[l] || l >= m))
                dp[i + 1][j - 1] = sum(dp[i + 1][j - 1], dp[i][j]);

            if(r < m && s[i] == t[r] || r >= m)
                dp[i + 1][j] = sum(dp[i + 1][j], dp[i][j]);
        }


    }
//    return;

    for(int i = m; i <= n; i++)
        ans = sum(ans, dp[i][0]);

    cout << ans;
}

/*
1
1 1 1
1
1
1000000000
*/

int main() {
    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}