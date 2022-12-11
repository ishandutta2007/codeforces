#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int NMAX = 1000010;

ll fact[NMAX], invfact[NMAX];

ll modexp(ll b, ll e = MOD -2) {
    if (e == 0) return 1;
    else return modexp(b*b % MOD, e/2) * (e & 1 ? b : 1) % MOD;
}

ll binom(ll n, ll r) {
    if (r < 0 || r > n || n < 0) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

// splits st. b1s have total k elements
ll blockSplitWays(ll n, ll b1, ll b2, ll k) {
    return binom(k-1, b1-1) * binom(n-k-1, b2-1) % MOD; 
}

ll threes(ll n, ll b1, ll b2, ll k, bool freeB2) {
    return modexp(3, k - b1) * modexp(3, (n-k)-b2 + (freeB2 ? 1 : 0)) % MOD;
}

ll solve(ll n, ll k) {
    // all 1c, all 0c

    if (k == 0) return modexp(3, n);
    else if (k == n) return modexp(3, n-1);

    // POSITIVE B:
    // B 1c, B 0c blocks, first bit is 0
    // B 1c, B 0c blocks, first bit is 1
    // B+1 1c, B 0c blocks, first bit is 1
    // B 1c, B+1 0c, first bit is 0
    // first bit 0 => add 1 to the *3 count for 0cs
    // first bit 1 => do not change *3 count for 1cs
    ll ans = 0;
    for (int b = 1; b < n; ++b) {
        ll even1 = blockSplitWays(n, b, b, k) * threes(n, b, b, k, true) % MOD;
        ll even2 = blockSplitWays(n, b, b, k) * threes(n, b, b, k, false) % MOD;
        ll oneside = blockSplitWays(n, b+1, b, k) * threes(n, b+1, b, k, false) % MOD;
        ll zeroside = blockSplitWays(n, b, b+1, k) * threes(n, b, b+1, k, true) % MOD;
        ans = (ans + even1 + even2 + oneside + zeroside) % MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    fact[0] = 1;
    for (int i = 1; i < NMAX; ++i) fact[i] = (fact[i-1] * i) % MOD;
    invfact[NMAX-1] = modexp(fact[NMAX-1]);
    for (int i = NMAX - 2; i >= 0; --i) invfact[i] = (invfact[i+1] * (i+1)) % MOD;
    
    cout << solve(n, k) << endl;
}