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
#define set_bits(x) __builtin_popcountll(x)
 
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

void solve(){
	ll n;
	cin >> n;
	ll x[n],y[n];
	ll cx[n],cy[n];
	set<ll> xs,ys;
	forn(i,n){
		cin >> x[i] >> y[i];
		xs.insert(x[i]);
		ys.insert(y[i]);
	}
	unordered_map<ll,ll> rx,ry;
	ll index = 0;
	for(auto it : xs) rx[it]=index++;
	index = 0;
	for(auto it : ys) ry[it]=index++;
	forn(i,n){
		cx[i]=rx[x[i]],cy[i]=ry[y[i]];
	}
	ll l = 1, r = 2e9+5;
	while(l!=r){
		ll mid = (l+r)/2;
		UnionFind U(n);
		ll dc = n;
		forn(i,n){
			forsn(j,i+1,n){
				if((x[i]==x[j] && abs(y[i]-y[j])<=mid) || (y[i]==y[j] && abs(x[i]-x[j])<=mid)){
					if(!U.isSameSet(i,j)){
						dc--;
						U.unionSet(i,j);
					}
				}
			}
		}
		bool bo=0;
		if(dc==1) bo=1;
		else if(dc>4) bo=0;
		else{
			ll factor = 1e3+5;
			v64 m(1e6+1e4,0); 
			ll sv = 0;
			ll ms = 0;
			ll pr[n],rv[n];
			forn(i,n){
				pr[i] = U.findSet(i);
				if(pr[i]==i) {
					rv[i]=sv++;
				}
			}
			forn(i,n){
				forsn(j,i+1,n){
					if(pr[i]==pr[j]) continue;
					if(abs(x[i]-x[j])<=mid && abs(y[i]-y[j])<=mid){
						ll a1 = rv[pr[i]], a2 = rv[pr[j]];
						if(a1>a2) swap(a1,a2);
						ll cur = (1<<(4*a1+a2-1));
						m[factor*cx[i]+cy[j]]|=cur;
						ms = max(ms,(ll)__builtin_popcountll(m[factor*cx[i]+cy[j]]));
						m[factor*cx[j]+cy[i]]|=cur;
						ms = max(ms,(ll)__builtin_popcountll(m[factor*cx[j]+cy[i]]));
					}
					if(pr[i]!=pr[j] && sv==2 && ((x[i]==x[j] && abs(y[i]-y[j])<=2*mid) || (y[i]==y[j] && abs(x[i]-x[j])<=2*mid))){
						bo = 1;
					}
				}
			}
			if(sv==2 && ms>=1) bo=1;
			if(sv==3 && ms>=2) bo=1;
			if(sv==4 && ms>=4) bo=1;
		}
		if(bo) r = mid;
		else l = mid+1;
	}
	cout << ((l==2e9+5) ? -1 : l) << ln;
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