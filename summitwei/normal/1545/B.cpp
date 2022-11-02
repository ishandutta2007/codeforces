#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef unsigned long long ull;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPS 0.000000000001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
string s;

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    getFacs();

    int t;
    cin >> t;
    F0R(_, t){
        cin >> n;
        cin >> s;
        int cnt = 0;
        bool potato = true;
        int cnt2 = 0;
        F0R(i, n-1){
            if(s[i] == '1') ++cnt2;
            if(s[i] == '1' && s[i+1] == '1' && potato){
                potato = false;
                ++cnt;
            } else{
                potato = true;
            }
        }
        if(s[n-1] == '1') ++cnt2;
        cnt2 -= cnt*2;
        //cout << cnt << " " << n << " " << cnt2 << "\n";
        cout << choose(n-cnt-cnt2, cnt) << "\n";
    }

    return 0;
}