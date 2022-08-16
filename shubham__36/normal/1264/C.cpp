#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<ll> v32;
typedef vector<vector<ll> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e9
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll mpow(ll a, ll b){
    if(b >= (MOD-1)) b %= (MOD-1);
    if(b==0) return 1;
    ll t1 = mpow(a,b/2);
    t1 *= t1;
    t1 %= MOD;
    if(b%2) t1 *= a;
    t1 %= MOD;
    // cout << a << " " << b << " " << t1 << ln;
    return t1;
}

ll mpow(ll a, ll b, ll p){
    if(b==0) return 1;
    ll t1 = mpow(a,b/2,p);
    t1 *= t1;
    t1 %= p;
    if(b%2) t1 *= a;
    t1 %= p;
    return t1;
}
 
ll modinverse(ll a, ll m){
    ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) return 0; 
    while (a > 1){
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    }
    if (x < 0) x += m0; 
    return x; 
}
 
ll range(ll l, ll r){
    return l + rand()%(r-l+1);
}

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

v64 ppd,ps,pas;

ll f(ll u, ll v){
    // cout << ppd[v-1] << " " << ppd[u-1] << ln;
    ll num1 = ((v-u)*((ppd[v-1]*mpow(((u>0) ? ppd[u-1] : 1),MOD-2))%MOD))%MOD;
    ll agp = pas[v-1]-((u>0) ? pas[u-1] : 0);
    ll diff = ps[v-1]-((u>0) ? ps[u-1] : 0);
    // cout << diff << ln;
    agp -= (u*diff)%MOD;
    agp *= mpow(((u>0) ? ppd[u-1] : 1),MOD-2);
    agp %= MOD;
    if(agp < 0) agp += MOD;
    diff *= mpow(((u>0) ? ppd[u-1] : 1),MOD-2);
    diff %= MOD;
    ll den = (1-diff)%MOD;
    if(den < 0) den += MOD;
    // cout << num1 << " " << agp << " " << den << ln;
    ll ans = (num1+agp)*mpow(den,MOD-2);
    ans %= MOD;
    if(ans < 0) ans += MOD;
    return ans;
}
 
void solve(){  
    ll n,q;
    cin >> n >> q;
    ll p[n];
    ll inv100 = mpow(100,MOD-2);
    // cout << inv100 << ln;
    // return;
    forn(i,n) {
        cin >> p[i];
        // cout << p[i] << " ";
        p[i] = (p[i]*inv100)%MOD;
        // cout << p[i] << ln;
    }
    ppd.resize(n);
    ps.resize(n);
    pas.resize(n);
    ppd[0]=p[0];
    ps[0]=(1-p[0]+MOD)%MOD;
    pas[0]=ps[0];
    forsn(i,1,n){
        ppd[i] = (ppd[i-1]*p[i])%MOD;
        ll term = (ppd[i-1]*(1-p[i]))%MOD;
        if(term < 0) term+=MOD;
        ps[i] = (ps[i-1]+term)%MOD;
        pas[i] = (pas[i-1]+(i+1)*term)%MOD;
    }
    ordered_set os;
    os.insert(0);
    os.insert(n);
    ll ans[n];
    ll s[n];
    forn(i,n){
        ans[i]=0;
        s[i]=0;
    }
    s[0]=1;
    ll num = (n*ppd[n-1]+pas[n-1])%MOD;
    ll den = (1-ps[n-1])%MOD;
    if(den < 0) den += MOD;
    // ans[0] = f(0,n);
    // cout << (n*ppd[n-1])%MOD << " " << pas[n-1] << " "<< den << ln;
    // ans[0] = (num*mpow(den,MOD-2))%MOD;
    ll cans = ans[0];
    // cout << cans << ln;
    // cout << f(1,2) << ln;
    // return;
    forn(i,q){
        ll u;
        cin >> u;
        u--;
        // cout << u << " " << s[u] << ln;
        if(s[u]) os.erase(u);
        ll in = os.order_of_key(u);
        ll l = *(os.find_by_order(in-1));
        ll r = *(os.find_by_order(in));
        // cout << l << " "<< r << ln;
        if(s[u]) {
            cans -= (ans[l]+ans[u]);
            // cout << "a" << ln;
            // cout << ans[l] << " " << ans[u] << ln;
            ans[l] = f(l,r);
            // cout << "b" << ln;
            // cout << ans[l] << ln;
            cans += ans[l];
            s[u]=0;
        }
        else {
            cans -= ans[l];
            // cout << "c" << ln;
            // cout << ans[l] << ln;
            ans[l] = f(l,u);
            ans[u] = f(u,r);
            // cout << "d" << ln;
            // cout << ans[l] << " " << ans[u] << ln;
            cans += (ans[l]+ans[u]);
            s[u]=1;
            os.insert(u);
        }
        cans %= MOD;
        if(cans < 0) cans += MOD;
        cout << cans << ln;
    }
}
 
int main()
{
    fast_cin();
    ll t=1;
    // ll a = 100;
    // ll b = 268435456;
    // cout << b << " " << b*b << ln; 
    // cout << b*b << " " << (b*b)%MOD << ln; 
    // cout << (a*((b*b)%MOD))%MOD << " " << MOD << ln;
    // cin>>t;
    forn(i,t) {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}