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

vv64 gr;
v64 pa,dep,sz,lst,hv;
ll noq; 

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

void dfs(ll v, ll p, ll lev){
	pa[v]=p;
	ll m = -1;
	sz[v]=1;
	lst[v]=v;
	dep[v]=lev;
	forn(i,(ll)gr[v].size()){
		if(gr[v][i]!=p){
			dfs(gr[v][i],v,lev+1);
			sz[v] += sz[gr[v][i]];
			if(sz[gr[v][i]]>m){
				m = sz[gr[v][i]];
				hv[v] = gr[v][i];
				lst[v] = lst[gr[v][i]];
			}
		}
	}
}

ll d(ll v){
	noq++;
	if(noq==37) {
		exit(1);
	}
	cout << "d " << v << endl;
	ll ans;
	cin >> ans;
	if(ans == 0) {
		cout << "! " << v << endl;
		exit(0);
	}
	return ans;
}

ll s(ll v){
	noq++;
	if(noq==37) {
		exit(1);
	}
	cout << "s " << v << endl;
	ll ans;
	cin >> ans;
	return ans;
}


void solve(){
	ll n;
	cin >> n;
	gr.resize(n+5);
	pa.resize(n+5);
	dep.resize(n+5);
	sz.resize(n+5);
	lst.resize(n+5);
	hv.resize(n+5);
	forn(i,n-1){
		ll a1,a2;
		cin >> a1 >> a2;
		gr[a1].pb(a2);
		gr[a2].pb(a1);
	}
	dfs(1,-1,0);
	ll sz = d(1);
	ll u = 1;
	while(1){
		ll v = lst[u];
		ll a1 = dep[v] - dep[u];
		ll a2 = sz - dep[u];
		ll a3 = d(v);
		ll a4 = (a2+a3-a1)/2;
		ll a5 = a2-a4;
		forn(i,a5){
			u = hv[u];
		}
		if(dep[u]==sz){
			cout << "! " << u << endl;
			exit(0);
		}
		u = s(u);
		if(dep[u]==sz){
			cout << "! " << u << endl;
			exit(0);
		}
	}
}


int main()
{
	// ios_base::sync_with_stdio(0);
 //    cin.tie(0);
 //    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) solve();
    return 0;
}