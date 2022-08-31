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

ll rev(ll v){
	return mpow(v,MOD-2);
}

ll n,L;
v64 a,b,last;

ll val(ll in){
	ll l=0,r=n;
	while(l!=r){
		ll mid = (l+r)/2;
		if(a[mid] < in) l = mid+1;
		else r = mid;
	}
	return l;
}

ll dist(ll i, ll j){
	return min(abs(a[i]-b[j]),L-abs(a[i]-b[j]));
}

bool check(ll v){
	last.clear();
	last.resize(n,-1);
	forn(i,n){
		ll ei=(b[i]+v+1)%L;
		last[i] = val(ei)%n;
	}
	// forn(i,n) cout << last[i] << " ";
	// cout << ln;
	ll si = (val((b[0]-v+L)%L))%n;
	ll val = (last[0]-si-1+n)%n;
	forn(i,n){
		while(dist(si,i)>v){
			if(val == 0) {
				// cout << i << ln;
				return 0;
			}
			si++;
			si %= n;
			val--; 
		}
		val = min(val,(last[i]-si-1+n)%n);
		si++;
		si %= n;
	}
	return 1;
}

void solve(){
    cin >> n >> L;
    a.resize(n);
    b.resize(n);
    forn(i,n) cin >> a[i];
    forn(i,n) cin >> b[i];
    sort(all(a));
    sort(all(b));
    // cout << check(27) << ln;
    ll l = 0, r = L/2;
    while(l!=r){
    	ll mid = (l+r)/2;
    	if(check(mid)) r=mid;
    	else l = mid+1;
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