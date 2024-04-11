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
ll MOD = 1000000007;
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

ll n,tot;
vector<bool> vis;
v64 ord,p,ans;

void dfs(ll v, ll val){
	vis[v]=1;
	ans[v]=val;
	if(val==1 && !vis[p[v]]) dfs(p[v],2);
	if(val==2 && !vis[(v^1)%tot]) dfs((v^1)%tot,1);
}

void solve(ll index){
	cin >> n;
	tot = 2*n;
	vis.resize(tot,0);
	p.resize(tot);
	ans.resize(tot);
	forn(i,n){
		ll t1,t2;
		cin >> t1 >> t2;
		t1--,t2--;
		ord.pb(t1);
		ord.pb(t2);
		p[t1]=t2;
		p[t2]=t1;
	}
	forn(i,tot){
		if(!vis[i]) dfs(i,1);
	}
	// forn(i,tot) cout << ans[i] << " ";
	// cout << ln;
	forn(i,n){
		cout << ans[ord[2*i]] << " " << ans[ord[2*i+1]] << ln;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) solve(i+1);
    return 0;
}