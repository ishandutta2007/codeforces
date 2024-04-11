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

vv64 gr;
v64 dp;
ll ans;
vp64 vec;
v64 deg;

void inc(ll v, bool bo){
	if(dp[v] == ans){
		if(bo) vec.pb(mp(v+1,ans-deg[v]));
		dp[v]=ans-deg[v];
	}
	dp[v]++;
}

void dfs(ll v, ll p, ll val){
	vec.pb(mp(v+1,val));
	dp[v]=val;
	inc(v,(p==-1 ? 0 : 1));
	for(auto it : gr[v]){
		if(it != p){
			dfs(it,v,dp[v]);
			vec.pb(mp(v+1,dp[v]));
			inc(v,(p==-1 ? 0 : 1));
		}
	}
	if(p!=-1 && dp[v]!=dp[p]) vec.pb(mp(v+1,dp[p]-1));
}

void solve(){
	ll n;
	cin >> n;
	deg.resize(n,0);
	gr.resize(n);
	dp.resize(n,0);
	forn(i,n-1){
		ll a,b;
		cin >> a >> b;
		a--,b--;
		gr[a].pb(b);
		gr[b].pb(a);
		deg[a]++,deg[b]++;
	}
	forn(i,n) ans = max(ans,deg[i]);
	dfs(0,-1,0);
	cout << sz(vec) << ln;
	for(auto it : vec) cout << it.fi << " " << it.se << ln;
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