#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
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
    ll n, c;
    cin >> n >> c;
    vector <ll> dp(n + 1, 0);
    vector <ll> a(n + 1, 0);
    multiset <ll> all;
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
        dp[i] = dp[i - 1] + x;
        sum += x;
        all.insert(x);
        if (i > c) {
            sum -= a[i - c];
            all.erase(all.find(a[i - c]));
        }
        if (i >= c) {
            dp[i] = min(dp[i], dp[i - c] + sum - *all.begin());
        }
    }
    cout << dp[n];
}