#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int n, mod;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> mod;

    ll res = 0;
    vector<ll> dp = {1};
    for (int i = 2; i <= n; i++) {
        rep(j, 1, sz(dp)) (dp[j] += dp[j - 1]) %= mod;
        vector<ll> psum(all(dp));
        rep(j, 1, sz(dp)) (psum[j] += psum[j - 1]) %= mod;
        ll sum = 0, cres = 0;
        rep(x, 0, sz(dp)) {
            if(x - 3 >= 0) sum -= psum[x - 3];
            if(x - i - 1 - 1 >= 0) sum += psum[x - i - 1 - 1];
            if(x - 2 >= 0) (sum += (i - 1) * dp[x - 2]) %= mod;
            (cres += (dp[x] - (x ? dp[x - 1] : 0)) * sum) %= mod;
        }
        rep(j, i + 1, n + 1) (cres *= j) %= mod;
        (res += cres) %= mod;
        ll last = dp.back();
        dp.resize(sz(dp) + (i - 1), last);
        vector<ll> ndp(all(dp));
        for (int j = sz(ndp) - 1; j >= 0; j--) {
            if(j - (i - 1) - 1 >= 0) (ndp[j] -= ndp[j - i]) %= mod;
        }
        dp = ndp;
    }
    cout << (res + mod) % mod << endl;
}