#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef long double ld;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
string s; int n;
int k;

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
    if(c < 0 || b < 0){
        return 0;
        //cout << "ur bad\n";
        //exit(0);
    }

    ll num = fac[a];
    ll denom = (fac[b]*fac[c])%MOD;

    //cout << "num " << num << " denom " << denom << "\n";
    //cout << a << " " << b << " " << modDiv(num, denom) << "\n";
    return modDiv(num, denom);
}

ll get(int x){
    //cout << "doing " << x << "\n";
    ll ans = 0;
    //cout << "doing " << x << " " << s << "\n";
    F0R(i, n){
        //cout << s[i] << " is s of " << i << "\n";
        if(s[i] == '1'){
            ans += choose(n-1-i, x);
            ans %= MOD;
            //cout << "adding, now " << ans << "\n";
            --x;
        }
    }
    if(x == 0) ans = (ans+1)%MOD;
    //cout << ans << "\n";
    return ans;
}
int calc(int x){
    int cnt = 0;
    while(x != 1){
        ++cnt;
        x = __builtin_popcount(x);
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    getFacs();
    cin >> s >> k;
    if(k == 0){
        cout << "1\n";
        return 0;
    } else if(k == 1){
        cout << s.length()-1 << "\n";
        return 0;
    }
    n = s.length();
    ll ans = 0;
    FOR(i, 1, 1000){
        if(calc(i) == k-1){
            ans += get(i);
            ans %= MOD;
        }
    }
    cout << ans << "\n";

    return 0;
}