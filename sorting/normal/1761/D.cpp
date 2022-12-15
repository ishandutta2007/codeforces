#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll N = 1e6 + 13;

ll n, k, pwr3[N], f[N], inv_f[N];
const ll MOD = 1e9 + 7;

ll fast_pow(ll base, ll exp){
    if(!exp) return 1ll;
    if(exp & 1) return base * fast_pow(base, exp - 1) % MOD;
    ll t = fast_pow(base, exp >> 1);
    return t * t % MOD;
}

ll comb(ll n, ll k){
    if(n < k) return 0ll;
    if(k < 0 || n < 0) return 0ll;
    return f[n] * inv_f[k] % MOD * inv_f[n - k] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    pwr3[0] = 1;
    for(int i = 1; i < N; ++i)
        pwr3[i] = pwr3[i - 1] * 3 % MOD;

    f[0] = 1;
    for(int i = 1; i < N; ++i)
        f[i] = f[i - 1] * i % MOD;

    inv_f[N - 1] = fast_pow(f[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; --i)
        inv_f[i] = inv_f[i + 1] * (i + 1) % MOD;

    if(k == 0){
        cout << pwr3[n] << "\n";
        return 0;
    }

    int t1 = 1, t0 = 1;
    ll ans = 0;
    while(t1 <= k && n - k >= t0 - 1 && t0 + t1 <= n + 1){
        ans += comb(k - 1, t1 - 1) * comb(n - k, t0 - 1) % MOD * pwr3[n - (t1 + t0 - 1)] % MOD;
        ans %= MOD;
        if(t1 == t0)
            ++t0;
        else
            ++t1;
    }

    cout << ans << "\n";
}