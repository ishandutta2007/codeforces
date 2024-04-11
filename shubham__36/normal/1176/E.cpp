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
#define INF LLONG_MAX/2e5

v64 vis,lev;
vv64 gr;

void dfs(ll v, ll l){
	// cout << v << ln;
	vis[v]=1;
	lev[v]=l;
	forn(i,(ll)gr[v].size()){
		if(vis[gr[v][i]]==0){
			dfs(gr[v][i],l+1);
		}
	}
}

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

void solve(ll in){
	ll n,m;
	cin >> n >> m;
	vis.clear();
	lev.clear();
	gr.clear();
	gr.resize(n+5);
	vis.resize(n+5,0);
	lev.resize(n+5,0);
	forn(i,m){
		ll t1,t2;
		cin >> t1 >> t2;
		gr[t1].pb(t2);
		gr[t2].pb(t1);	
	}
	// forsn(i,1,n+1){
	// 	cout << vis[i] << " ";
	// }
	// cout << ln;
	// forsn(i,1,n+1){
	// 	forn(j,(ll)gr[i].size()) cout << gr[i][j] << " ";
	// 	cout << ln;
	// }
	dfs(1,0);
	v64 v1,v2;
	forsn(i,1,n+1){
		if(lev[i]%2) v1.pb(i);
		else v2.pb(i);
	}
	if((ll)v1.size()>(ll)v2.size()){
		swap(v1,v2);
	}
	cout << (ll)v1.size() << ln;
	forn(i,(ll)v1.size()){
		cout << v1[i] << " ";
	}
	cout << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin >> t;
    forn(i,t) {
    	solve(i+1);
    }
    return 0;
}