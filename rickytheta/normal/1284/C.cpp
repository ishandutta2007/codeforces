#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;

using _loop_int = int;
#define REP(i,n) for(_loop_int i=0; i<(_loop_int)(n); i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a); i<(_loop_int)(b); i++)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1; i>=(_loop_int)(a); i--)

#define CHMIN(a,b) (a)=min((a),(b))
#define CHMAX(a,b) (a)=max((a),(b))
#define ALL(v) (v).begin(),(v).end()

#define DEBUG(x) cerr<<#x<<": "<<(x)<<endl
#define DEBUG_VEC(v) cerr<<#v<<": ";REP(__i,(v).size())cerr<<((v)[__i])<<", ";cerr<<endl

ll MOD;

ll modpow(ll a, ll b){
    ll r = 1;
    while(b){
        if(b&1)r=r*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return r;
}
ll modinv(ll a){
    return modpow(a,MOD-2);
}

ll fact[252521];
ll ifact[252521];

int main(){
    int n;
    cin >> n >> MOD;

    fact[0] = 1;
    FOR(i,1,252521)fact[i] = fact[i-1] * i % MOD;
    ifact[252521-1] = modinv(fact[252521-1]);
    FORR(i,1,252521)ifact[i-1] = ifact[i] * i % MOD;

    ll ans = 0;
    FOR(len, 1, n+1){
        ll beginValPat = n-len+1;
        ll beginPosPat = n-len+1;
        ll multipliedFactor = fact[n-len] * fact[len] % MOD;
        ans += beginValPat * beginPosPat % MOD * multipliedFactor % MOD;
        ans %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}