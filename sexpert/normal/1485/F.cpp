#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;
const ll MOD = 1e9 + 7;
ll dp[MAXN], dp2[MAXN], a[MAXN], pre[MAXN];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = a[i] + pre[i - 1];
    }
    map<ll, ll> su;
    dp[1] = 1;
    dp2[1] = (a[1] == 0);
    su[a[1]] = dp[1] - dp2[1];
    su[0] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = (2LL * dp[i - 1] - dp2[i - 1]) % MOD;
        dp2[i] = su[pre[i]];
        su[pre[i]] = (su[pre[i]] + dp[i] - dp2[i]) % MOD;
    }
    cout << (dp[n] + MOD) % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}