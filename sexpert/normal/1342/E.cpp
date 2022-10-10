#include <bits/stdc++.h>
#define rep(i, a, b) for(int (i) = a; i < b; i++)
#define sz(x) (int)((x).size())
using namespace std;
typedef long long ll;
 
typedef vector<int> vi;
typedef vector<ll> vl;
const ll mod = (119 << 23) + 1, root = 62;
const int MAXN = 2e5 + 10;
int n;
ll k;
ll fac[MAXN], ifac[MAXN];
vl rt, rev;
 
ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}
 
void ntt(vl& a, vl& rt, vl& rev, int n) {
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
                ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
                a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
                ai += (ai + z >= mod ? z - mod : z);
    }
}
 
vl conv(const vl& a, const vl& b) {
    assert(a.size() == n + 1);
    assert(b.size() == n + 1);
    if (a.empty() || b.empty())
        return {};
    int s = sz(a)+sz(b)-1, B = 32 - __builtin_clz(s), N = 1 << B;
    vl L(a), R(b), out(N);
    L.resize(N), R.resize(N);
    ll inv = modpow(N, mod - 2);
    ntt(L, rt, rev, N); ntt(R, rt, rev, N);
    rep(i,0,N) out[-i & (N-1)] = L[i] * R[i] % mod * inv % mod;
    ntt(out, rt, rev, N);
    vl res(n + 1);
    return {out.begin(), out.begin() + n + 1};
}
 
vl elevate(vl p, int m) {
    vl res = {1};
    res.resize(n + 1);
    for(ll k = 1; k <= m; k *= 2) {
        if(k & m) res = conv(res, p);
        p = conv(p, p);
    }
    //for(auto x : res)
    //    cout << x << " ";
    //cout << endl;
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    fac[0] = 1;
    for(ll i = 1; i < MAXN; i++)
        fac[i] = (i * fac[i - 1]) % mod;
    ifac[MAXN - 1] = modpow(fac[MAXN - 1], mod - 2);
    for(ll i = MAXN - 1; i >= 1; i--)
        ifac[i - 1] = (i * ifac[i]) % mod;

    cin >> n >> k;
    if(k >= n) {
        cout << "0\n";
        return 0;
    }

    int s = (n + 1) + (n + 1) - 1, B = 32 - __builtin_clz(s), N = 1 << B;
    rt.assign(N, 1), rev.assign(N, 0);
    rep(i,0,N) rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
    ll curL = mod / 2, inv = modpow(N, mod - 2);
    for (int k = 2; k < N; k *= 2) {
        ll z[] = {1, modpow(root, curL /= 2)};
        rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
    }

    ll m = n - k;
    vl pol(n + 1);
    for(int i = 1; i <= n; i++)
        pol[i] = ifac[i];
    vl res = elevate(pol, m);
    ll ans = (fac[n] * res[n]) % mod;
    ans = (ans * fac[n]) % mod;
    ans = (ans * ifac[m]) % mod;
    ans = (ans * ifac[n - m]) % mod;
    if(k != 0)
        ans = (2LL * ans) % mod;
    cout << ans << '\n';
}