#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<long long> > vvll;
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
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005

ll fac[MN];

pll egcd(ll a, ll b){ //a*first+b*second=gcd
    if(a == 0){
        return mp(0, 1);
    }

    pll prev = egcd(b%a, a);

    return mp(prev.s-(b/a)*prev.f, prev.f);
} //using ll's just to be safe wrt overflow issues

ll modInv(ll x){ //return x^-1 % MOD
    pll res = egcd(x, MOD);

    res.f = (res.f+MOD)%MOD;

    //cout << "modinv of " << x << " is " << res.f << "\n";

    return res.f;
}

ll modDiv(ll x, ll y){
    return (x*modInv(y))%MOD;
}

void getFacs(){
    fac[0] = 1;
    FOR(i, 1, MN-1){
        fac[i] = (fac[i-1]*i)%MOD;
    }
}

ll choose(ll a, ll b){
    ll c = a-b;
    if(c < 0){
        cout << "ur bad\n";
        exit(0);
    }

    ll num = fac[a];
    ll denom = (fac[b]*fac[c])%MOD;

    //cout << "num " << num << " denom " << denom << "\n";

    return modDiv(num, denom);
}


ll n;
ll a[MN];
ll cpy[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    getFacs();

    cin >> n;
    F0R(i, n){
        cin >> a[i];
    }
    if(n == 1){
        cout << a[0] << "\n";
        return 0;
    }
    if(n % 2 == 1){
        F0R(i, n-1){
            if(i%2==0){
                cpy[i] = a[i]+a[i+1];
                cpy[i] %= MOD;
            } else{
                cpy[i] = a[i]-a[i+1];
                cpy[i] = (cpy[i]+MOD)%MOD;
            }
        }
        memcpy(a, cpy, sizeof a);
        n--;
    }
    
    ll x1 = 0;
    ll x2 = 0;
    F0R(i, n/2){
        ll val = choose(n/2-1, i);
        x1 += ((val*a[i*2])%MOD);
        x1%=MOD;
        x2 += ((val*a[i*2+1])%MOD);
        x2%=MOD;
    }
    
    //cout << x1 << " " << x2 << "\n";
    
    ll res;
    if(n % 4 == 0){
        res = (x1-x2+MOD)%MOD;
    } else{
        res = (x1+x2)%MOD;
    }
    
    cout << res << "\n";
    return 0;
}