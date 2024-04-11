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
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int m;
int sieve[MN];
bool par[MN];
bool isPow[MN];

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

void gs(){
    FOR(i, 2, MN-1){
        if(sieve[i] != 0) continue;
        for(int j=i; j<=MN-1; j+=i){
            sieve[j] = i;
            par[j] = !par[j];

            //cout << j << " " << i << " is fac\n";

            if((j/i) % i == 0){
                isPow[j] = true;
                //cout << j << " is true\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m;
    if(m == 1){
        cout << "1\n";
        return 0;
    }

    gs();

    ll sm = modDiv(1, m);
    //cout << "1 " << sm << "\n";
    ll nf = 0;

    FOR(i, 2, m){
        //if(sieve[i] != i) continue;

        nf++;
        /*ll n = m-m/i;
        ll prob = modDiv(m, n);
        cout << "prob at " << i << " " << prob << "\n";
        cout << i << " " << n << " " << m << "\n";
        sm = (sm+prob)%MOD;*/
        ll prob = modDiv(m/i, m);
        ll exv = modDiv((prob*(MOD+2-prob)%MOD), (MOD+1-prob)%MOD);
        //sm = (sm+exv)%MOD;
        if(sieve[i] == i || (!isPow[i] && par[i])){
            sm = (sm+exv)%MOD;
            //cout << i << "hi ";
        } else if(!isPow[i]){
            sm = (sm+MOD-exv)%MOD;
        }
        //cout << i << " " << exv << "\n";
    }

    cout << sm << "\n";
    
    return 0;
}