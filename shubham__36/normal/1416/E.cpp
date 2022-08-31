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

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	ll alpha = 0, sign = 1;
	set<ll> s;
	ll st = -1, en = -1;
	ll ans = 1;
	forn(i,n) {
		cin >> a[i];
	}
	if(a[0]%2){
		st = 1;
		en = a[0]-1;
		ans++;
	}
	else{
		st = a[0]/2;
		en = a[0]/2;
	}
	forsn(i,1,n){
		// cout << "range" << st << " " << en << " " << sz(s) << ln;
		ll alpha1 = a[i]-alpha;
		ll sign1 = -sign;
		if(a[i]%2){
			ans++;
			ll val = a[i]-alpha;
			// cout << val << " " << sign  << *(s.begin()) << ln;
				if(sign>0){
					auto it = s.lower_bound(val);
					while(it!=s.end()){
						s.erase(it);
						it = s.lower_bound(val);
					}
				}
				else{
					auto it = s.lower_bound(-val+1);
					while(it!=s.begin()){
						it--;
						s.erase(it);
						it = s.lower_bound(-val+1);
					}
				}
				// cout << sz(s) << ln;
				if(st >= a[i] && sz(s)==0){
					// cout << "entered " << st << " " << en << ln;
					ans++;
					st = 1, en = a[i]-1;
				}
				else if(st >= a[i]){
					ll val = alpha1 + sign1*(*(s.begin()));
					s.erase(s.begin());
					st = val, en = val;
				}
				else{
					ll t1 = a[i]-st, t2 = a[i]-en;
					st = max((ll)1,t2), en = max((ll)1,t1);
				}

		}
		else{
			ll mid = sign*(a[i]/2-alpha);
			if(s.find(mid)!=s.end() || (st <= a[i]/2 && en>=a[i]/2)){
				s.clear();
				st = a[i]/2;
				en = a[i]/2;
			}
			else{
				ans++;
				ll val = a[i]-alpha;
				if(sign>0){
					auto it = s.lower_bound(val);
					while(it!=s.end()){
						s.erase(it);
						it = s.lower_bound(val);
					}
				}
				else{
					auto it = s.lower_bound(-val+1);
					while(it!=s.begin()){
						it--;
						s.erase(it);
						it = s.lower_bound(-val+1);
					}
				}
				if(st >= a[i] && sz(s)==0){
					st = a[i]/2, en = a[i]/2;
				}
				else if(st >= a[i]){
					ll val = alpha1 + sign1*(*(s.begin()));
					s.erase(s.begin());
					st = val, en = val;
					s.insert(sign1*(a[i]/2-alpha1));
				}
				else{
					ll t1 = a[i]-st, t2 = a[i]-en;
					st = max((ll)1,t2), en = max((ll)1,t1);
					s.insert(mid);
				}
			}
		}
		alpha = a[i]-alpha;
		sign *= -1;
		// cout << i << " " << ans << ln;
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