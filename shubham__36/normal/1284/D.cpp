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
ll MOD = 231548613323;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
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

class SegmentTree {
	ll n;
	vp64 t;

	public:

	SegmentTree(const vector<pair<p64,p64> > &a){
		n = (ll)a.size();
		t.resize(2*n);
		forn(i,n) t[n+i]=a[i].se;
		build();
	}

	// ll at(ll index){
	// 	return t[index];
	// }

	p64 f(p64 a, p64 b){
		return mp(max(a.fi,b.fi),min(a.se,b.se));
	}

	void build() {  // build the tree
	  rforn(i,n-1) t[i] = f(t[i<<1],t[i<<1|1]);
	}

	// void modify(ll p, ll value) {  // set value at position p
	//   for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
	// }

	p64 query(ll l, ll r) {  // sum on interval [l, r)
	  p64 res = mp(-INF,INF);
	  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	    if (l&1) res = f(res,t[l++]);
	    if (r&1) res = f(res,t[--r]);
	  }
	  return res;
	}

	// void modify(ll l, ll r, ll value) {
	//   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	//     if (l&1) t[l++] += value;
	//     if (r&1) t[--r] += value;
	//   }
	// }

	// ll query(ll p) {
	//   ll res = 0;
	//   for (p += n; p > 0; p >>= 1) res += t[p];
	//   return res;
	// }

	// void push() {
	//   forn (i,n) {
	//     t[i<<1] += t[i];
	//     t[i<<1|1] += t[i];
	//     t[i] = 0;
	//   }
	// }
};

ll n;
vector<pair<p64,p64> > a,b;

ll f(vector<pair<p64,p64> > &vec, ll val){
	ll l=0,r=n;
	while(l!=r){
		ll mid = (l+r)/2;
		if(vec[mid].fi.fi <= val) l=mid+1;
		else r=mid;
	}
	return l;
}

bool check(vector<pair<p64,p64> > &vec){
	SegmentTree T(vec);
	forn(i,n){
		ll en = f(vec,vec[i].fi.se);
		// cout << en << ln;
		p64 res = T.query(i+1,en);
		if(res.fi > vec[i].se.se || res.se < vec[i].se.fi) {
			// cout << i << " " << res.fi << " " << res.se << ln;
			return 1;
		}
	}
	return 0;
}
 
void solve(){
	cin >> n;
	a.resize(n);
	b.resize(n);
	forn(i,n){
		cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se.fi >> a[i].se.se;
		b[i] = mp(a[i].se,a[i].fi);
	}
	sort(all(a));
	sort(all(b));
	if(check(a) || check(b)) cout << "NO" << ln;
	else cout << "YES" << ln;
}
 
int main()
{
	fast_cin();
    ll t=1;
    // cin>>t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}