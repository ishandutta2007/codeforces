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
ll MOD = 1e9+7;
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

ll mpow(ll a, ll b, ll p){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
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

void solve(){
	ll n;
	cin >> n;
	p64 a[n];
	forn(i,n){
		cin >> a[i].se >> a[i].fi; 
	} 
	sort(a,a+n);
	ll mmin = 0;
	ll val = 1;
	multiset<pair<p64,p64> > s;
	forn(i,n){
		// cout << i << ln;
		while(sz(s) && (*(s.begin())).fi.fi <= a[i].fi){
			if((*(s.begin())).fi.se < mmin){
				mmin = (*(s.begin())).fi.se;
				val = (*(s.begin())).se.fi;
			}
			else if((*(s.begin())).fi.se == mmin){
				val += (*(s.begin())).se.fi;
				val %= MOD;
			}
			s.erase(s.begin());
		}
		s.insert(mp(mp(a[i].se,mmin+a[i].fi-a[i].se),mp(val,mmin+a[i].fi)));
	}
	ll ans = 0;
	mmin = INF;
	for(auto it : s){
		ll v = it.se.se;
		// cout << it.fi.fi << " " << it.fi.se << " " << it.se.fi << " " << it.se.se << ln;
		if(v==mmin){
			ans += it.se.fi;
			ans %= MOD;
		}
		else if(v<mmin){
			mmin = v;
			ans = it.se.fi;
		}
		
	}
	cout << ans << ln;
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