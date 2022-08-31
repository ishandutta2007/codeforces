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

void solve(){
	ll n,r1,r2,r3,t;
	cin >> n >> r1 >> r2 >> r3 >> t;
	p64 a[n];
	forn(i,n) {
		ll temp;
		cin >> temp;
		a[i] = mp(min(r2,(temp+1)*r1)+r1,temp*r1+r3);
		a[i].fi = min(a[i].fi,a[i].se);
		// cout << a[i].fi << " " << a[i].se << ln;
	}
	ll dp[n];
	dp[0]=a[0].se;
	dp[1]=min(a[0].fi+a[1].fi+3*t,a[0].se+a[1].se+t);
	forsn(i,2,n){
		dp[i]=min(dp[i-2]+a[i-1].fi+a[i].fi+4*t,dp[i-1]+a[i].se+t);
		dp[i]=min(dp[i],dp[i-1]+a[i].fi+3*t);
		// cout << dp[i] << ln;
	}
	cout << min(dp[n-1],((n-3)>=0 ? dp[n-3] : -t)+a[n-2].fi+a[n-1].se+3*t) << ln;
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