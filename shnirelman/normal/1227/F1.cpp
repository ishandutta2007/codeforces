#include <bits/stdc++.h>

#define x first
#define y second

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using li = long long;
using ld = long double;

const int M = 998244353; 
//const li INF = 1e18;
const int INF = 1e9;

int sum(int a, int b) {
    return (a + b) % M;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(k == 1 || n == 1) {
        cout << 0;
        return 0;
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int> (2 * n + 1, 0));
    dp[0][n] = (a[0] == a[1] ? k : k - 2);
    dp[0][n - 1] = dp[0][n + 1] = (a[0] != a[1]);
//    for(int i = 0; i < n - 1; i++)
//        for(int j = 0; j < dp[i].size(); j++) if(dp[i][j] != 0) {
//
//            int d = j - n;
//            //cout << i << ' ' << d << ' ' << dp[i][j] << endl;
//            int l = (i + 1) % n;
//            int l1 = (i + 2) % n;
//            dp[i + 1][j] = sum(dp[i + 1][j], dp[i][j] * 1ll * (a[l] == a[l1] ? k - 1 : k - 2) % M);
//            dp[i + 1][j + 1] = sum(dp[i + 1][j + 1], dp[i][j] * (a[l1] != a[l]));
//            dp[i + 1][j - 1] = sum(dp[i + 1][j - 1], dp[i][j] * (a[l1] != a[l]));
//
////            dp[i][j] = sum();
//        }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < dp[i].size(); j++) {
            int l = (i + 1) % n;
            if(j > 0)
                dp[i][j] = sum(dp[i][j], dp[i - 1][j - 1] * (a[l] != a[i]));
            if(j < dp[i].size() - 1)
                dp[i][j] = sum(dp[i][j], dp[i - 1][j + 1] * (a[l] != a[i]));
            dp[i][j] = sum(dp[i][j], dp[i - 1][j] * 1ll * (a[i] == a[l] ? k : k - 2) % M);
        }
    }

    int ans = 0;
    for(int i = n + 1; i < dp[0].size(); i++)
        ans = sum(ans, dp[n -1][i]);
    cout << ans;
}