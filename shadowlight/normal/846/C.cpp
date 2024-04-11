#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
const ll MAXN = 1e6 + 7;
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
    vector <ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <vector <ll> > dp(n + 1, vector <ll> (4, -INF));
    vector <vector <ll> > pred(n + 1, vector <ll> (4, -1));
    for (ll i = 0; i < 4; i++) {
        dp[0][i] = 0;
        pred[0][i] = 0;
    }
    for (ll i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + a[i - 1];
        pred[i][0] = pred[i - 1][0];
        for (ll j = 1; j < 4; j++) {
            ll val = a[i - 1] * (j % 2 ? -1 : 1);
            if (dp[i - 1][j] > dp[i - 1][j - 1]) {
                dp[i][j] = dp[i - 1][j] + val;
                pred[i][j] = pred[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j - 1] + val;
                pred[i][j] = i - 1;
            }
        }
        for (ll j = 1; j < 4; j++) {
            if (dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                pred[i][j] = i;
            }
        }
    }
    vector <ll> res;
    ll now = n;
    for (ll i = 3; i > 0; i--) {
        now = pred[now][i];
        //cout << dp[i - 1][now] << "\n";
        res.push_back(now);
    }
    reverse(res.begin(), res.end());
    for (ll x : res) {
        cout << x << " ";
    }
}