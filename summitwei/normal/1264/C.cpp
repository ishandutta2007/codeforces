#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<pll> vpll;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
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

int n, q;
ll p[MN];
ll ps[MN];
ll pp[MN];
set<int> in;

ll calc(int l, int r){
    ll dif = ps[r]-ps[l-1];
    dif = (dif+MOD)%MOD;
    return modDiv(dif, pp[r]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pp[0] = 1;

    cin >> n >> q;
    FOR(i, 1, n){
        ll x;
        cin >> x;
        p[i] = modDiv(x, 100);
        pp[i] = (pp[i-1]*p[i])%MOD;
        ps[i] = ps[i-1]+pp[i-1];
    }
    ll cur = calc(1, n);
    in.insert(1);
    in.insert(n+1);
    F0R(_, q){
        int x;
        cin >> x;
        if(in.count(x)){
            set<int>::iterator it = in.find(x), it2 = in.find(x);
            --it;
            cur -= calc(*it, x-1);
            cur = (cur+MOD)%MOD;
            ++it2;
            cur -= calc(x, *it2-1);
            cur = (cur+MOD)%MOD;
            cur += calc(*it, *it2-1);
            cur %= MOD;
            in.erase(x);
        } else{
            in.insert(x);
            set<int>::iterator it = in.find(x), it2 = in.find(x);
            --it;
            cur += calc(*it, x-1);
            cur %= MOD;
            ++it2;
            cur += calc(x, *it2-1);
            cur %= MOD;
            cur -= calc(*it, *it2-1);
            cur = (cur+MOD)%MOD;
        }
        cout << cur << "\n";
    }

    return 0;
}