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
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
 
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
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef tree<
  p64, null_type, less<p64>, rb_tree_tag, tree_order_statistics_node_update>
  ordered_set;
 
ll mpow(ll a, ll b){
	if(a==0) return 0;
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

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
 
ll range(ll l, ll r){
	return l + mt()%(r-l+1);
}
 
ll rev(ll v){
	return mpow(v,MOD-2);
}

ll nc2(ll v){
	return (v*(v-1))/2;
}

class LazySegmentTree {
	ll n;
	v64 t;
	ll h;
	v64 d;

	public:

	LazySegmentTree(const v64 &a){
		n = (ll)a.size();
		h = sizeof(ll) * 8 - __builtin_clz(n);
		t.assign(2*n,0);
		d.assign(n,0);
		forn(i,n) t[n+i]=a[i];
		build();
	}

	void build() {  // build the tree
	  rforn(i,n-1) t[i] = max(t[i<<1],t[i<<1|1]);
	}

	void apply(ll p, ll value) {
	  t[p] += value;
	  if (p < n) d[p] += value;
	}

	void build(ll p) {
	  while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
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

	void inc(ll l, ll r, ll value) { // range [l,r) 
	  l += n, r += n;
	  ll l0 = l, r0 = r;
	  for (; l < r; l >>= 1, r >>= 1) {
	    if (l&1) apply(l++, value);
	    if (r&1) apply(--r, value);
	  }
	  build(l0);
	  build(r0 - 1);
	}

	ll query(ll l, ll r) { // range [l,r) 
	  l += n, r += n;
	  push(l);
	  push(r - 1);
	  ll res = -INF;
	  for (; l < r; l >>= 1, r >>= 1) {
	    if (l&1) res = max(res, t[l++]);
	    if (r&1) res = max(t[--r], res);
	  }
	  return res;
	}
};

void solve(){
	ll n;
	cin >> n;
	pair<p64,ll> a[n];
	forn(i,n) cin >> a[i].fi.se >> a[i].fi.fi >> a[i].se;
	sort(a,a+n);
	map<ll,ll> l,r;
	l[-INF]=r[-INF]=0;
	ll li=1,ri=1;
	v64 vec(n,0);
	LazySegmentTree L(vec),R(vec);
	ordered_set left,right;
	left.insert(mp(-INF,0));
	right.insert(mp(-INF,0));
	forn(i,n){
		if(a[i].se==1){
			left.insert(mp(a[i].fi.fi,li));
			ll in = right.order_of_key(mp(a[i].fi.se,0));
			R.inc(0,in,1);
			L.inc(li,li+1,R.query(0,in));
			li++;
		}
		else{
			right.insert(mp(a[i].fi.fi,ri));
			ll in = left.order_of_key(mp(a[i].fi.se,0));
			L.inc(0,in,1);
			R.inc(ri,ri+1,L.query(0,in));
			ri++;
		}
	}
	cout << L.query(0,n) << ln;
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