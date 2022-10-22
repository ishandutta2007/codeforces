#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e5 + 13;
const int K = 500;
//const int M = 1e5 + 13;
const int A = 26;

int a[N];
li dp[N][K];
li s[N];

/*
1
5
1 1 2 2 3
*/

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    s[0] = 0;
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i - 1];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < K; j++)
            dp[i][j] = -1;
    }

    for(int j = 0; j < K; j++)
        dp[n][j] = -1;
    dp[n][0] = INF64;

    int ans = 1;
    for(int i = n - 1; i >= 0; i--) {
        dp[i][0] = INF64;
//        dp[i][1] = a[i];
//        cout << "dp " << i << ' ' << 1 << ' ' << dp[i][1] << endl;
        for(int j = 1; j < K && i + j <= n; j++) {
            dp[i][j] = dp[i + 1][j];
//            cout << i << ' ' << j << ' ' << dp[i + j][j - 1] << ' ' << s[i + j] - s[i] << endl;
            if(dp[i + j][j - 1] > s[i + j] - s[i]) {
                dp[i][j] = max(dp[i][j], s[i + j] - s[i]);
                ans = max(ans, j);
//                cout << i << ' ' << i + j << ' ' << s[i + j] - s[i] << endl;
            }

//            cout << "dp " << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
//        cout << endl;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}