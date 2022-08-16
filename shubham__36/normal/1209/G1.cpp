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
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
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
	ll t1 = mpow(a,b/2);
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

ll lim = 2e5+5;
v64 st(lim,lim),en(lim,-1),mcount(lim,0);
vv64 gr(lim);
v64 vis(lim,0);

p64 dfs(ll v){
	vis[v]=1;
	ll cmax = mcount[v];
	ll csum = mcount[v];
	forn(i,sz(gr[v])){
		if(vis[gr[v][i]]==0){
			p64 ret = dfs(gr[v][i]);
			cmax = max(cmax,ret.se);
			csum = csum += ret.fi;
		}
	}
	return mp(csum,cmax);
}

void solve(){
	ll n,q;
	cin >> n >> q;
	ll a[n];
	forn(i,n) cin >> a[i];
	forn(i,n){
		st[a[i]]=min(st[a[i]],i);
		en[a[i]]=max(en[a[i]],i);\
		mcount[a[i]]++;
	}
	forn(i,n-1){
		if(a[i]==a[i+1]) continue;
		if(st[a[i+1]]<i || en[a[i]]>i+1){
			gr[a[i+1]].pb(a[i]);
			gr[a[i]].pb(a[i+1]);
			ll nst = min(st[a[i]],st[a[i+1]]);
			ll nen = max(en[a[i]],en[a[i+1]]);
			st[a[i]]=st[a[i+1]]=nst;
			en[a[i]]=en[a[i+1]]=nen;
		}
	}
	ll ans = 0;
	forn(i,n){
		if(vis[a[i]]==0){
			p64 ret = dfs(a[i]);
			ans += ret.fi-ret.se;
		}
	}
	cout << ans << ln;
}
 
int main()
{
	fast_cin();
    ll t=1;
	// cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}