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
ll MOD = 998244353;
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

char g(ll v){
	if(v==0) return 'W';
	return 'B';
}

ll f(char c){
	if(c == 'W') return 0;
	return 1;
}

void solve(){
	ll n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	p64 a[n];
	forn(i,n) a[i] = mp(INF,0);
	forn(i,n){
		if(s[(i+1)%n]==s[i] || s[(i+n-1)%n]==s[i]){
			a[i]=mp(0,f(s[i]));
		}
	}
	ll k1 = -1;
	ll c = 0;
	forn(i,2*n){
		if(a[i%n].fi == 0){
			k1 = 1;
			c = a[i%n].se;
		}
		else if(k1==-1){
			continue;
		}
		else{
			if(k1 < a[i%n].fi){
				a[i%n] = mp(k1,c);
			}
			k1++;
		}
	}
	k1 = -1;
	rforn(i,2*n-1){
		if(a[i%n].fi == 0){
			k1 = 1;
			c = a[i%n].se;
		}
		else if(k1==-1){
			continue;
		}
		else{
			if(k1 < a[i%n].fi){
				a[i%n] = mp(k1,c);
			}
			k1++;
		}
	}
	forn(i,n){
		// cout << a[i].fi << " " << a[i].se << ln;
		if(k>=a[i].fi){
			cout << g(a[i].se);
		}
		else{
			cout << g((f(s[i])+k)%2);
		}
	}
	cout << ln;
}
 
int main()
{
	fast_cin();
    ll t=1;
    // cin>>t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}