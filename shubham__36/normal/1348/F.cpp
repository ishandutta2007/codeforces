#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
ll MOD = 163577857;
double eps = 1e-12;
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
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
ll mpow(ll a, ll b){
	if(a==0) return 0;
	if(b >= (MOD-1)) b %= (MOD-1);
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}
 
ll mpow(ll a, ll b, ll p){
	if(a==0) return 0;
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
 
ll rev(ll v){
	return mpow(v,MOD-2);
}

void solve(){
	ll n;
	cin >> n;
	pair<p64,ll> a1[n];
	pair<p64,ll> a[n];
	forn(i,n){
		cin >> a[i].fi.fi >> a[i].fi.se;
		a[i].se=i;
		a1[i]=a[i];
	}
	sort(a,a+n);
	set<p64> s;
	ll in = 0;
	ll ans[n];
	ll p[n];
	vp64 vec;
	forsn(i,1,n+1){
		while(in<n && a[in].fi.fi==i) {
			s.insert(mp(a[in].fi.se,a[in].se));
			in++;
		}
		p64 cur = *(s.begin());
		ans[cur.se]=i;
		p[i-1]=a1[cur.se].fi.se;
		vec.pb(mp(a1[cur.se].fi.fi,i));
		s.erase(s.begin());
	}
	sort(all(vec));
	// for(auto it : vec) cout << it.fi << " " << it.se << ln;
	set<ll> s1;
	in=0;
	bool yes = 1;
	ll a11,a2;
	forsn(i,1,n+1){
		while(in<n && vec[in].fi == i){
			s1.insert(vec[in].se);
			in++;
		}
		while(sz(s1) && (*s1.begin())==i) s1.erase(s1.begin());
		if(sz(s1) && (*s1.begin())<=p[i-1]){
			yes=0;
			a11=i,a2=(*s1.begin());
			break;
		}
	}
	// cout << a11 << " " << a2 << ln;
	cout << (yes ? "YES" : "NO") << ln;
	forn(i,n) cout << ans[i] << " ";
	cout << ln;
	if(!yes){
		forn(i,n) {
			cout << ((ans[i]==a11 || ans[i]==a2) ? a11+a2-ans[i] : ans[i]) << " ";
		}
		cout << ln;
	}
}
 
int main()
{
	fast_cin();
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}