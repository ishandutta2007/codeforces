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
 
ll range(ll l, ll r){
	return l + rand()%(r-l+1);
}
 
ll rev(ll v){
	return mpow(v,MOD-2);
}

ll n;
vv64 gr;
v64 size1, block;

bool cmp(ll u, ll v){
	return size1[u]>size1[v];
}

ll ask(ll a, ll b){
	cout << "? " << a+1 << " " << b+1 << endl;
	ll v;
	cin >> v;
	if(v==-1) exit(0);
	v--;
	return v;
}
 
void dfs(ll v, ll p) {
	size1[v] = 1;
	for(auto u : gr[v]) {
		if(u != p && !block[u]) {
			dfs(u, v);
			size1[v] += size1[u];
		}
	}
	sort(all(gr[v]),cmp);
}

ll get(ll v, ll p, ll n) {
	for(auto u : gr[v]) {
		if(u != p && 2 * size1[u] > n && !block[u]) {
			return get(u, v, n);
		}
	}
	return v;
}

ll find_centroid(ll v, ll p) {
	fill(begin(size1), end(size1), 0);
	dfs(v, p);
	return get(v, p, size1[v]);
}

void solve(){
	cin >> n;
	gr.resize(n);
	size1.assign(n, 0);
	block.assign(n, 0);
	forn(i,n-1){
		ll a,b;
		cin >> a >> b;
		a--,b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	ll v = find_centroid(0,-1);
	dfs(v,-1);
	while(size1[v]!=1){
		v64 vec;
		for(auto it : gr[v]){
			if(!block[it]) vec.pb(it);
		}
		ll in = 0;
		while(in < sz(vec)){
			if(in+1 == sz(vec)){
				ll ans = ask(vec[in],v);
				if(ans == v){
					cout << "! " << v+1 << endl;
					return;
				}
				else{
					block[v]=1;
					v = ans;
					break;
				}
			}
			else{
				ll ans = ask(vec[in],vec[in+1]);
				if(ans == v){
					block[vec[in]]=1;
					block[vec[in+1]]=1;
				}
				else{
					block[v]=1;
					v = ans;
					break;
				}
			}
			in+=2;
		}
		v = find_centroid(v,-1);
		dfs(v,-1);
	}
	cout << "! " << v+1 << endl;
}
 
int main()
{
	// fast_cin();
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}