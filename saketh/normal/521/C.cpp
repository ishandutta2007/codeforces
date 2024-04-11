#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 100005;
const ll MOD = 1000000007;

int N, K;
string s; 

ll fact[MAXN];

ll pow(ll base, ll exp){
    if(exp == 0) return 1;
    ll hf = pow(base, exp/2);
    hf = (hf * hf) % MOD;
    if(exp % 2) hf = (hf * base) % MOD;
    return hf;
}

ll inv(ll val){
    return pow(val, MOD-2);
}

ll ncr(ll n, ll r){
    if(n<0) return 0;
    if(n==0) return r==0;
    if(r<0 || r>n) return 0;
    ll num = fact[n];
    ll den = (fact[r] * fact[n-r]) % MOD;
    return (num * inv(den)) % MOD;
}

int main(){
    fact[0] = 1;
    for(int i=1; i<MAXN; i++)
        fact[i] = (fact[i-1] * i) % MOD;

    cin >> N >> K >> s;

    ll ans = 0;
    ll tmp = 0;

    for(int i=N-1; i>=0; i--){
        ll dig = s[i] - '0';
        
        ll coeff = pow(10, N-1-i);
        ll ways = ncr(i, K);

        ll contr = dig * (coeff * ways % MOD) % MOD;
        ans = (ans + contr) % MOD;

        if(i<N-1){
            ll ocoff = pow(10, N-2-i);
            ll oways = ncr(i, K-1);

            tmp = (tmp + (ocoff * oways % MOD)) % MOD;
            ans = (ans + (tmp * dig % MOD)) % MOD;
        }
    }

    cout << ans << endl;
}