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
ll MOD = 231548613323;
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
 
ll rev(ll v){
	return mpow(v,MOD-2);
}
 
ll f(ll val, v64 &v){
	ll l = 0,r=sz(v);
	while(l!=r){
		ll mid = (l+r)/2;
		if(v[mid]>val) r=mid;
		else l = mid+1; 
	}
	return l;
}

void solve(){
	ll x,y,a1,a2,b1,b2;
	cin >> x >> y >> a1 >> a2 >> b1 >> b2;
	ll xi,yi,t;
	cin >> xi >> yi >> t;
	vp64 v;
	while(x<=xi || y<=yi || abs(x-xi)+abs(y-yi) <= t){
		if(abs(x-xi)+abs(y-yi) <= t){
			v.pb(mp(x,y));
			// cout << x << " " << y << ln;
		}
		x = a1*x+b1;
		y = a2*y+b2;
	}
	if(sz(v)==0){
		cout << 0 << ln;
		return;
	}
	v64 pr(sz(v));
	pr[0]=0;
	forsn(i,1,sz(v)){
		pr[i]=pr[i-1]+abs(v[i].fi-v[i-1].fi)+abs(v[i].se-v[i-1].se);
	}
	ll ans = 0;
	forn(i,sz(v)){
		ll in1 = f(t-abs(xi-v[i].fi)-abs(yi-v[i].se)+pr[i],pr);
		ll in2 = f(pr[i]-(t-abs(xi-v[i].fi)-abs(yi-v[i].se)),pr);
		if(in2 && pr[in2-1] == pr[i]-(t-abs(xi-v[i].fi)-abs(yi-v[i].se))) in2--;
		ans = max(ans,in1-i);
		ans = max(ans,i-in2+1);
	}
	cout << ans << ln;
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