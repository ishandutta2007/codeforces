#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 200000 + 13;
const int M = 998244353;
const int B = 600;

/*
*/

//void solve() {
//}

int sum(int a, int b) {
    a += b;
    if(a >= M)
        return a - M;
    return a;
}

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();

    int n;
    cin >> n;

    vector<pair<bool, int>> a(n);
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if(c == '+') {
            cin >> a[i].s;
            a[i].f = true;
        } else {
            a[i].f = false;
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) if(a[i].f) {
        int pw = 1;
        vector<bool> b;
        for(int j = 0; j < n; j++) {
            if(j != i && (j < i || a[j].f && a[j].s >= a[i].s))
                pw = pw * 2ll % M;
//                cout << i << ' ' << j << endl;
            else if(i != j)
                b.push_back(a[j].f);
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k <= n; k++) {
                if(i != j)
                    dp[j + 1][k] = sum(dp[j + 1][k], dp[j][k]);
                if(a[j].f) {
                    if(a[j].s > a[i].s || a[j].s == a[i].s && j >= i)
                        dp[j + 1][k] = sum(dp[j + 1][k], dp[j][k]);
                    else if(k + 1 <= n)
                        dp[j + 1][k + 1] = sum(dp[j + 1][k + 1], dp[j][k]);
                } else {
                    if(k > 0)
                        dp[j + 1][k - 1] = sum(dp[j + 1][k - 1], dp[j][k]);
                    else if(j < i)
                        dp[j + 1][0] = sum(dp[j + 1][0], dp[j][0]);
                }
            }
        }

//        vector<vector<int>> dp(b.size() + 1, vector<int>(b.size() + 1, 0));
//        dp[0][0] = 1;
//        for(int j = 0; j < b.size(); j++) {
//            for(int k = 0; k < dp[j].size(); k++) {
//                dp[j + 1][k] = sum(dp[j + 1][k], dp[j][k]);
//                if(b[j]) {
//                    if(k + 1 < dp[j].size())
//                        dp[j + 1][k + 1] = sum(dp[j + 1][k + 1], dp[j][k]);
//                } else {
//                    if(k > 0)
//                        dp[j + 1][k - 1] = sum(dp[j + 1][k - 1], dp[j][k]);
//                }
//            }
//        }

        int res = 0;
        for(int j = 0; j <= n; j++)
            res = sum(res, dp.back()[j]);

//        cout << i << ' ' << res << ' ' << pw << endl;

//        ans = sum(ans, res * 1ll * pw % M * 1ll * a[i].s % M);
        ans = sum(ans, res * 1ll * a[i].s % M);
    }

    cout << ans << endl;
}