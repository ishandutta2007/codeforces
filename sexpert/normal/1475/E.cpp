#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2005;
const ll MOD = 1e9 + 7;
ll fac[MAXN], ifac[MAXN];

ll inv(ll b) {
    ll e = MOD - 2, ans = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
    }
    return ans;
}

ll binom(ll n, ll k) {
    if(k < 0 || k > n)
        return 0;
    ll ans = (fac[n] * ifac[k]) % MOD;
    return (ans * ifac[n - k]) % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n + 1);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int m = n; m >= 1; m--) {
        if(cnt[m] < k)
            k -= cnt[m];
        else {
            cout << binom(cnt[m], k) << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for(ll i = 1; i < MAXN; i++)
        fac[i] = (i * fac[i - 1]) % MOD;

    ifac[MAXN - 1] = inv(fac[MAXN - 1]);
    for(int i = MAXN - 1; i >= 1; i--)
        ifac[i - 1] = (i * ifac[i]) % MOD;

    int t;
    cin >> t;
    while(t--)
        solve();
}