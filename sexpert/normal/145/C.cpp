#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool lucky(int x) {
    string s = to_string(x);
    for(auto c : s)
        if(c != '4' && c != '7')
            return false;
    return true;
}

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll fac[MAXN], ifac[MAXN], dp[MAXN];

ll inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k <<= 1) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

ll binom(ll n, ll k) {
    if(k > n)
        return 0;
    ll den = (ifac[k] * ifac[n - k]) % MOD;
    return (fac[n] * den) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for(ll x = 1; x < MAXN; x++)
        fac[x] = (x * fac[x - 1]) % MOD;
    ifac[MAXN - 1] = inv(fac[MAXN - 1]);
    for(ll x = MAXN - 1; x >= 1; x--)
        ifac[x - 1] = (x * ifac[x]) % MOD;
    int n, k;
    ll cnt_u = 0;
    cin >> n >> k;
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(lucky(x))
            cnt[x]++;
        else
            cnt_u++;
    }
    vector<ll> amt;
    for(auto p : cnt)
        amt.push_back(p.second);
    dp[0] = 1;
    for(auto x : amt) {
        for(int m = k; m >= 1; m--)
            dp[m] = (dp[m] + x * dp[m - 1]) % MOD;
    }
    ll ans = 0;
    for(int i = 0; i <= k; i++)
        ans = (ans + dp[i] * binom(cnt_u, k - i)) % MOD;
    cout << ans << '\n';
}