#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
// #include <atcoder/all>
// #include <bits/stdc++.h>
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
// using namespace atcoder;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> p32;
typedef pair<ll, ll> p64;
typedef pair<p64, p64> pp64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<ll> v32;
typedef vector<vector<ll>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln '\n'
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define zero ll(0)
#define set_bits(x) __builtin_popcountll(x)
// #define mll modll998244353
 
ll mpow(ll a, ll b)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    ll t1 = mpow(a, b / 2);
    t1 *= t1;
    t1 %= MOD;
    if (b % 2)
        t1 *= a;
    t1 %= MOD;
    return t1;
}
 
ll mpow(ll a, ll b, ll p)
{
    if (b == 0)
        return 1;
    if (a == 0)
        return 0;
    ll t1 = mpow(a, b / 2, p);
    t1 *= t1;
    t1 %= p;
    if (b % 2)
        t1 *= a;
    t1 %= p;
    return t1;
}
 
ll modinverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
 
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
 
ll range(ll l, ll r)
{
    return l + mt() % (r - l + 1);
}
 
ll rev(ll v)
{
    return mpow(v, MOD - 2);
}
 
ll ceil(ll p, ll q)
{
    return (p + q - 1) / q;
}

class SegmentTree {
	ll n;
	v64 t;

	public:

	SegmentTree(ll n1){
		n = n1;
		t.assign(2*n,0);
		// forn(i,n) t[n+i]=a[i];
		// if(!type) build();
	}

	ll at(ll index){
		return t[index];
	}

	void build() {  // build the tree
	  rforn(i,n-1) t[i] = max(t[i<<1],t[i<<1|1]);
	}

	void modify(ll p, ll value) {  // set value at position p
	  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p],t[p^1]);
	}

	ll query(ll l, ll r) {  // sum on interval [l, r)
	  ll res = -INF;
	  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	    if (l&1) res = max(res,t[l++]);
	    if (r&1) res = max(res,t[--r]);
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

void solve()
{
    ll n;
    cin >> n;
    ll h[n],val[n];
    forn(i,n) cin >> h[i];
    forn(i,n) {
    	cin >> val[i];
    }
    v64 l(n,-1);
    vp64 vec;
    forn(i,n){
    	while(sz(vec) && vec.back().fi>h[i]){
    		vec.pop_back();
    	}
    	if(sz(vec)){
    		l[i] = vec.back().se;
    	}
    	vec.pb(mp(h[i],i));
    }
    SegmentTree S(n);
    forn(i,n){
    	// cout << l[i] << ln;
    	ll cur = -INF;
    	if(l[i]==-1) cur = max(cur,val[i]);
    	else {
    		cur = max(cur,S.query(l[i],l[i]+1));
    	}
    	cur = max(cur,val[i]+S.query(max(zero,l[i]),i));
    	S.modify(i,cur);
    	if(i==n-1) 
    		cout << cur << ln;
    }
    
}
 
int main()
{
    fast_cin();
    ll t = 1;
    // cin >> t;
    forn(i, t)
    {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}