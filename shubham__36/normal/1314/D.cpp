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
 
typedef int ll;
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
ll MOD = 1e9+7;
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
#define INF 2e9
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
	ll n,k1;
	cin >> n >> k1;
	k1 /= 2;
	ll dist[n][n];
	vp64 distt[n][n];
	forn(i,n) forn(j,n) {
		cin >> dist[i][j];
	}
	forn(i,n){
		forn(j,n){
			forn(k,n){
				if(i!=k && j!=k) distt[i][j].pb(mp(dist[i][k]+dist[k][j],k));
			}
			sort(all(distt[i][j]));
		}
	}
	// cout << "entered" << ln;
	ll ans = INF;
	v64 p(k1+1,0);
	v64 pr(n,0);
	pr[0]=k1+1;
	ll val = 1;
	forn(i,k1-1) val*=n;
	forn(i1,val){
		// cout << i1 << ln;
		ll cans = 0;
		bool bo = 0;
		forn(i,k1){
			bo = 1;
			for(auto it : distt[p[i]][p[i+1]]){
				if(!pr[it.se]){
					cans += it.fi;
					bo=0;
					break;
				}
			}
			if(bo) break; 
		}
		if(!bo) ans = min(ans,cans); 
		forsn(i,1,k1){
			if(p[i]!=n-1){
				pr[p[i]]--;
				p[i]++;
				pr[p[i]]++;
				break;
			}
			else{
				pr[p[i]]--;
				p[i]=0;
				pr[p[i]]++;
			}
		}
	}
	cout << ans << ln;
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