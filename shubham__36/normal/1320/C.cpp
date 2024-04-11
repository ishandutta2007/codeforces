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

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
 
ll range(ll l, ll r){
	return l + mt()%(r-l+1);
}
 
ll rev(ll v){
	return mpow(v,MOD-2);
}

class Recursive{
	ll n;
	v64 tr,lazy;

	public:

	Recursive(ll n1){
		n = n1;
		tr.assign(4*n+5,0);
		lazy.assign(4*n+5,0);
	}

	void pushdown(ll node) {
		if(lazy[node]) {
			tr[node*2]+=lazy[node];
			tr[node*2+1]+=lazy[node];
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
			lazy[node]=0;
		}
	}

	void add(ll node, ll l, ll r, ll ll1, ll rr, ll val) {
		if(l>rr||ll1>r)
			return;
		if(l<=ll1&&rr<=r) {
			tr[node]+=val;
			lazy[node]+=val;
			return;
		}
		pushdown(node);
		add(2*node,l,r,ll1,(ll1+rr)/2,val);
		add(2*node+1,l,r,1+(ll1+rr)/2,rr,val);
		tr[node]=max(tr[2*node],tr[2*node+1]);
	}

	ll query(ll node, ll l, ll r, ll ll1, ll rr) {
		if(l>rr||ll1>r)
			return -INF;
		if(l<=ll1&&rr<=r)
			return tr[node];
		pushdown(node);
		return max(query(node*2,l,r,ll1,(ll1+rr)/2),query(node*2+1,l,r,(ll1+rr)/2+1,rr));
	}
};

const ll M = 1024*1024; 

void solve(){
	ll n,m,p;
	cin >> n >> m >> p;
	p64 a[n],b[m];
	pair<p64,ll> c[p];
	forn(i,n){
		cin >> a[i].fi >> a[i].se;
	}
	forn(i,m){
		cin >> b[i].fi >> b[i].se;
	}
	forn(i,p){
		cin >> c[i].fi.fi >> c[i].fi.se >> c[i].se;
	}
	sort(a,a+n);
	sort(b,b+m);
	sort(c,c+p);
	v64 b1(M+1,-INF);
	forn(i,m){
		b1[b[i].fi]=max(b1[b[i].fi],-b[i].se);
	}
	rforn(i,M-1) b1[i]=max(b1[i],b1[i+1]);
	// forn(i,20) cout << b1[i] << " ";
	// cout << ln;
	Recursive tr(M);
	// cout << tr.query(1,1,M,1,M) << ln;
	forsn(i,1,M+1) tr.add(1,i,i,1,M,b1[i]);
	// cout << tr.query(1,1,M,1,M) << ln;
	ll ans = -INF;
	ll in = 0;
	forn(i,n){
		while(in<p && c[in].fi.fi<a[i].fi) {
			tr.add(1,c[in].fi.se+1,M,1,M,c[in].se); 
			// cout << "add " << c[in].fi.se+1 << " " << c[in].se << ln;
			in++;
		}
		ans = max(ans,tr.query(1,1,M,1,M)-a[i].se);
		// cout << tr.query(1,1,M,1,M) << ln;
	}
	cout << ans << ln;
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