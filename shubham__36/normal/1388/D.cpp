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
#define INF 1e18
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

vv64 gr;
v64 a,b,top,id,vis;

void dfs(ll v){
	vis[v]=1;
	for(auto it : gr[v]) if(!vis[it]) dfs(it);
	top.pb(v);
}

void solve(){
	ll n;
	cin >> n;
	a.resize(n);
	b.resize(n);
	id.resize(n,0);
	vis.resize(n,0);
	gr.resize(n);
	forn(i,n){
		cin >> a[i];
	}
	forn(i,n){
		cin >> b[i];
		b[i]--;
		if(b[i]!=-2){
			gr[i].pb(b[i]);
			id[b[i]]++;
		}
	}
	forn(i,n){
		if(id[i]==0) dfs(i);
	}
	// for(auto it : top) cout << it << " ";
	// cout << ln;
	v64 ans;
	v64 pr(n,0);
	ll tot=0;
	rforn(j,n-1){
		ll i = top[j];
		if(a[i]>=0){
			pr[i]=1;
			ans.pb(i);
			// cout << i << " ";
			tot+=a[i];
			if(b[i]!=-2) a[b[i]]+=a[i];
		}
	}
	forn(j,n){
		ll i = top[j];
		if(!pr[i]){
			pr[i]=1;
			ans.pb(i);
			// cout << i << " ";
			tot+=a[i];
			if(b[i]!=-2) a[b[i]]+=a[i];
		}
	}
	cout << tot << ln;
	for(auto it : ans) cout << it+1 << " ";
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