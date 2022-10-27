#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 300000 + 10;
const ll mod = 998244353;
ll fac[N], inv[N];
ll mpow(ll a, ll x) {
    if (x==0)return 1;
    ll t = mpow(a,x>>1);
    if (x%2==0) return t*t%mod;
    return t*t%mod*a%mod;
}

ll c(ll x, ll y) {
    if (y < 0 || y > x) return 0;
    return fac[x] * inv[y] % mod * inv[x-y] % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);

    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; i ++) {
        fac[i] = fac[i-1] * i % mod;
        inv[i] = mpow(fac[i], mod - 2);
    }


    int n, m;
    cin >> n >> m;
    vector<ll> d(n);
    for (int i = 0; i < n; i ++) {
        cin >> d[i];
    }
    ll tot = accumulate(d.begin(), d.end(), 0ll);
    if (tot % 2 == 1) {
        cout << mpow(m, n) << "\n";
        return 0;
    }
    for (int i = 0; i < n; i ++) d.push_back(d[i]);    
    vector<ll> sum(2 * n, 0);
    sum[0] = d[0];
    for (int i = 1; i < 2 * n; i ++) {
        sum[i] = sum[i-1] + d[i]; 
    }

    map<ll, int> mp;
    for (auto x: sum) mp[x] = 0; mp[0] = 0;
    int g2 = 0, g1 = 0;

    for (int i = 0; i < n; i ++) {
        if (mp.count( (i>=1?sum[i-1]:0) + tot / 2)) {
            g2 ++;
        }
    }
    g2 /= 2;
    g1 = n - 2 * g2;
    //cout << g1 << " " << g2 << "\n";
    ll ans = 0;
    for (int i = 0; i <= g2; i ++) {
        if (i > m) break;
        ll tmp1 = c(g2, i) * c(m, i) % mod * fac[i] % mod;
        int rem = m - i;

        ll tmp2 = mpow(1ll * rem * (rem - 1) % mod, g2 - i) * mpow(rem, g1) % mod;
        //printf("i=%lld,tmp1=%lld,tmp2=%lld\n",i,tmp1,tmp2);
        ans += tmp1 * tmp2 % mod;
        ans %= mod;
    }
    cout << ans <<"\n";
}