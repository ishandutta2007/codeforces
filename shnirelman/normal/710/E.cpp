#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18 + 13;
const int N = 1e7 + 1003;
//const int M = 1e5 + 13;
const int A = 26;

li dp[N];

signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    li ans = n * 1ll * x;

    for(int i = 0; i < N; i++)
        dp[i] = i * 1ll * x;

//    dp[0] = 0;
    for(int i = 0; i < 24; i++) {
        for(int j = 1; j < N - 1; j++) {
            dp[j + 1] = min(dp[j + 1], dp[j] + x);
//            if(j * 2 < N)
//                dp[j * 2] = min(dp[j * 2], dp[j] + y);
//            if(j > 0)
            dp[j - 1] = min(dp[j - 1], dp[j] + x);
        }

        for(int j = 0; j * 2 < N; j++) {
            dp[j * 2] = min(dp[j * 2], dp[j] + y);
        }
    }

    cout << dp[n] << endl;

//    map<int, li> dp1, dp2;
//    dp1[1] = x;
//    for(int i = 0; i < 24; i++) {
//        for(auto p : dp1) {
//            li& cur = dp2[p.s + 1];
//            if(cur == 0 || cur)
//        }
//    }
}