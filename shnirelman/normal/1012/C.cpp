#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18 + 13;
const int N = 5000 + 13;
const int M = 1e9 + 7;
const int B = 600;

/*
*/

int a[N];
li dp[N][3], dp1[N][3];

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

//    int t = 1;
////    cin >> t;
//
//    while(t--)
//        solve();

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++)
            dp[i][j] = INF;
    }

    dp[0][0] = 0;
    dp[1][1] = 0;
    dp[0][2] = 0;

    int k = (n + 1) / 2;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            dp1[j][2] = dp[j][1] + max(0, - a[i - 1] + a[i] + 1);
            dp1[j][0] = min(dp[j][0], dp[j][2]);
            if(j > 0) {
                dp1[j][1] = dp[j - 1][0] + max(0, - a[i] + a[i - 1] + 1);
                if(j > 1)
                    dp1[j][1] = min(dp1[j][1], dp[j - 1][2] + max(0, - a[i] + 1 + min(a[i - 2] - 1, a[i - 1])));
            }
        }

        for(int j = 0; j <= k; j++) {
            for(int l = 0; l < 3; l++) {
                dp[j][l] = dp1[j][l];
                dp1[j][l] = INF;
//                cout << i << ' ' << j << ' ' << l
            }
//            cout << i << ' ' << j << "   |  " << dp[j][0] << ' ' << dp[j][1] << ' ' << dp[j][2] << endl;
        }
    }

    for(int i = 1; i <= k; i++) {
        cout << min(dp[i][0], min(dp[i][1], dp[i][2])) << ' ';
    }
}