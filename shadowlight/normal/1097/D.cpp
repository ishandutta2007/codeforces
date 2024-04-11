#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MT = 1e18 + 7;
const ll MAXN = 1e8 + 7;
const double EPS = 1e-6;

ll power(ll a, ll k) {
    if (!k) {
        return 1;
    }
    ll b = power(a, k / 2);
    b = b * b % INF;
    if (k % 2) {
        return a % INF * b % INF;
    } else {
        return b;
    }
}

ll rev(ll a) {
    return power(a, INF - 2);
}

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
    ll n, k;
    cin >> n >> k;
    ll t = 1;
    for (ll i = 2; i <= MAXN; i++) {
        if (i == MAXN && n > 1) {
            i = n;
        }
        ll sum = 0;
        while (n % i == 0) {
            sum++;
            n /= i;
        }
        if (!sum) continue;
        vector <vector <ll> > dp(sum + 1, vector <ll> (k + 1, 0));
        dp[sum][0] = 1;
        for (ll j = 1; j <= k; j++) {
            ll pref = 0;
            for (ll a = sum; a >= 0; a--) {
                pref = (pref + dp[a][j - 1] * rev(a + 1)) % INF;
                dp[a][j] = pref;
//                for (ll b = a; b >= 0; b--) {
//                    dp[b][j] += dp[a][j - 1] * rev(a + 1) % INF;
//                    dp[b][j] %= INF;
//                }
            }
        }
        ll now = 1;
        ll res = 0;
        for (ll a = 0; a <= sum; a++) {
            res += now % INF * dp[a][k] % INF;
            res %= INF;
            now *= i;
        }
        t = t * res % INF;
    }
    cout << t;
}