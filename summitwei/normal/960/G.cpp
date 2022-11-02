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
#define MOD 998244353LL //119*2^23+1
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

typedef complex<double> cd;
const double PI = acos(-1);

#define MN 100005
#define PR 3
int n, a, b;

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

void fft(vector<ll> & a, bool invert, int sz){
    int n = a.size();

    /*cout << "doing " << sz << "\n";
    for(auto u : a) cout << u << " ";
    cout << "\n";*/

    ll root = modExp(PR, 119LL<<(23-sz));
    ll root_1 = modInv(root);
    ll root_pw = 1<<sz;
 
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % MOD);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % MOD);
                a[i+j] = u + v < MOD ? u + v : u + v - MOD;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + MOD;
                w = (int)(1LL * w * wlen % MOD);
            }
        }
    }

    if (invert) {
        ll n_1 = modInv(n);
        for (ll & x : a)
            x = (x * n_1) % MOD;
    }
}
vll mult(vll const& a, vll const& b){
    vll fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1, bruh=0;
    while(n < a.size() + b.size()){ n <<= 1; ++bruh;}
    fa.resize(n);
    fb.resize(n);

    /*cout << "mult\n";
    for(auto u : a) cout << u << " ";
    cout << "\n";
    for(auto u : b) cout << u << " ";
    cout << "\n";*/
 
    fft(fa, false, bruh);
    fft(fb, false, bruh);
    F0R(i, n){
        fa[i] *= fb[i];
        fa[i] %= MOD;
    }
    fft(fa, true, bruh);
    vll res(n);
    F0R(i, n){
        res[i] = (fa[i])%MOD;
    }

    /*cout << "got\n";
    for(auto u : res){
        cout << u << " ";
    }
    cout << "\n";*/
    
    int lst = n;
    while(lst != 0 && res[lst-1] == 0) --lst;
    res.resize(lst);
 
    return res;
}

vll calc(int l, int r){
    if(l == r){
        vll res;
        res.pb(l); res.pb(1);
        return res;
    }
    int mid = (l+r)/2;
    vll q1 = calc(l, mid);
    vll q2 = calc(mid+1, r);
    vll res = mult(q1, q2);
    /*cout << l << " " << r << "\n";
    for(auto u : res){
        cout << u << " ";
    }
    cout << "\n";*/
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /*memset(dp, -1, sizeof dp);

    dp[1][1][1] = 1;
    
    cin >> n >> a >> b;
    cout << calc(n, a, b) << "\n";*/
    cin >> n >> a >> b;
    if(a == 0 || b == 0 || a+b > n+1){
        cout << "0\n";
        return 0;
    }
    if(n == 1){
        cout << "1\n";
        return 0;
    }
    --n; --a; --b;
    ll num = 1;
    FOR(i, 1, a+b) num = (num*i)%MOD;
    ll den = 1;
    FOR(i, 1, a) den = (den*i)%MOD;
    FOR(i, 1, b) den = (den*i)%MOD;

    ll p1 = modDiv(num, den);

    vll aah = calc(0, n-1);
    /*for(auto u : aah) cout << u << " ";
    cout << "\n";*/
    ll p2 = aah[a+b];
    //cout << p1 << " " << p2 << "\n";
    cout << (p1*p2)%MOD << "\n";

    return 0;
}