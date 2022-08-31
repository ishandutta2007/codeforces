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
ll MOD = 998244353;
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
#define INF 2e18
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

ll n;

void no(){
	cout << -1 << ln;
	exit(0);
}

bool f(string s){
	string ans = s;
	forn(i,n-1){
		if(ans[i]=='_'){
			ans[i]='#';
			i++;
		}
		else{
			return false;
		}
	}
	if(s[n-2]=='_') return false;
	v64 ans1;
	ans1.pb(0);
	forn(i,n){
		if(ans[i]=='#'){
			ll cur = ans1.back()+1;
			ans1.pop_back();
			ans1.pb(cur);
		} 
		else{
			ans1.pb(0);
		}
	}
	cout << sz(ans1) << ln;
	for(auto it: ans1) cout << it <<  " ";
	cout << ln;
	exit(0);
}

bool g(string s){
	forn(i,2){
		if(s[i]=='#' || s[n-1-i]=='#') return false;
	}
	string ans = s;
	forn(i,n-2){
		if(ans[i+2]=='#'){
			ans[i]='#';
			ans[i+1]='#';
		}
	}
	forn(i,n-1){
		if(s[i]=='#' && s[i+1]=='_' && ans[i+1]=='#') return false;
	}
	forn(i,n-3){
		if(ans[i]=='#' && ans[i+1]=='_' && ans[i+2]=='_' && ans[i+3]=='#') return false;
	}
	if(ans[n-4]=='#' && ans[n-3]=='_') return false;
	if(ans[1]=='#' && ans[0]=='_') return false;
	forn(i,n-2){
		if(ans[i]=='#') continue;
		else if(i && ans[i-1]=='#' && ans[i]=='_') {
			continue;
		}
		else if(ans[i]=='_' && ans[i+1]=='_'){
			ans[i]='#';
		}
		else{
			ans[i-1]='#';
		}
	}
	if(ans[n-3]=='_') ans[n-3]='#';
	v64 ans1;
	ans1.pb(0);
	forn(i,n){
		if(ans[i]=='#'){
			ll cur = ans1.back()+1;
			ans1.pop_back();
			ans1.pb(cur);
		} 
		else{
			ans1.pb(0);
		}
	}
	while(ans1.back()==0) ans1.pop_back();
	cout << sz(ans1) << ln;
	for(auto it: ans1) cout << it <<  " ";
	cout << ln;
	exit(0);
}

bool g1(string s){
	forn(i,3){
		if(s[i]=='#' || s[n-1-i]=='#') return false;
	}
	string ans = s;
	forn(i,n-3){
		if(ans[i+3]=='#'){
			ans[i]='#';
			ans[i+1]='#';
			ans[i+2]='#';
		}
	}
	forn(i,n-1){
		if(s[i]=='#' && s[i+1]=='_' && ans[i+1]=='#') return false;
	}
	forn(i,n-3){
		if(ans[i]=='#' && ans[i+1]=='_' && ans[i+2]=='_' && ans[i+3]=='#') return false;
	}
	if(ans[n-5]=='#' && ans[n-4]=='_') return false;
	if(ans[1]=='#' && ans[0]=='_') return false;
	forn(i,n-3){
		if(ans[i]=='#') continue;
		else if(i && ans[i-1]=='#') {
			continue;
		}
		else if(ans[i]=='_' && ans[i+1]=='_'){
			ans[i]='#';
		}
		else{
			ans[i-1]='#';
		}
	}
	if(ans[n-4]=='_') ans[n-4]='#';
	v64 ans1;
	ans1.pb(0);
	forn(i,n){
		if(ans[i]=='#'){
			ll cur = ans1.back()+1;
			ans1.pop_back();
			ans1.pb(cur);
		} 
		else{
			ans1.pb(0);
		}
	}
	while(ans1.back()==0) ans1.pop_back();
	cout << sz(ans1) << ln;
	for(auto it: ans1) cout << it <<  " ";
	cout << ln;
	exit(0);
}

bool g2(string s){
	forn(i,1){
		if(s[i]=='#' || s[n-1-i]=='#') return false;
	}
	string ans = s;
	forn(i,n-1){
		if(ans[i+1]=='#'){
			ans[i]='#';
		}
	}
	forn(i,n-1){
		if(s[i]=='#' && s[i+1]=='_' && ans[i+1]=='#') return false;
	}
	forn(i,n-3){
		if(ans[i]=='#' && ans[i+1]=='_' && ans[i+2]=='_' && ans[i+3]=='#') return false;
	}
	if(ans[n-3]=='#' && ans[n-2]=='_') return false;
	if(ans[1]=='#' && ans[0]=='_') return false;
	forn(i,n-1){
		if(ans[i]=='#') continue;
		else if((i && ans[i-1]=='#')) {
			continue;
		}
		else if(ans[i]=='_' && ans[i+1]=='_'){
			ans[i]='#';
		}
		else{
			return false;
		}
	}
	if(ans[n-2]=='_') return false;
	v64 ans1;
	ans1.pb(0);
	forn(i,n){
		if(ans[i]=='#'){
			ll cur = ans1.back()+1;
			ans1.pop_back();
			ans1.pb(cur);
		} 
		else{
			ans1.pb(0);
		}
	}
	while(ans1.back()==0) ans1.pop_back();
	cout << sz(ans1) << ln;
	for(auto it: ans1) cout << it <<  " ";
	cout << ln;
	exit(0);
}

void solve(){
	string s;
	cin >> s;
	n = sz(s);
	if(s[0]=='#' || s[n-1]=='#'){
		if(s[0]=='_' || s[n-1]=='_') no();
		forsn(i,1,n){
			if(s[i-1]=='_' && s[i]=='_') no();
		}
		v64 ans;
		ans.pb(0);
		forn(i,n){
			if(s[i]=='#'){
				ll cur = ans.back()+1;
				ans.pop_back();
				ans.pb(cur);
			}
			else{
				ans.pb(0);
			}
		}
		cout << sz(ans) << ln;
		for(auto it: ans) cout << it <<  " ";
		cout << ln;
		return;
	}
	bool bo = true;
	for(auto it : s){
		if(it=='#') bo = false;
	}
	if(bo){
		cout << 0 << ln;
		cout << ln;
		return;
	}
	f(s);
	g(s);
	g1(s);
	g2(s);
	no();
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