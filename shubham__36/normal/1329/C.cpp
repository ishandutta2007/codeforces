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
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e17
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
	ll g,h;
	cin >> g >> h;
	ll sz1 = (1<<(g+1))+5;
	ll a[sz1];
	ll c[sz1],c1[sz1];
	forn(i,sz1) c[i]=c1[i]=a[i]=0;
	forsn(i,1,(1<<g)){
		cin >> a[i];
	}
	rforsn(i,(1<<g)-1,1){
		c[i] = c[2*i] + c[2*i+1] + 1;
	}
	rforsn(i,(1<<h)-1,1){
		c1[i] = c1[2*i] + c1[2*i+1] + 1;
	}
	// cout << c[2] << ln;
	vp64 vec;
	v64 ans;
	ll cur = 1;
	forn(i,(1<<g)-(1<<h)){ 
		ll lcur = cur;
		ans.pb(lcur);
		while(1){
			if(c[lcur] <= c1[lcur]){
				// cout << lcur << " " << c[lcur] << " " << c1[lcur] << ln;
				i--;
				cur++;
				vec.clear();
				ans.pop_back();
				break;
			}
			ll l = a[2*lcur],r = a[2*lcur+1];
			vec.pb(mp(lcur,max(l,r)));
			if(l==0 && r==0){
				break;
			}
			else if(l>r) lcur = 2*lcur;
			else lcur = 2*lcur+1;
		}
		for(auto it : vec) {
			a[it.fi] = it.se;
			c[it.fi]--;
		}
		vec.clear();
	}
	ll tot = 0;
	forsn(i,1,(1<<g)){
		// cout << a[i] << ln;
		tot += a[i];
	}
	cout << tot << ln;
	for(auto it : ans) cout << it << " ";
	cout << ln;
}
 
int main()
{
	fast_cin();
    ll t=1;
    cin>>t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}