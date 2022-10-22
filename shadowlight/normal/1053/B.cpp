#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll N = 107;

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
    vector <ll> cnt(n, 0);
    vector <vector <ll> > dp(n + 1, vector <ll> (2, 0));
    dp[0][0] = 0;
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll now = 0;
        while (x) {
            now += x % 2;
            x /= 2;
        }
        cnt[i] = now;
        if (now % 2) {
            dp[i + 1][1] = dp[i][0] + 1;
            dp[i + 1][0] = dp[i][1];
        } else {
            dp[i + 1][0] = dp[i][0] + 1;
            dp[i + 1][1] = dp[i][1];
        }
        res += dp[i + 1][0];
        //cout << cnt[i] << "\n";
    }
    for (ll i = 0; i < n; i++) {
        ll sum = 0, maxk = 0;
        for (ll j = 0; j < N; j++) {
            if (i + j >= n) break;
            sum += cnt[i + j];
            maxk = max(maxk, cnt[i + j]);
            if (maxk > sum - maxk && sum % 2 == 0) {
                res--;
            }
        }
    }
    cout << res;
}