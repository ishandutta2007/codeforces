#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000000000005LL
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n, l, r; ll p;
ll mod, bs, expo;

pll gcd(ll a, ll b){ //a*first+b*second=gcd
    if(a == 0){
        return mp(0, 1);
    }

    pll prev = gcd(b%a, a);

    return mp(prev.s-(b/a)*prev.f, prev.f);
} //using ll's just to be safe wrt overflow issues
ll modInv(ll x){ //return x^-1 % MOD
    pll res = gcd(x, mod);

    res.f = (res.f+mod)%mod;

    //cout << "modinv of " << x << " is " << res.f << "\n";

    return res.f;
}
ll modDiv(ll x, ll y){
    return (x*modInv(y))%mod;
}

pll fac[MN]; //res, #ofmodbase
void getFacs(){
    fac[0] = {1, 0};
    FOR(i, 1, MN-1){
        fac[i] = fac[i-1];
        int tmp = i;

        while(tmp % bs == 0){
            fac[i].s++;
            tmp /= bs;
        }
        fac[i].f = (fac[i].f*tmp)%mod;
        //if(i <= 10) cout << fac[i].f << " " << fac[i].s << "\n";
    }
}
ll modExp(ll b, ll ex){
    ll prod = 1;
    while(ex > 0){
        if(ex % 2 == 0){
            b = (b * b) % mod;
            ex /= 2;
        } else{
            prod = (prod*b) % mod;
            ex--;
        }
    }
    
    return prod;
}
ll choose(int a, int b){
    int c = a-b;
    if(c < 0){
        cout << "ur bad\n";
        exit(0);
    }

    ll bsp = fac[a].s-fac[b].s-fac[c].s;
    ll res = modDiv(fac[a].f, (fac[b].f*fac[c].f)%mod);

    if(bsp >= expo) return 0;
    F0R(_, bsp) res = (res*bs)%mod;
    //cout << a << " choose " << b << " " << c << " is " << res << "\n";
    return res;
}

ll calc(int n, int l, int r){ //assume no nv
    //cout << "calc " << n << " " << l << " " << r << " " << mod << "\n";
    if(r > n) r = n;
    if(l > n) return 0;
    if((n-r)%2) --r;
    if((n-l)%2) ++l;
    ll ret = choose(n, (n-l)/2)-(n==r?0:choose(n, (n-r)/2-1));
    //cout << "got " << ret << "\n";
    return ret<0?ret+mod:ret;
}
map<ll, ll> res; //mod bases and answers

ll calc2(){
    //cout << "doing " << mod << " " << bs << " " << expo << "\n";
    getFacs();
    ll sm = 0;
    FOR(i, 0, n){
        ll p1 = calc(n-i, l, r);
        ll p2 = choose(n, i);
        sm = (sm+p1*p2)%mod;
        //cout << "did " << i << " " << p1 << " " << p2 << "\n";
    }
    return sm;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n >> p >> l >> r;
    ll op = p;

    for(int i=2; 1LL*i*i<=p; ++i){
        if(p % i != 0) continue;
        int cnt = 0;
        ll ree = 1;
        while(p % i == 0){
            ++cnt; p /= i; ree *= i;
        }
        mod = ree; bs = i; expo = cnt;
        ll ans = calc2();
        res[mod] = ans;
    }
    if(p != 1){
        mod = p; bs = p; expo = 1;
        ll ans = calc2();
        res[mod] = ans;
    }

    //combine somehow
    ll fin = 0;
    for(auto u : res){
        //cout << u.f << " " << u.s << "\n";
        pll hmm = gcd(u.f, op/u.f);
        ll got = ((u.s*hmm.s)%op*(op/u.f))%op;
        fin = (fin+got)%op;
    }

    cout << (fin+op)%op << "\n";
    
    return 0;
}