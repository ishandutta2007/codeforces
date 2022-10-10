#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int off = 2002;
ll dp[4005], tdp[4005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    dp[off] = 1;
    for(int i = 0; i < n; i++) {
        for(int d = -n; d <= n; d++) {
            if(v[i] == v[(i + 1) % n])
                tdp[off + d] = (k * dp[off + d]) % MOD;
            else {
                tdp[off + d] = (dp[off + d - 1] + dp[off + d + 1] + (k - 2) * dp[off + d]) % MOD;
            }
        }
        for(int d = -n; d <= n; d++)
            dp[off + d] = tdp[off + d];
    }
    ll ans = 0;
    for(int d = 1; d <= n; d++)
        ans = (ans + dp[off + d]) % MOD;
    cout << ans << '\n';
}