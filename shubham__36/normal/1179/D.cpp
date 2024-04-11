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
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF LLONG_MAX

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

ll n;
vv64 gr;
v64 dp,dp1,sz;

void dfs(ll v, ll p){
	map<ll,ll> m;
	v64 sizes;
	dp[v]=n*n;
	forn(i,(ll)gr[v].size()){
		if(gr[v][i]!=p){
			dfs(gr[v][i],v);
			sz[v]+=sz[gr[v][i]];
		}
	}
	dp1[v]=sz[v]*sz[v];
	forn(i,(ll)gr[v].size()){
		if(gr[v][i]!=p){
			dp1[v]=min(dp1[v],(sz[v]-sz[gr[v][i]])*(sz[v]-sz[gr[v][i]])+dp1[gr[v][i]]);
			dp[v]=min(dp[v],(n-sz[gr[v][i]])*(n-sz[gr[v][i]])+dp1[gr[v][i]]);
			if(m.find(sz[gr[v][i]])!=m.end()){
				dp[v]=min(dp[v],(n-2*sz[gr[v][i]])*(n-2*sz[gr[v][i]])+dp1[gr[v][i]]+m[sz[gr[v][i]]]);
			}
			if(m.find(sz[gr[v][i]])==m.end()) {
				m[sz[gr[v][i]]]=dp1[gr[v][i]];
				sizes.pb(sz[gr[v][i]]);
			}
			else m[sz[gr[v][i]]] = min(m[sz[gr[v][i]]],dp1[gr[v][i]]);
		}
	}
	forn(i,(ll)sizes.size()){
		forsn(j,i+1,(ll)sizes.size()) dp[v]=min(dp[v],(n-sizes[i]-sizes[j])*(n-sizes[i]-sizes[j])+m[sizes[i]]+m[sizes[j]]);
	}
}

void solve(){
	cin >> n;
	gr.resize(n+5);
	dp.resize(n+5,0);
	dp1.resize(n+5,0);
	sz.resize(n+5,1);
	forn(i,n-1){
		ll t1,t2;
		cin >> t1 >> t2;
		gr[t1].pb(t2);
		gr[t2].pb(t1);
	}
	ll ans = 2*n*n-n;
	dfs(1,-1);
	ll temp=INF;
	forsn(i,1,n+1) temp=min(temp,dp[i]);
	ans -= temp;
	cout << ans/2 << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}