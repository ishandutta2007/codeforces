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
ll n,ans=1;

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

ll dfs(ll v, ll p){
	ll fact = 1;
	ll noc = 0;
	ll dp = 1;
	forn(i,(ll)gr[v].size()){
		if(gr[v][i]!=p){
			noc++;
			fact *= noc;
			fact %= MOD;
			dp *= dfs(gr[v][i],v)+1;
			dp %= MOD;
		}
	}
	ans *= (fact*dp)%MOD;
	ans %= MOD;
	return noc;
}

void solve(){
	cin >> n;
	gr.resize(n);
	forn(i,n-1){
		ll t1,t2;
		cin >> t1 >> t2;
		t1--,t2--;
		gr[t1].pb(t2);
		gr[t2].pb(t1);
	}
	dfs(0,-1);
	cout << (n*ans)%MOD << ln;
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