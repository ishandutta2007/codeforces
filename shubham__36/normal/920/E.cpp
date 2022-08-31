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

v64 vec,sz,vis;
vv64 nvec;

ll find(ll node){
	if(vec[node]!=node) vec[node]=find(vec[node]);
	return vec[node];
}

void merge(ll node1, ll node2){
	node1 = find(node1);
	node2 = find(node2);
	if(node1==node2) return;
	if(sz[node1]>=sz[node2]){
		sz[node1]+=sz[node2];
		vec[node2]=node1;
		forn(j,(ll)nvec[node2].size()){
			nvec[node1].pb(nvec[node2][j]);
		}
	}
	else{
		sz[node2]+=sz[node1];
		vec[node1]=node2;
		forn(j,(ll)nvec[node1].size()){
			nvec[node2].pb(nvec[node1][j]);
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
	vec.resize(n+5);
	sz.resize(n+5,1);
	vis.resize(n+5,0);
	forn(i,n+5) vec[i]=i;
	map<p64,ll> mmap;
	forn(i,m){
		ll t1,t2;
		cin >> t1 >> t2;
		if(t1>t2) swap(t1,t2);
		mmap[mp(t1,t2)]=1;
	}
	set<ll> root;
	nvec.resize(n+5);
	forn(i,n+5) nvec[i].pb(i);
	forsn(i,1,n+1){
		for(auto j : root){
			forn(k,(ll)nvec[j].size()){
				if(mmap.find(mp(nvec[j][k],i))==mmap.end()){
					merge(i,j);
					break;
				}
			}
		}
		root.insert(vec[i]);
	}
	v64 fvec;
	forsn(i,1,n+1){
		ll temp = find(i);
		if(vis[temp]==0){
			fvec.pb(sz[temp]);
			vis[temp]=1;
		}
	}
	sort(fvec.begin(),fvec.end());
	cout << (ll)fvec.size() << ln;
	forn(i,(ll)fvec.size()){
		cout << fvec[i] << " ";
	} 
	cout << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve(i+1);
    }
    return 0;
}