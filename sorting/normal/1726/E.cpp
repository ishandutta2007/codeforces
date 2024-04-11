#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

    const ll N = 3e5 + 3;
    const ll MOD = 998244353;

ll fast_pow(ll base, ll exp){
    if(!exp) return 1;
    if(exp & 1) return base * fast_pow(base, exp - 1) % MOD;
    ll t = fast_pow(base, exp >> 1);
    return t * t % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;


    static ll f[N], inv_f[N];
    f[0] = 1;
    for(int i = 1; i < N; ++i)
        f[i] = f[i - 1] * i % MOD;

    inv_f[N - 1] = fast_pow(f[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; --i)
        inv_f[i] = inv_f[i + 1] * (i + 1) % MOD;

    while(t--){
        ll n;
        cin >> n;

        static ll dp[N];
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
            dp[i] %= MOD;
        }

        ll ans = 0, pow = 1;
        for(int i = 0; 4 * i <= n; ++i, pow = 2 * pow % MOD){
            ans += f[n - 2 * i] * inv_f[2 * i] % MOD * inv_f[n - 4 * i] % MOD * dp[n - 4 * i] % MOD * f[2 * i] % MOD * inv_f[i] % MOD;
            ans %= MOD;
            // cout << ans << endl;
        }
        cout << ans << "\n";
    }
}