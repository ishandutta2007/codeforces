#include <bits/stdc++.h>
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
v64 vis;
ll val;

void dfs(ll v){
	vis[v]=val;
	forn(i,(ll)gr[v].size()){
		if(vis[gr[v][i]]==0) dfs(gr[v][i]);
	}
}

void solve(){
	ll n,m;
	cin >> n >> m;
	gr.resize(n);
	vis.resize(n,0);
	forn(i,m){
		ll k;
		cin >> k;
		v64 temp;
		forn(i,k){
			ll t1;
			cin >> t1;
			temp.pb(t1-1);
			if(i!=0){
				gr[temp[i]].pb(temp[i-1]);
				gr[temp[i-1]].pb(temp[i]);
			}
		}
	}
	val=1;
	forn(i,n){
		if(vis[i]==0) dfs(i);
		val++;
	}
	ll c[n];
	forn(i,n) c[i]=0;
	forn(i,n){
		c[vis[i]-1]++;
	}
	forn(i,n){
		cout << c[vis[i]-1] << " ";
	}
	cout << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    forn(i,t) solve();
    return 0;
}