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
ll MOD = 163577857;
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

void solve(){
	ll n,k;
	cin >> n >> k;
	ll a[n],b[n];
	ll sum = 0;
	forn(i,n){
		cin >> a[i] >> b[i];
		sum += a[i]+b[i];
	}
	ll rem = sum%k;
	ll ans = sum/k;
	// cout << rem << " " << ans << ln;
	v64 dp(k,0);
	dp[0]=1;
	// for(auto it : dp) cout << it << " ";
	// cout << ln;
	forn(i,n){
		v64 pos;
		forn(i1,min(k,a[i]+1)){
			ll used = a[i]-i1;
			ll crem = used%k;
			if(crem == 0 || (b[i]+crem)>=k) pos.pb(i1);
		}
		// cout << sz(pos) << ln;
		v64 ndp(k,0);
		for(auto it : pos){
			forn(j,k){
				ndp[(j+it)%k]|=dp[j];
			}
		}
		dp = ndp;
		// for(auto it : dp) cout << it << " ";
		// cout << ln;
	}
	forn(i,rem+1) if(dp[i]){
		cout << ans << ln;
		return;
	}
	forn(i,n) swap(a[i],b[i]);
	dp.clear();
	dp.resize(k,0);
	dp[0]=1;
	forn(i,n){
		v64 pos;
		forn(i1,min(k,a[i]+1)){
			ll used = a[i]-i1;
			ll crem = used%k;
			if(crem == 0 || (b[i]+crem)>=k) pos.pb(i1);
		}
		// cout << sz(pos) << ln;
		v64 ndp(k,0);
		for(auto it : pos){
			forn(j,k){
				ndp[(j+it)%k]|=dp[j];
			}
		}
		dp = ndp;
		// for(auto it : dp) cout << it << " ";
		// cout << ln;
	}
	forn(i,rem+1) if(dp[i]){
		cout << ans << ln;
		return;
	}
	cout << ans-1 << ln;
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