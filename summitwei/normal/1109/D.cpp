#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (ll i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
ll n, m, a, b;

ll fac[MN];
ll ifac[MN];

pll gcd(ll a, ll b){ //a*first+b*second=gcd
    if(a == 0){
        return mp(0, 1);
    }

    pll prev = gcd(b%a, a);

    return mp(prev.s-(b/a)*prev.f, prev.f);
}
ll modInv(ll x){ //return x^-1 % MOD
    pll res = gcd(x, MOD);

    res.f = (res.f+MOD)%MOD;

    //cout << "modinv of " << x << " is " << res.f << "\n";

    return res.f;
}
ll modDiv(ll x, ll y){
    return (x*modInv(y))%MOD;
}
ll getFacs(){
    fac[0] = 1;
    ifac[0] = 1;
    FOR(i, 1, MN-1){
        fac[i] = (fac[i-1]*i)%MOD;
        ifac[i] = modInv(fac[i]);
    }
}
ll choose(ll a, ll b){
    ll c = a-b;
    if(c < 0){
        cout << "ur bad\n";
        exit(0);
    }

    ll num = fac[a];
    ll denom = (ifac[b]*ifac[c])%MOD;

    //cout << "num " << num << " denom " << denom << "\n";

    //return modDiv(num, denom);
    return (num*denom)%MOD;
}
ll modExp(ll b, ll ex){
    if(ex < 0){
        return modInv(modExp(b, -ex));
    }
    ll prod = 1;
    while(ex > 0){
        if(ex % 2 == 0){
            b = (b * b) % MOD;
            ex /= 2;
        } else{
            prod = (prod*b) % MOD;
            ex--;
        }
    }
    
    return prod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> a >> b;

    getFacs();

    ll ans = 0;
    FOR(k, 2, min(n, m+1)){
        //cout << "doing " << k << "\n";
        ll perm = (fac[n-2]*ifac[n-k])%MOD;
        ll comb = choose(m-1, k-2);
        ll cay = (k*(modExp(n, n-k-1)))%MOD;
        ll oth = modExp(m, n-k);

        //cout << k << " " << perm << " " << comb << " " << cay << " " << oth << "\n";

        ll fin = (((perm*comb)%MOD)*((cay*oth)%MOD))%MOD;
        ans = (ans+fin)%MOD;
    }

    cout << ans << "\n";
    
    return 0;
}