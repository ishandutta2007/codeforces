#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 3;
const ll MOD = 1e9 + 7;

ll fact[N], inv_fact[N];
ll k;
int n, m;

ll fast_pow(ll base, ll exp){
    if(!exp) return 1ll;
    if(exp & 1) return base * fast_pow(base, exp - 1) % MOD;
    ll t = fast_pow(base, exp >> 1);
    return t * t % MOD;
}

ll comb(ll n, ll k){
    if(n < k) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

void solve(){
    cin >> n >> m >> k;

    if(m == 0){
        cout << "0\n";
        return;
    }

    ll ans = 0;
    for(int i = 1; i <= m; ++i){
        ans += comb(n, m - i) * i % MOD;
        if(ans >= MOD) ans -= MOD;
    }

    //cout << ans << " before" << endl;

    ans = ans * k % MOD * fast_pow(fast_pow(2, n - 1), MOD - 2) % MOD;
    cout << ans << "\n"; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    fact[0] = 1;
    for(int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[N - 1] = fast_pow(fact[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;

    while(t--)
        solve();
}