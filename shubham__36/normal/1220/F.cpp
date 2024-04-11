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
ll MOD = 998244353;
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

class SegmentTree {
	ll n;
	vp64 t;

	public:

	void create(ll n1){
		n = n1;
		t.resize(2*n);
		forn(i,2*n) t[i]=mp(0,0);
	}

	// ll at(ll index){
	// 	return t[index];
	// }

	// void build() {  // build the tree
	//   rforn(i,n-1) t[i] = t[i<<1] + t[i<<1|1];
	// }

	void modify(ll p, p64 value) {  // set value at position p
	  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p],t[p^1]);
	}

	p64 query(ll l, ll r) {  // sum on interval [l, r)
	  p64 res = mp(INF,0);
	  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	    if (l&1) res = min(res,t[l++]);
	    if (r&1) res = min(res,t[--r]);
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

SegmentTree S;

ll f(ll l, ll r){
	if((r-l)<2) return r-l;
	p64 v = S.query(l,r);
	return 1+max(f(l,v.se),f(v.se+1,r));
}

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	ll in = 0;
	forn(i,n) {
		cin >> a[i];
		if(a[i]==1) in=i;
	}
	if(n==1){
		cout << "1 0" << ln;
		return;
	}
	S.create(n-1);
	forn(i,n-1){
		S.modify(i,mp(a[(in+1+i)%n],i));
	}
	ll l=0,r=n-1;
	while(l<r){
		ll m = (l+r)/2;
		ll v1 = f(0,m), v2 = f(m,n-1);
		if(v1==v2){
			l = m;
			r = m;
		}
		else if(v1>v2) r=m;
		else l=m+1;
	}
	ll v1 = f(0,l), v2 = f(l,n-1);
	cout << 1+max(v1,v2) << " " << (in+1+l)%n << ln;
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