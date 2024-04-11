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
ll MOD = 998244353;
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

set<p64> s;
vv64 val;

ll f(){
	p64 val1 = *(s.begin());
	s.erase(s.begin());
	return val1.se;
}

ll g(ll v){
	ll ans = val[v].back();
	val[v].pop_back();
	return ans;
}

void h(ll v){
	if(sz(val[v])) s.insert(mp(-sz(val[v]),v));
}

void solve(){
	ll n,m1,m2;
	cin >> n >> m1 >> m2;
	ll a[n],b[n];
	val.resize(n+1);
	forn(i,n){
		cin >> a[i];
		a[i]--;
		b[i]=a[i];
		val[a[i]].pb(i);
	}
	
	ll c = -1;
	forn(i,n+1){
		if(sz(val[i])==0 && c==-1) c = i;
		if(sz(val[i])) s.insert(mp(-sz(val[i]),i));
	}
	ll match = n, match1 = n;
	while(match-2 >= m1){
		if((match-m1)==3 && sz(s)>=3){
			ll v1 = f(),v2 = f(),v3 = f();
			ll in1 = g(v1), in2 = g(v2), in3 = g(v3);
			swap(b[in1],b[in2]);
			swap(b[in2],b[in3]);
			h(v1),h(v2),h(v3);
			match -= 3;
		}
		else if(sz(s)>1){
			ll v1 = f(),v2 = f();
			ll in1 = g(v1), in2 = g(v2);
			swap(b[in1],b[in2]);
			h(v1),h(v2);
			match -= 2;
		}
		else{
			break;
		}
	}
	forn(i,n){
		if(a[i]==b[i] && match>m1){
			b[i]=c;
			match--;
			match1--;
		}
	}
	// cout << match << " " << match1 << ln;
	if(match1 < m2) cout << "NO" << ln;
	else{
		cout << "YES" << ln;
		forn(i,n){
			if(a[i]!=b[i] && b[i]!=c && match1>m2){
				cout << c+1 << " ";
				match1--;
			}
			else{
				cout << b[i]+1 << " ";
			}
		}
		cout << ln;
	}
	s.clear();
	val.clear();
}
 
int main()
{
	fast_cin();
    ll t=1;
    cin >> t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}