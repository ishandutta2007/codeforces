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
double eps = 1e-6;
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
#define INF 5e18
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

v64 v[3];

ll val(ll v1, ll mi, ll ma){
	return (v1-mi)*(v1-mi)+(v1-ma)*(v1-ma);
}

ll f(ll in, ll mi, ll ma){
	// cout << in << " " << mi << " " << ma << ln;
	ll l = 0,r = sz(v[in]);
	// cout << l << " " << r << ln;
	ll mv = INF;
	while(l<r){
		ll mid1 = (2*l+r)/3,mid2=(l+2*r)/3;
		ll val1 = val(v[in][mid1],mi,ma);
		ll val2 = val(v[in][mid2],mi,ma);
		mv = min(mv,min(val1,val2));
		if(val1 < val2){
			r = mid2-1;
		}
		else{
			l = mid1+1;
		}
		// cout << mv << ln;
	}
	if(l<sz(v[in])) mv = min(mv,val(v[in][l],mi,ma));
	return mv;
}

void solve(){
	ll r,g,b;
	cin >> r >> g >> b;
	v[0].resize(r);
	v[1].resize(g);
	v[2].resize(b);
	forn(i,r) cin >> v[0][i];
	forn(i,g) cin >> v[1][i];
	forn(i,b) cin >> v[2][i];
	forn(i,3) sort(all(v[i]));
	forn(i,3) {
		v64::iterator ip = unique(all(v[i]));
		v[i].resize(distance(v[i].begin(),ip));
		// for(auto it : v[i]) cout << it << " ";
		// cout << ln;
	}
	ll ans= INF;
	while(sz(v[0]) && sz(v[1]) && sz(v[2])){
		ll ma=0,in1,mi=INF,in2;
		forn(i,3){
			if(v[i].back() > ma){
				ma = v[i].back();
				in1 = i;
			}
			if(v[i].back() < mi){
				mi = v[i].back();
				in2 = i;
			}
		}
		// cout << mi << " " << ma << ln;
		ll rem;
		if(in1!=in2) rem = f(3-in1-in2,mi,ma);
		else{
			cout << 0 << ln;
			return;
		}
		// cout << rem << ln;
		ans = min(ans,(ma-mi)*(ma-mi)+rem);
		v[in1].pop_back();
	}
	cout << ans << ln;
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