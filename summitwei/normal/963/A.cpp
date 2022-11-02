#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000009LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
ll n, a, b;
int k; string s;

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b >> k;
    cin >> s;

    ll res = modDiv(b, a);
    ll st = modExp(a, n);
    ll sm = 0;
    ll cur = st;
    F0R(i, k){
        if(s[i] == '+') sm += cur;
        else sm -= cur;
        sm = (sm+MOD)%MOD;
        cur = (cur*res)%MOD;
    }
    //cout << sm << "\n";
    ll nt = (n+1)/k;
    ll pro = modExp(res, k);
    ll num = (modExp(pro, nt)+MOD-1)%MOD;
    ll den = (pro+MOD-1)%MOD;
    if(pro == 1){num = nt; den = 1;}
    ll fin = modDiv((sm*num)%MOD, den);
    //cout << nt << " " << pro << " " << num << " " << den << "\n";
    cout << fin << "\n";

    return 0;
}