#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
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
ll MOD = 998244853;
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
	ll t1 = mpow(a,b/2);
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

v64 arr;
set<ll> s;
v64 a;
ll n,m,t;

ll f(ll d){
	ll t1=0;
	ll ans = 0;
	ll batchnum=0;
	ll tot=0;
	forn(i,n){
		if(arr[i]<=d){
			t1 += arr[i];
			batchnum++;
			tot += arr[i];
			if(t1>t){
				return ans;
			}
			ans++;
			if(batchnum==m){
				t1 += tot;
				batchnum=0;
				tot=0;
			}
			if(t1>t){
				return ans;
			}
		}
	}
	return ans;
}

void solve(){
	cin >> n >> m >> t;
	arr.resize(n);
	forn(i,n){
		cin >> arr[i];
		s.insert(arr[i]);
	}
	for(auto it:s) {
		if(it>t) break;
		a.pb(it);
	}
	ll l = 0;
	ll r = sz(a)-1;
	// cout << f(2) << " " << f(3) << " " << f(5) << " " << f(7) << ln;
	while(l<r){
		ll mid = (l+r+1)/2;
		ll val1 = f(a[mid]);
		ll val2 = f(a[mid-1]);
		if(val1>val2){
			l = mid;
		}
		else{
			r = mid-1;
		}
		// cout << l << " " << r << ln;
	}
	if(sz(a)==0) cout << 0 << " " << 1 << ln;
	else cout << f(a[l]) << " " << a[l] << ln;
	arr.clear();
	a.clear();
	s.clear();
}

int main()
{
	fast_cin();
    ll t=1;
	cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}