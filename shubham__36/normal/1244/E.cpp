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

ll n,k;
v64 a;
set<pair<ll,p64> > s;
ll tot = 0;

p64 sum(ll v){
	auto it = s.upper_bound(mp(v,mp(-INF,-INF)));
	if(it == s.begin()) return mp(0,0);
	it--;
	return it->se;
}

bool check(ll v){
	forn(i,n){
		p64 s1 = sum(a[i]);
		p64 s2 = sum(a[i]+v);
		p64 s3 = sum(a[i]-v);
		ll t1 = tot - s2.fi - (n-s2.se)*(a[i]+v);
		ll t2 = s1.se*a[i] - s1.fi;
		ll req1 = t1+t2;
		t1 = tot - s1.fi - (n-s1.se)*(a[i]);
		t2 = s3.se*(a[i]-v) - s3.fi;
		ll req2 = t1+t2;
		// cout << s1 << " " << s2 << " " << s3 << ln;
		// cout << req1 << " " << req2 <<ln;
		if(req1<=k || req2 <=k) return 1;
	}
	return 0;
}

void solve(){
	cin >> n >> k;
	a.resize(n);
	forn(i,n) cin >> a[i];
	sort(all(a));
	forn(i,n){
		tot += a[i];
		s.insert(mp(a[i],mp(tot,i+1)));
	}
	// check(0);
	// return;
	ll l = 0,r=1e9;
	while(l!=r){
		ll mid = (l+r)/2;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	cout << l << ln;
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