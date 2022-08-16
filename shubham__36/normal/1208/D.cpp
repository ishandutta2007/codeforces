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
ll MOD = 998244853;
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
#define INF 1e18
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

class LazySegmentTree {
	ll n;
	vp64 t;
	ll h;
	v64 d;

	public:

	LazySegmentTree(const v64 &a){
		n = (ll)a.size();
		h = sizeof(ll) * 8 - __builtin_clz(n);
		t.assign(2*n,mp(0,0));
		d.assign(n,0);
		forn(i,n) t[n+i]=mp(a[i],-i);
		build();
	}

	void build() {  // build the tree
	  rforn(i,n-1) t[i] = min(t[i<<1],t[i<<1|1]);
	}

	void apply(ll p, ll value) {
	  t[p].fi += value;
	  if (p < n) d[p] += value;
	}

	void build(ll p) {
	  while (p > 1) {p >>= 1, t[p] = min(t[p<<1], t[p<<1|1]); t[p].fi += d[p];}
	}

	void push(ll p) {
	  for (ll s = h; s > 0; --s) {
	    ll i = p >> s;
	    if (d[i] != 0) {
	      apply(i<<1, d[i]);
	      apply(i<<1|1, d[i]);
	      d[i] = 0;
	    }
	  }
	}

	void inc(ll l, ll r, ll value) {
	  l += n, r += n;
	  ll l0 = l, r0 = r;
	  for (; l < r; l >>= 1, r >>= 1) {
	    if (l&1) apply(l++, value);
	    if (r&1) apply(--r, value);
	  }
	  build(l0);
	  build(r0 - 1);
	}

	ll query(ll l, ll r) {
	  l += n, r += n;
	  push(l);
	  push(r - 1);
	  p64 res = mp(1,0); 
	  for (; l < r; l >>= 1, r >>= 1) {
	    if (l&1) res = min(res, t[l++]);
	    if (r&1) res = min(t[--r], res);
	  }
	  return -res.se;
	}
};

void solve(){
	ll n;
	cin >> n;
	v64 a(n);
	forn(i,n) cin >> a[i];
	ll ans[n];
	LazySegmentTree A(a);
	forn(i,n){
		// cout << i << ln;
		ll in = A.query(0,n);
		ans[in]=i+1;
		A.inc(in+1,n,-(i+1));
		A.inc(in,in+1,INF);
	}
	forn(i,n) cout << ans[i] << " ";
	cout << ln;
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