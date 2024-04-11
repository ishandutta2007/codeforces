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
ll MOD = 1e12+13;
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

vp64 vec;
ll maxx,minx,maxy,miny,maxxy,minxy;
p64 ans;

bool check(ll val){
	forsn(i,maxx-val,minx+val+1){
		ll f = max(maxy-val,i-(minxy+val)), s = min(miny+val,i-(maxxy-val));
		if(i==0) f=max(f,(ll)1);
		else f = max(f,(ll)0);
		if(f<=s){
			ans = mp(i,s);
			return 1;
		}
	}
	return 0;
}

void solve(){
	ll n;
	cin >> n;
	minx = miny = minxy = INF;
	maxx = maxy = maxxy = -INF;
	forn(i,n){
		string s;
		cin >> s;
		ll a=0,b=0;
		for(auto it : s) {if(it=='B') a++; else b++;}
		maxx=max(maxx,a);
		maxy=max(maxy,b);
		minx=min(minx,a);
		miny=min(miny,b);
		maxxy=max(maxxy,a-b);
		minxy=min(minxy,a-b);
	}
	ll l = 0, r = 2e6;
	while(l<r){
		ll mid = (l+r)/2;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	check(l);
	cout << l << ln;
	forn(i,ans.fi) cout << 'B';
	forn(i,ans.se) cout << 'N';
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