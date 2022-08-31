#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
// #include <atcoder/all>
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
ll MOD = 1e9+7;
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
#define INF 1e18
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

const ll N = 1e5+5;

void solve(){
	ll n;
	cin >> n;
	ll c[n];
	forn(i,n) cin >> c[i];
	ll b[n];
	b[n-1]=0;
	forn(i,n-1) cin >> b[i];
	rforn(i,n-2) b[i] += b[i+1];
	ll ux=INF,lx;
	ll sumb = 0, sumc = 0;
	forn(i,n) sumb += b[i];
	forn(i,n) sumc += c[i];
	lx = sumb/n;
	ux = (sumb+sumc)/n+1;
	ll q;
	cin >> q;
	v64 gdp(N,-1);
	ll nc = 0;
	v64 dp(1e6,0);
	v64 ndp(1e6,0);
	forn(i,q){
		ll x;
		cin >> x;
		x += b[0];
		if(x<lx) x = lx;
		else if(x>ux) x = ux;
		if(gdp[x]==-1){
			nc++;
			assert(nc < 200);
			// assert(mpv < 20000);
			ll nzl = 0, nzr = 0;
			dp[0]=1;
			rforn(i,n-1){
				// forn(k,mpv){
				// 	forsn(j,b[i],b[i]+c[i]+1){
				// 		ll nk = max(zero,k-(j-x));
				// 		if(nk <= mpv) ndp[nk] += dp[k];
				// 	}
				// }
				// forn(k,mpv){
				// 	dp[k] = ndp[k]%MOD;
				// }
				ll cnzl = INF, cnzr = 0;
				forsn(k,nzl,nzr+1){
					ll r = max(zero,k-(b[i]-x)), l = max(zero,k-(b[i]+c[i]-x));
					ndp[0] += (c[i]-(r-l))*dp[k];
					ndp[1] -= (c[i]-(r-l))*dp[k];
					ndp[l]+=dp[k];
					ndp[r+1]-=dp[k];
					cnzl = min(l,cnzl);
					cnzr = max(r+1,cnzr);
					dp[k] = 0;
				}

				forsn(k,cnzl,cnzr+1){
					if(k) {
						ndp[k] += ndp[k-1];
					}
					ndp[k] %= MOD;
					dp[k] = ndp[k];
				}
				forsn(k,cnzl,cnzr+1){
					ndp[k] = 0;
				}
				nzl = cnzl;
				nzr = cnzr-1;
			}
			gdp[x] = dp[0];
		}
		cout << (gdp[x]+MOD)%MOD << ln;
	}
}

int main()
{
	fast_cin();
	ll t=1;
	// cin >> t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}