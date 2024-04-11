#pragma GCC optimize("Ofast")
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
 
// ll rev(ll v){
// 	return mpow(v,MOD-2);
// }

ll n;
ll cards[52];
ll rcards[52];
bool rev;

void op(v64 vec){
	ll tmp[52];
	ll end = n;
	ll in = 0;
	for(auto it : vec){
		end -= it;
		forsn(j,end,end+it){
			tmp[j]=cards[in];
			in++;
		}
	}
	forn(i,n){
		cards[i]=tmp[i];
		rcards[tmp[i]]=i;
	}
}

void solve(){
	rev = 0;
	cin >> n;
	forn(i,n){
		cin >> cards[i];
		cards[i]--;
		rcards[cards[i]]=i;
	}
	vv64 ans;
	// cout << n << ln;
	forn(i,n-1){
		v64 vec;
		ll p1 = rcards[0], p2 = rcards[i+1];
		// cout << p1 <<  " " << p2 << ln;
		if(p2 > p1){
			if(rev){
				if(p1-i > 0) vec.pb(p1-i);
				vec.pb(i+1);
				vec.pb(p2-p1);
			}
			else{
				if(p1 > 0) vec.pb(p1);
				forn(j,i+1) vec.pb(1);
				vec.pb(p2-p1-i);
				rev = 1;
			}
			if(n-1-p2 > 0) vec.pb(n-1-p2);
		}
		else{
			if(p2 > 0) vec.pb(p2);
			if(rev){
				vec.pb(p1-p2-i);
				forn(j,i+1) vec.pb(1);
				if(n-1-p1 > 0) vec.pb(n-1-p1);
				rev = 0;
			}
			else{
				vec.pb(p1-p2);
				vec.pb(i+1);
				if(n-1-p1-i > 0) vec.pb(n-1-p1-i);
			}
		}
		v64 tmp;
		tmp.pb(sz(vec));
		// cout << sz(vec) << " ";
		for(auto it : vec) tmp.pb(it);
		ans.pb(tmp);
		// cout << ln;
		op(vec);
	}
	if(rev){
		cout << n << ln;
		for(auto it : ans){
			for(auto it1 : it) cout << it1 << " ";
			cout << ln;
		}
		cout << n << " ";
		forn(i,n) cout << 1 << " ";
		cout << ln;
	}
	else{
		cout << n-1 << ln;
		for(auto it : ans){
			for(auto it1 : it) cout << it1 << " ";
			cout << ln;
		}
	}
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