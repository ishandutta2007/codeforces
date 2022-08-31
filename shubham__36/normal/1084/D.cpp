#include <bits/stdc++.h>
#include <set>
#include <list>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

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
typedef unordered_map<int,int> m32;
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
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
string s;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
	cin >> n;
	ll w[n],deg[n],vis[n],max1[n];
	vv64 add(n);
	m64 is_connected;
	m648 c;
	forn(i,n){
		cin >> w[i];
		deg[i]=0;
		vis[i]=0;
		max1[i]=0;
	}
	ll a,b,ci;
	forn(i,n-1){
		cin >> a >> b >> ci;--a;--b;
		deg[a]++;deg[b]++;
		c[a].insert(b);
		c[b].insert(a);
		is_connected[a*n+b]=ci;
		is_connected[b*n+a]=ci;
	}
	forn(j,n){
		ll i=j;
		while(deg[i]==1){
			ll sec = *(c[i].begin());
			ll temp=max((ll)0,w[i]+max1[i]-is_connected[i*n+sec]);
			add[sec].pb(temp);
			max1[sec]=max(max1[sec],temp);
			deg[sec]--;
			deg[i]--;
			c[sec].erase(i);
			if(deg[sec]!=1) break;
			i=sec; 
		}
	}
	forn(i,n){
		sort(add[i].begin(),add[i].end());
	}
	ll fans = 0;
	forn(i,n){
		ll id=0;
		if(add[i].size()>1) id = add[i][add[i].size()-2];
		fans = max(fans,w[i]+max1[i]+id);
	}
	cout << fans;
}