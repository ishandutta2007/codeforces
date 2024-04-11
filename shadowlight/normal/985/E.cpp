#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
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
    ll n, k, d;
    cin >> n >> k >> d;
    vector <ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll cnt = 0;
    vector <ll> dp(n + 2, 0);
    dp[0] = 1;
    dp[1] = -1;
    for (ll i = 0; i < n; i++) {
        cnt += dp[i];
        //cout << i << " " << cnt << "\n";
        if (!cnt) {
            continue;
        }
        ll pos = upper_bound(a.begin(), a.end(), a[i] + d) - a.begin();
        ll cnt = pos - (i + k - 1);
        //cout << cnt << "\n";
        if (cnt <= 0) continue;
        dp[i + k]++;
        dp[i + k + cnt]--;
    }
    cnt += dp[n];
    if (cnt) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}