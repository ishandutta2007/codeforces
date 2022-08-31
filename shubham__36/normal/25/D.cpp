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
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
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

vv64 gr;
map<ll,ll> m;
v64 a;
v64 vis;
v64 ind;
ll fact = 1e4;

void dfs(ll v){
	vis[v]=1;
	forn(i,(ll)gr[v].size()){
		if(vis[gr[v][i]]==0) {
			dfs(gr[v][i]);
			ind[m[v*fact+gr[v][i]]]=1;
		}
	}
}

void solve(){
	ll n;
	cin >> n;
	gr.resize(n);
	vis.resize(n,0);
	ind.resize(n-1,0);
	a.resize(n-1);
	forn(i,n-1){
		ll t1,t2;
		cin >> t1 >> t2;
		t1--,t2--;
		gr[t1].pb(t2);
		gr[t2].pb(t1);
		a[i]=t1*fact+t2;
		m[a[i]]=i;
		m[t2*fact+t1]=i;
	}
	v64 v1;
	forn(i,n){
		if(vis[i]==0){
			dfs(i);
			v1.pb(i);
		}
	}
	v64 v2;
	forn(i,n-1){
		if(ind[i]==0) v2.pb(i);
	}
	cout << (ll)v2.size() << ln;
	forn(i,(ll)v2.size()){
		cout << a[v2[i]]/fact+1 << " " << a[v2[i]]%fact+1 << " " << v1[0]+1 << " " << v1[i+1]+1 << ln;
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) solve();
    return 0;
}