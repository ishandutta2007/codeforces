#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
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
#define INF LLONG_MAX
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
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

vv64 m;
// map <p64,ll> m;
v64 a;

ll f(ll sin, ll ein){
	if(sin==ein) return 1;
	else if(sin>ein) return 0;
	ll len = ein-sin;
	if(m[sin][len]==-1){
		ll mm = INF;
		ll mi = 0;
		forsn(i,sin,ein){
			if(a[i]<mm){
				mm = a[i];
				mi = i;
			}
		}
		ll ans1 = 0;
		ll ans2 = 0;
		forsn(i,sin,mi+1){
			ans1 += f(sin,i)*f(i,mi);
			ans1 %= MOD;
		}
		forsn(i,mi+1,ein+1){
			ans2 += f(mi+1,i)*f(i,ein);
			ans2 %= MOD;
		}
		m[sin][len] = (ans1*ans2)%MOD;
	}
	// cout << sin << " " << ein << " " << m[mp(sin,ein)] << ln;
	return m[sin][len];
}

void solve(){
	ll n,m1;
	cin >> n >> m1;
	a.resize(n+5);
	m.resize(n+5,v64(n+5,-1));
	forn(i,n) cin >> a[i];
	cout << f(0,n) << ln;
}

int main()
{
	fast_cin();
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}