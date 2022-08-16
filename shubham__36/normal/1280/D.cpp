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
ll MOD = 1e9+7;
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

vv64 gr;
v64 a;
ll n,m;
vvp64 dp;
p64 initial = mp((ll)0,-INF);

p64 add(p64 a, p64 b){
	return mp(a.fi+b.fi,a.se+b.se);
}

void dfs(ll v, ll p){
	dp[v][0]=mp(0,a[v]);
	forn(i1,sz(gr[v])){
		if(gr[v][i1] != p){
			dfs(gr[v][i1],v);
			vp64 temp(m,initial);
			forn(i,m){
				if(dp[v][i]==initial) break;
				forn(j,m){
					if(i+j >= m || dp[gr[v][i1]][j]==initial) break;
					temp[i+j] = max(temp[i+j],add(dp[v][i],dp[gr[v][i1]][j]));
				}
			}
			dp[v] = temp;
		}
	}
	rforn(i,m-1) if(dp[v][i]!=initial) dp[v][i+1] = max(dp[v][i+1],mp(dp[v][i].fi+(dp[v][i].se > 0),(ll)0));
}

void solve(){
	cin >> n >> m;
	gr.resize(n);
	a.resize(n,0);
	dp.resize(n,vp64(m+1,initial));
	forn(i,n){
		ll t;
		cin >> t;
		a[i]-=t;
	}
	forn(i,n){
		ll t;
		cin >> t;
		a[i]+=t;
	}
	forn(i,n-1){
		ll a,b;
		cin >>a >> b;
		a--,b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	dfs(0,-1);
	cout << dp[0][m].fi << ln;
	// forn(i,n){
	// 	forn(j,m+1) cout << dp[i][j].fi << " " << dp[i][j].se << "       ";
	// 	cout << ln;
	// }
	gr.clear();
	a.clear();
	dp.clear();
}
 
int main()
{
    fast_cin();
    ll t=1;
    cin>>t;
    forn(i,t) {
        // cout << "Case #" << i+1 << ": " << ln;
        solve();
    }
    return 0;
}