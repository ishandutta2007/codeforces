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

v64 a;
v64 pr;

ll msum(ll l, ll len){
	return pr[l+2*(len-1)] - ((l>1) ? pr[l-2] : 0);
}

ll f(ll st, ll sum, ll r){
	if(sum<0) return 0;
	ll l = 0;
	while(l<r){
		ll mid = (l+r+1)/2;
		if(msum(st,mid)<=sum) l=mid;
		else r = mid-1;
	}
	// cout << st << " " << sum << " " << r << ln;
	return l;
}

void solve(){
	ll n;
	cin >> n;
	a.resize(n);
	pr.resize(n);
	v64 pr1(n);
	ll sum = 0;
	forn(i,n){
		cin >> a[i];
		sum += a[i];
		pr[i] = (a[i] + ((i>1) ? pr[i-2] : 0));
		pr1[i] = (a[i] + (i ? pr1[i-1] : 0));
	}
	sum = (sum-1)/2;
	ll ans = 0;
	forn(i,n){
		ans += f(i,sum-(i ? pr1[i-1] : 0),(n-i)/2);
		ans += f(i,sum-(i ? pr1[i-1] : 0)-a[n-1],(n-i-1)/2);
		// cout << ans << ln;
		if(i){
			ans += f(i,sum-(i ? pr1[i-1] : 0)+a[0],(n-i)/2);
			ans += f(i,sum-(i ? pr1[i-1] : 0)-a[n-1]+a[0],(n-i-1)/2);
		}
		ans %= MOD;
		// cout << ans << ln;
	}
	ll csum = 0;
	rforn(i,n-1){
		if(csum<=sum) ans++;
		csum += a[i];
	}
	ans %= MOD;
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