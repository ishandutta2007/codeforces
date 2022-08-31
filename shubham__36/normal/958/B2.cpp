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
ll MOD = 1e13+7;
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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
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

vv64 gr;
v64 dep;
multiset<ll> s;

void dfs(ll v, ll p, ll val){
	dep[v]=val;
	forn(i,(ll)gr[v].size()){
		if(gr[v][i]!=p) dfs(gr[v][i],v,val+1);
	}
}

ll dfs1(ll v, ll p){
	ll mmax=0;
	forn(i,(ll)gr[v].size()){
		if(gr[v][i]!=p) mmax = max(mmax,dfs1(gr[v][i],v));
	}
	s.erase(s.find(mmax));
	mmax++;
	s.insert(mmax);
	return mmax;
}

void solve(){
	ll n;
	cin >> n;
	if(n==1){
		cout << 1 << ln;
		return;
	}
	gr.resize(n);
	dep.resize(n,0);
	v64 a(n,0);
	forn(i,n-1){
		ll t1,t2;
		cin >> t1 >> t2;
		t1--,t2--;
		gr[t1].pb(t2);
		gr[t2].pb(t1);
	}
	dfs(0,-1,0);
	ll v = -1,val=0;
	forn(i,n) if(dep[i]>val){
		v = i;
		val = dep[i];
	}
	forn(i,n) s.insert(0);;
	dfs1(v,-1);
	ll tot = 0;
	for(auto it : s){
		tot += it;
	}
	v64 v1;
	for(auto it : s){
		tot -= it;
		v1.pb(tot);
	}
	rforn(i,n-1) cout << ((i==n-1) ? 1 : v1[i]) << " ";
	cout << ln;
}


int main()
{
	fast_cin();
    ll t=1;
    forn(i,t) {
    	solve();
    }
    return 0;
}