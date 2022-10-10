#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e5 + 10;
const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
ll fac[MAXN], ifac[MAXN], inv[MAXN], n, k;

ll binom(ll n, ll k) {
    if(k < 0 || k > n)
        return 0;
    ll res = (fac[n] * ifac[k]) % mod;
    return (res * ifac[n - k]) % mod;
}


ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

typedef vector<ll> vl;
void ntt(vl &a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vl rt(2, 1);
    for (static int k = 2, s = 2; k < n; k *= 2, s++) {
        rt.resize(n);
        ll z[] = {1, modpow(root, mod >> s)};
        rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
            ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
            a[i + j + k] = ai - z + (z > ai ? mod : 0);
            ai += (ai + z >= mod ? z - mod : z);
        }
}
vl conv(const vl &a, const vl &b) {
    if (a.empty() || b.empty()) return {};
    int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
    int inv = modpow(n, mod - 2);
    vl L(a), R(b), out(n);
    L.resize(n), R.resize(n);
    ntt(L), ntt(R);
    rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
    ntt(out);
    return {out.begin(), out.begin() + s};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for(ll k = 1; k < MAXN; k++)
        fac[k] = (k * fac[k - 1]) % mod;

    ifac[MAXN - 1] = modpow(fac[MAXN - 1], mod - 2);
    for(ll i = MAXN - 1; i >= 1; i--) {
        ifac[i - 1] = (i * ifac[i]) % mod;
        inv[i] = (ifac[i] * fac[i - 1]) % mod;
    }

    cin >> n >> k;

    vector<ll> a(k + 1), b(k + 1);
    for(int i = 0; i <= k; i++) {
        if(i % 2)
            a[i] = (-ifac[i] + mod) % mod;
        else
            a[i] = ifac[i];
        b[i] = (modpow(i, k) * ifac[i]) % mod;
    }

    auto f = conv(a, b);

    ll ans = 0;
    ll cur = 1;
    for(ll m = 1; m <= min(k, n + 1); m++) {
        cur = (cur * (n - m + 1)) % mod;
        ll term = (cur * f[m]) % mod;
        term = (term * modpow(n + 1, n - m)) % mod;
        ans = (ans + term) % mod;
    }

    cout << ans << '\n';
}