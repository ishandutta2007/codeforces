#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 2005
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
ll c2(ll x){
    return x*(x-1)/2;
}

int n;
ll p;
ll dp[MN]; //exp val
ll p1[MN][MN]; //prob that j people win vs other i ppl
ll p2[MN]; //prob that i people form SCC

ll calcP1(int x, int y){
    if(p1[x][y] != -1) return p1[x][y];

    if(y == 0)
        return p1[x][y] = 1;
    if(x < y)
        return p1[x][y] = 0;

    ll pt1 = (calcP1(x-1, y)*modExp(p, y))%MOD;
    ll pt2 = (calcP1(x-1, y-1)*modExp(1+MOD-p, x-y));
    return p1[x][y] = (pt1+pt2)%MOD;
}
ll calcP2(int x){
    if(p2[x] != -1) return p2[x];

    if(x == 1)
        return p2[x] = 1;

    ll bad = 0;
    FOR(i, 1, x-1){
        bad = (bad+calcP1(x, i)*calcP2(i))%MOD;
    }
    return p2[x]=1+MOD-bad;
}
ll calcDP(int x){
    if(dp[x] != -1) return dp[x];

    if(x <= 1)
        return dp[x] = 0;
    
    ll tot = 0;
    FOR(i, 1, x-1){
        ll pb = (calcP1(x, i)*calcP2(i))%MOD;
        ll amt = (c2(i)+i*(x-i)+calcDP(i)+calcDP(x-i))%MOD;
        tot = (tot+pb*amt)%MOD;
    }

    ll ree = (calcP1(x, x)*calcP2(x))%MOD;
    ll reee = (c2(x)+calcDP(0))%MOD;
    ll reeee = (tot+(ree*reee))%MOD;
    ll reeeee = modDiv(reeee, 1+MOD-ree);
    return dp[x]=reeeee;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int a, b;
    cin >> a >> b;
    p = modDiv(a, b);

    memset(dp, -1, sizeof dp);
    memset(p1, -1, sizeof p1);
    memset(p2, -1, sizeof p2);

    cout << calcDP(n) << "\n";
    
    return 0;
}