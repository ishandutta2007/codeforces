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
ll MOD = 1e9+7;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln '\n'
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define zero ll(0)
 
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
	v64 t;

	public:

	SegmentTree(ll n1){
		n = n1;
		t.assign(2*n,0);
	}

	ll at(ll index){
		return t[index];
	}

	void build() {  // build the tree
	  rforn(i,n-1) t[i] = t[i<<1] + t[i<<1|1];
	}

	void modify(ll p, ll value) {  // set value at position p
	  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
	}

	ll query(ll l, ll r) {  // sum on interval [l, r)
	  ll res = 0;
	  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	    if (l&1) res += t[l++];
	    if (r&1) res += t[--r];
	  }
	  return res;
	}

	void modify(ll l, ll r, ll value) {
	  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	    if (l&1) t[l++] += value;
	    if (r&1) t[--r] += value;
	  }
	}

	ll query(ll p) {
	  ll res = 0;
	  for (p += n; p > 0; p >>= 1) res += t[p];
	  return res;
	}

	void push() {
	  forn (i,n) {
	    t[i<<1] += t[i];
	    t[i<<1|1] += t[i];
	    t[i] = 0;
	  }
	}
};

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	ll base = -1;
	SegmentTree S(n+5);
	v64 vec;
	forn(i,n){
		cin >> a[i];
		if(i){
			ll pr1 = S.query(i-1);
			while(a[i]-pr1 > 1){
				// cout << "entered" << ln;
				if(base == -1){
					ll totround = (a[i]-pr1)/(i+1);
					S.modify(0,i,totround);
					pr1 += totround;
					a[i] -= totround*i;
					ll rem = max(zero,a[i]-pr1-1);
					if(rem){
						S.modify(0,rem,1);
						vec.pb(rem);
						base = rem;
					}
					a[i] -= rem;
				}
				else{
					if((a[i]-pr1-1) >= i-base){
						// cout << "entered1" << ln;
						S.modify(base,i,1);
						pr1++;
						a[i] -= i-base;
						vec.pop_back();
						if(sz(vec)) base = vec.back();
						else base = -1;
					}
					else{
						S.modify(base,(a[i]-pr1-1)+base,1);
						vec.pop_back();
						vec.pb((a[i]-pr1-1)+base);
						base = (a[i]-pr1-1)+base;
						a[i] -= (a[i]-pr1-1);
					}
				}
			}
			if(a[i]==pr1){
				vec.pb(i);
				base = i;
			}
		}
		S.modify(i,i+1,a[i]);
		// forn(i,n) cout << S.query(i) << " ";
		// cout << ln;
	}
	forn(i,n) cout << S.query(i) << " ";
	cout << ln;
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