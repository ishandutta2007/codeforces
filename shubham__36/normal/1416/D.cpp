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
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<p64,p64> pp64;
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
#define ln '\n'
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define zero ll(0)
#define set_bits(x) __builtin_popcountll(x)
// #define mint modint998244353
 
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

class UnionFind {
	v64 p, sz;
	vv64 grp;
public:
	UnionFind(ll N) {
		p.assign(N, 0);
		sz.assign(N, 1); 
		grp.resize(N);
		forn(i,N) p[i] = i; 
	}
	void remove_edge(ll i, ll j){
		p[i]=i;
		p[j]=j;
	}
	ll findSet(ll i) { // returns the head of group containing element i
		return (p[i] == i) ? i : findSet(p[i]); 
	} 
	bool isSameSet(ll i, ll j) {  // checks whether i and j are in same group
		return findSet(i) == findSet(j); 
	}
	void unionSet(ll i, ll j) { // unify group containing i and j(if already in same set then do nothing)
		if (!isSameSet(i, j)) {
			ll x = findSet(i), y = findSet(j);
			if (sz[x] > sz[y]) {
				p[y] = x;
				sz[x] += sz[y];
			}
			else { 
				p[x] = y; 
				sz[y] += sz[x];
			}
		} 
	} 
	void build(ll index, ll val){
		grp[index].pb(val);
		if(p[index]!=index) build(p[index],val); 
	}
	ll last(ll index){
		if(sz(grp[index])){
			ll ret = grp[index].back();
			grp[index].pop_back();
			return ret;
		}
		else{
			return -1;
		}
	}
	ll sz1(ll i){ // returns the sz[i] (to check the size of group containing i use sz1(findSet(i)))
		return sz[i];
	}
};

void solve(){
	ll n,m,q;
	cin >> n >> m >> q; 
	ll p[n],rp[n];
	p64 edge[m];
	forn(i,n) {
		cin >> p[i];
		p[i]--;
		rp[p[i]]=i;
	}
	forn(i,m){
		cin >> edge[i].fi >> edge[i].se;
		edge[i].fi--,edge[i].se--;
	}
	p64 query[q];
	bool mark[m];
	forn(i,m) mark[i]=0;
	v64 vec;
	forn(i,q){
		ll t,v;
		cin >> t >> v;
		v--;
		query[i]=mp(t,v);
		if(t==2) {
			mark[v]=1;
			vec.pb(v);
		}
	}
	UnionFind U(n);
	forn(i,m){
		if(!mark[i]) U.unionSet(edge[i].fi,edge[i].se);
	}
	vp64 sep;
	rforn(i,sz(vec)-1){
		ll a = U.findSet(edge[vec[i]].fi), b = U.findSet(edge[vec[i]].se);
		if(a!=b) {
			U.unionSet(a,b);
			sep.pb(mp(a,b));
		}
		else{
			sep.pb(mp(-1,-1));
		}
	}
	forn(i,n) U.build(rp[i],rp[i]);
	forn(i,q){
		if(query[i].fi == 1){
			ll a = U.findSet(query[i].se);
			bool bo = 0;
			ll val;
			while((val = U.last(a))>=0){
				if(U.findSet(val) == a && p[val]>=0){
					bo = 1;
					cout << p[val]+1 << ln;
					p[val]=-1;
					break;
				}
			}
			if(!bo){
				cout << 0 << ln;
			}
		}
		else{
			p64 ind = sep.back();
			sep.pop_back();
			if(ind.fi>=0){
				U.remove_edge(ind.fi,ind.se);
			}
		}
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