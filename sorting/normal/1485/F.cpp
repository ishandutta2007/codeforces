#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 3;
const ll MOD = 1e9 + 7;

int n;
ll b[N], dp[N], prefix[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    for(int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + b[i];

    map<ll, ll> mp_sum;
    ll sum = 0;

    dp[0] = 1;
    sum += dp[0];
    mp_sum[0] += dp[0];

    for(int i = 1; i <= n; ++i){
        dp[i] = sum;
        if(mp_sum.count(prefix[i - 1])){
            dp[i] -= mp_sum[prefix[i - 1]];
            dp[i] %= MOD; 
        }

        sum += dp[i];
        sum %= MOD;

        ll &x = mp_sum[prefix[i - 1]];
        x += dp[i];
        x %= MOD;
    }

    if(sum < 0) sum += MOD;
    cout << sum << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}