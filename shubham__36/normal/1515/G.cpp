#pragma GCC optimize("-Ofast")
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
typedef pair<ll,p64> tp;
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

ll nc2(ll n){
	return (n*(n-1))/2;
}

// UnionFind U(n) :- n is number of elements

class UnionFind {
	v64 p, rank, sz;
public:
	UnionFind(ll N) { 
		rank.assign(N, 0);
		p.assign(N, 0);
		sz.assign(N, 1); 
		forn(i,N) p[i] = i; 
	}
	void inc(){
		rank.pb(0);
		p.pb(sz(p));
		sz.pb(1);
	}
	ll findSet(ll i) { // returns the head of group containing element i
		return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
	} 
	bool isSameSet(ll i, ll j) {  // checks whether i and j are in same group
		return findSet(i) == findSet(j); 
	}
	void unionSet(ll i, ll j) { // unify group containing i and j(if already in same set then do nothing)
		if (!isSameSet(i, j)) {
			ll x = findSet(i), y = findSet(j);
			p[x] = y;
		} 
	} 
	ll sz1(ll i){ // returns the sz[i] (to check the size of group containing i use sz1(findSet(i)))
		return sz[i];
	}
};

ll const N = 2e5+5;
vp64 gr[N];
ll vis[N],tot[N],p[N];
UnionFind U(N);
ll dp[N];

void dfs(ll v, ll val, ll dist, ll pr){
	vis[v]=val;
	tot[v]=dist;
	p[v]=pr;
	for(auto it : gr[v]){
		if(!vis[it.fi]) dfs(it.fi,val,dist+it.se,v);
		else if(vis[U.findSet(it.fi)]==val){
			ll v1 = U.findSet(v),v2 = U.findSet(it.fi);
			dp[v1]=gcd(dp[v1],tot[v]-tot[it.fi]+it.se);
			while(v1!=v2){
				ll cur = U.findSet(p[v1]);
				dp[cur]=gcd(dp[cur],dp[v1]);
				U.unionSet(v1,cur);
				v1 = U.findSet(cur);
			}
		}
	}
	vis[v] = N;
}

void solve(){
	ll n,m;
	cin >> n >> m;
	forn(i,m){
		ll a,b,w;
		cin >> a >> b >> w;
		a--,b--;
		gr[a].pb(mp(b,w));
	}
	ll cnt = 1;
	forn(i,n){
		if(!vis[i]){
			dfs(i,cnt++,0,-1);
		}
	}
	// forn(i,n) cout << dp[U.findSet(i)] << ln;
	ll q;
	cin >> q;
	forn(i,q){
		ll a,b,c;
		cin >> a >> b >> c;
		a--;
		ll req = (c-b)%c;
		ll avail = dp[U.findSet(a)];
		ll g = gcd(c,avail);
		if(req%g==0) cout << "YES" << ln;
		else cout << "NO" << ln;
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