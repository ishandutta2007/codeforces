#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (ll i=(a); i<=(signed ll)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed ll)(a); i++)
#define RFOR(i, a, b) for (ll i=(a); i >= b; i--)

#define MN 200005
ll fac[MN];
pll gcd(ll a, ll b){ //a*first+b*second=gcd
    if(a == 0){
        return mp(0, 1);
    }

    pll prev = gcd(b%a, a);

    return mp(prev.s-(b/a)*prev.f, prev.f);
} //using ll's just to be safe wrt overflow issues
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
    FOR(i, 1, MN-1){
        fac[i] = (fac[i-1]*i)%MOD;
    }
}
ll choose(ll a, ll b){
    ll c = a-b;
    if(c < 0){
        return 0;
        cout << "ur bad\n";
        exit(0);
    }

    ll num = fac[a];
    ll denom = (fac[b]*fac[c])%MOD;

    //cout << "num " << num << " denom " << denom << "\n";

    return modDiv(num, denom);
}
ll modExp(ll b, ll ex){
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

int n; ll mt;
ll t[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    getFacs();
    cin >> n >> mt;
    FOR(i, 1, n){
        cin >> t[i];
    }
    ll inv2 = modInv(2);

    ll ans = 0;
    ll cp2 = 1;
    ll tl = mt;
    ll cs = 1;
    ll ts = 0;
    FOR(i, 1, n){
        //cur += t[i];
        ll ntl = tl - t[i];
        cp2 = (cp2*inv2)%MOD;
        cs = (cs*2-ts+MOD)%MOD;
        if(ntl < 0){
            break;
        } else if(ntl >= i){
            tl = ntl;
            ans = (ans+1)%MOD;
            //cout << ans << "\n";
            ts = choose(i, tl);
            continue;
        }
        RFOR(j, min(i, tl), ntl+1){
            cs = (cs-choose(i, j)+MOD)%MOD;
        }
        ans = (ans+(cp2*cs)%MOD)%MOD;
        //cout << cs << " " << ans << "\n";
        tl = ntl;
        ts = choose(i, tl);
    }

    cout << ans << "\n";
    
    return 0;
}