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
	ll t1 = mpow(a,b/2);
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

vvp64 gr;
v64 vis;
vp64 vec;
v64 val1;
ll nnodes;

void add_edge(ll a, ll b, ll t1){
	ll pr = b;
	while(t1>9){
		nnodes++;
		vec.pb(mp(nnodes,pr));
		val1.pb(t1%10);
		t1/=10;
		pr = nnodes;
	}
	vec.pb(mp(a,pr));
	val1.pb(t1%10);
}

void solve(){
	ll n,m;
	cin >> n >> m;
	nnodes = n;
	forsn(i,1,m+1){
		ll a,b;
		cin >> a >> b;
		add_edge(a,b,i);
		add_edge(b,a,i);
	}
	gr.resize(nnodes+5);
	vis.resize(nnodes+5,0);
	forn(i,sz(vec)){
		gr[vec[i].fi].pb(mp(val1[i],vec[i].se));
	}
	forn(i,nnodes+5){
		sort(all(gr[i]));
	}
	ll dp[nnodes+5];
	dp[1]=0;
	vis[1]=1;
	queue<ll> q;
	q.push(1);
	ll pr = -1;
	vp64 vec;
	while(!q.empty() || sz(vec)){
		if(q.empty()){
			sort(all(vec));
			forn(i,sz(vec)) {
				if(vis[vec[i].se]==0){
					q.push(vec[i].se);
					vis[vec[i].se]=1;
					dp[vec[i].se] = vec[i].fi;
				}
			}
			vec.clear();
		}
		ll v = q.front();
		q.pop();
		if(pr != dp[v]){
			sort(all(vec));
			forn(i,sz(vec)) {
				if(vis[vec[i].se]==0){
					q.push(vec[i].se);
					vis[vec[i].se]=1;
					dp[vec[i].se] = vec[i].fi;
				}
			}
			vec.clear();
			pr = dp[v];
		}
		forn(i,sz(gr[v])){
			if(vis[gr[v][i].se]==0){
				ll val = (dp[v]*10+gr[v][i].fi)%MOD;
				vec.pb(mp(val,gr[v][i].se));
			}
		}
	}
	forsn(i,2,n+1){
		cout << dp[i] << ln;
	}
}
 
int main()
{
	fast_cin();
    ll t=1;
	// cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}