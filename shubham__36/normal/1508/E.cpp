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
			if (rank[x] > rank[y]) {
				p[y] = x;
				sz[x] += sz[y];
			}
			else { 
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++; 
				sz[y] += sz[x];
			}
		} 
	} 
	ll sz1(ll i){ // returns the sz[i] (to check the size of group containing i use sz1(findSet(i)))
		return sz[i];
	}
};

const ll N = 3e5+5;
ll a[N],st[N],en[N],r[N],dep[N],p[N];
v64 gr[N];
ll cnt,cc;

void dfs1(ll v, ll pp, ll d){
	for(auto it : gr[v]) dfs1(it,v,d+1);
	en[cnt++] = v;
	p[v] = pp;
	dep[v] = d;
}

void dfs2(ll v){
	st[v] = cnt++;
	for(auto it : gr[v]) dfs2(it);
}

void dfs3(ll v){
	if(a[v]<cc) return;
	if(a[v] != cnt++){
		cout << "NO" << ln;
		exit(0);
	}
	for(auto it : gr[v]) dfs3(it);
}

void solve(){
	ll n;
	cin >> n;
	forn(i,n) {
		cin >> a[i];
		a[i]--;
		r[a[i]]=i;
	}
	set<p64> tg[n];
	forn(i,n-1){
		ll u,v;
		cin >> u >> v;
		u--,v--;
		tg[u].insert(mp(a[v],v));
	}
	forn(i,n){
		for(auto it : tg[i]) gr[i].pb(it.se);
	}
	cnt = 0;
	dfs1(0,-1,0);
	cnt = 0;
	dfs2(0);
	cc = 0;
	ll ans = 0;
	while(cc<n && a[en[cc]]==cc) {
		ans += dep[en[cc]];
		cc++;
	}
	if(cc!=n){
		ll cur = r[cc];
		ans += dep[cur];
		while(dep[cur]){
			swap(a[cur],a[p[cur]]);
			cur = p[cur];
		}
		cur = en[cc];
		while(true){
			if(cur == r[cc]) break;
			if(dep[cur]==0){
				cout << "NO" << ln;
				exit(0);
			}
			cur = p[cur];
		}
		cnt = cc;
		dfs3(0);
	}
	cout << "YES" << ln;
	cout << ans << ln;
	forn(i,n) cout << st[i]+1 << " ";
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