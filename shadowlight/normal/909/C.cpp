#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n;
    cin >> n;
    vector <ll> dp(n + 1, 0);
    dp[0] = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        vector <ll> ndp(n + 1, 0);
        char c;
        cin >> c;
        if (c == 'f') {
            for (int j = 0; j < n; j++) {
                ndp[j + 1] = dp[j];
            }
        } else {
            ll sum = 0;
            for (int j = n; j >= 0; j--) {
                sum += dp[j];
                if (sum >= INF) {
                    sum -= INF;
                }
                ndp[j] += sum;
                if (ndp[j] >= INF) {
                    ndp[j] -= INF;
                }
            }
        }
//        for (int j = 0; j <= n; j++) {
//            cout << ndp[j] << " ";
//        }
//        cout << "\n";
        dp = ndp;
    }
    cout << dp[0];
}