#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll N = 5000 + 3;

ll n, p, f[N], pwr2[N], inv_f[N];
ll dp[N][N];

ll fast_pow(ll base, ll exp){
    if(!exp) return 1ll;
    if(exp & 1) return base * fast_pow(base, exp - 1) % p;
    ll t = fast_pow(base, exp >> 1);
    return t * t % p;
}

ll comb(ll n, ll k){
    return f[n] * inv_f[k] % p * inv_f[n - k] % p;
}

ll solve(ll l, ll r){
    ll ans = 0;
    for(int i = 0; i <= l; ++i){
        ans += comb(l, i) * f[i + r - 1] % p;
    }
    ans %= p;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p;
    f[0] = 1;
    for(int i = 1; i <= n; ++i)
        f[i] = i * f[i - 1] % p;
    inv_f[n] = fast_pow(f[n], p - 2);
    for(int i = n - 1; i >= 0; --i)
        inv_f[i] = inv_f[i + 1] *(i + 1) % p;

    pwr2[0] = 1;
    for(int i = 1; i <= n; ++i)
        pwr2[i] = 2 * pwr2[i] % p;

    ll ans = 0;
    if(n % 2 == 0)
        ans = n * f[n - 2] % p;

    for(int i = 1; i * 2 < n; ++i){
        if(2 * i == n) continue;

        ll l = min((ll)i - 1, n - i - 1);
        ll r = n - 2 - l;

        ans += solve(l, r) * n % p * (i + (n % 2 == 0)) % p;

        ans %= p;
    }

    cout << ans << "\n";
}