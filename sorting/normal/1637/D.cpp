#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll N = 100 + 3;

ll n, a[N], b[N];
ll dp[N][2 * N * N + 10];

ll& getDP(ll pos, ll sum){
    return dp[pos][sum + N * N + 3];
}

void solve(){
    cin >> n;
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
    for(ll i = 1; i <= n; ++i)
        cin >> b[i];

    ll sum = 0;
    for(ll i = 1; i <= n; ++i)
        sum += a[i];
    for(ll i = 1; i <= n; ++i)
        sum += b[i];

    for(ll i = -N * N; i <= N * N; ++i)
        getDP(n + 1, i) = abs(i);

    for(ll i = n; i >= 1; --i){
        for(ll curr_sum = -N * N; curr_sum <= N * N; ++curr_sum){
            ll &ans = getDP(i, curr_sum);
            ans = N * N;
            check_min(ans, getDP(i + 1, curr_sum + a[i] - b[i]));
            check_min(ans, getDP(i + 1, curr_sum + b[i] - a[i]));
        }
    }

    ll k = getDP(1, 0);
    // cout << k << " k\n";
    ll sum1 = (ll)((sum + k) / 2);
    ll sum2 = (ll)((sum + k) / 2 - k);

    // cout << sum1 << " " << sum2 << endl;

    ll ans = sum1 * sum1 + sum2 * sum2;
    for(int i = 1; i <= n; ++i){
        ans -= a[i] * a[i] + b[i] * b[i];
        ans += (n - 1) * (a[i] * a[i] + b[i] * b[i]);
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
        solve();
}