#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef vector<int> vi;

const int N = (int)1e6 + 50, M = 10000, K = 12;

int n;
ll a[N];

ll check(ll v) {
    ll rv = v;
    vector<ll> val;

    for (ll i = 1; i * i <= rv; i++) {
        if(rv % i == 0) {
            val.push_back(i);
            if(rv / i != i) val.push_back(rv / i);
        }
    }
    sort(all(val));
    unordered_map<ll, int> mp;
    rep(i, 0, sz(val)) mp[val[i]] = i;
    vector<int> dp(sz(val));

    for (int i = 0; i < n; i++) {
        ll g = __gcd(v, a[i]);
        dp[mp[g]]++;
    }
    for (int i = 0; i < sz(val); i++) {
        for (int j = 0; j < i; j++) dp[j] += dp[i] * (val[i] % val[j] == 0);
    }
    ll res = 0;
    rep(i, 0, sz(val)) {
        if(dp[i] * 2 >= n) res = max(val[i], res);
    }
    return res;
}


mt19937 rng(23333);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i];

    ll res = 1;
    rep(i, 0, 13) {
        int idx = rng() % n;
        ll r0 = check(a[idx]);
        res = max(res, r0);
    }
    cout << res << '\n';


}