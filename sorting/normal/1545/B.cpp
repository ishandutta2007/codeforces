#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

const int MOD = 998244353;
const int N = 1e5 + 3;

ll fast_pow(ll base, ll exp){
    if(!exp) return 1ll;
    if(exp & 1){
        return base * fast_pow(base, exp - 1) % MOD;
    }

    ll t = fast_pow(base, exp >> 1);
    return t * t % MOD;
}

ll f[N], inv_f[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    f[0] = 1;
    for(int i = 1; i < N; ++i)
        f[i] = f[i - 1] * i % MOD;

    inv_f[N - 1] = fast_pow(f[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; --i)
        inv_f[i] = inv_f[i + 1] * (i + 1) % MOD;

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i){
        int n;
        string s;
        cin >> n >> s;

        int cnt_odd = 0, cnt[2]{0, 0};
        int curr = 0;
        for(int i = 0; i < n; ++i){
            cnt[s[i] - '0']++;
            if(s[i] == '0'){
                if(curr & 1) ++cnt_odd;
                curr = 0;
            }
            else ++curr;
        }
        if(curr & 1) ++cnt_odd;

        int c_10, c_0, c_11;
        c_10 = cnt_odd;
        c_0 = cnt[0] + 1 - cnt_odd;
        c_11 = (n + 1 - c_0 - c_10 * 2) / 2;
        //cout << c_10 << " " << c_0 << " " << c_11 << endl;

        ll ans = f[c_10 + c_0 + c_11] * inv_f[c_10] % MOD * inv_f[c_0] % MOD * inv_f[c_11] % MOD;
        //cout << ans << " before\n"; 
        if(c_11){
            ans -= f[c_10 + c_0 + c_11 - 1] * inv_f[c_10] % MOD * inv_f[c_0] % MOD * inv_f[c_11 - 1] % MOD;
            ans += MOD;
            ans %= MOD;
        }
        ans = ans * fast_pow(f[c_10 + c_0] * inv_f[c_10] % MOD * inv_f[c_0] % MOD, MOD - 2) % MOD;
        cout << ans << "\n";
        //cout << endl;
    }   
}