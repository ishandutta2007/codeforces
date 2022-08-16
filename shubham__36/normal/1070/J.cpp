#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
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
typedef pair<long long int,long long int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<long long int> v32;
typedef vector<vector<long long int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244853;
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
 
ll n,m,k;
v64 dp,dp1,c;
multiset<ll> s1;
set<ll> s;
v64 vans;
 
void f(){
	dp.resize(k-m+10,0);
	dp1.resize(k-m+10,0);
	dp[0]=1;
	ll ans = n*m;
	for(auto ci : s1){
		forsn(j,ci,k-m+1){
			if(dp[j-ci]!=0) dp1[j]=1;
		}
		forsn(j,ci,k-m+1){
			if(dp1[j]!=0) dp[j] = 1;
			dp1[j]=0;
		}
	}
	rforn(i,k-m){
		if(dp[i]){
			vans.pb(i);
		}
	}
	dp.clear();
	dp1.clear();
}
 
void solve(){
	cin >> n >> m >> k;
	c.resize(26,0);
	forn(i,k){
		char ch;
		cin >> ch;
		c[ch-'A']++;
	}
	forn(i,26){
		if(c[i]!=0) {
			s.insert(c[i]);
			s1.insert(c[i]);
		}
	}
	ll ans = n*m;
	for(auto ci : s){
		s1.erase(s1.find(ci));
		f();
		s1.insert(ci);
		forn(i,sz(vans)){
			ll ret = vans[i];
			if(ret>=n) ans=0;
			else if(ret+ci-k+m>0) ans = min(ans,(n-ret)*(ret+ci-k+m));
		}
		vans.clear();
	}
	cout << ans << ln;
	c.clear();
	s.clear();
	s1.clear();
}
 
int main()
{
	fast_cin();
    ll t=1;
	cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}