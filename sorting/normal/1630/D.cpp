#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 3;
const ll INF = 1e18;

int n, m, a[N], b[N];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int g = 0;
    for(int i = 1; i <= m; ++i){
        cin >> b[i];
        g = __gcd(g, b[i]);
    }

    ll ans = -INF;
    for(int rem = 0; rem <= 1; ++rem){
        ll curr =0;
        for(int i = 1; i <= g; ++i){
            ll dp[2]{0, -INF};
            for(int j = i; j <= n; j += g){
                ll new_dp[2];
                new_dp[0] = max(dp[0] + a[j], dp[1] - a[j]);
                new_dp[1] = max(dp[0] - a[j], dp[1] + a[j]);
                dp[0] = new_dp[0];
                dp[1] = new_dp[1];
            }
            curr += dp[rem];
        }
        check_max(ans, curr);
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}