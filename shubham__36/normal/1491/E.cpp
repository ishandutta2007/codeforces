#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
// #include <atcoder/all>
// #include <bits/stdc++.h> 
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
// using namespace atcoder;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<p64,p64> pp64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef pair<ll,p64> tp;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln '\n'
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define zero ll(0)
#define set_bits(x) __builtin_popcountll(x)
// #define mint modint998244353
 
ll mpow(ll a, ll b){
	if(a==0) return 0;
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}
 
ll mpow(ll a, ll b, ll p){
	if(a==0) return 0;
	if(b==0) return 1;
	ll t1 = mpow(a,b/2,p);
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

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
 
ll range(ll l, ll r){
	return l + mt()%(r-l+1);
}
 
ll rev(ll v){
	return mpow(v,MOD-2);
}

ll nc2(ll n){
	return (n*(n-1))/2;
} 

vector<set<ll> > gr;
v64 fib;
v64 dp;

p64 dfs1(ll v, ll val1, ll val2, ll p=-1){
	// cout << " 1" << endl;
	dp[v]=1;
	p64 ans = mp(-1,-1);
	for(auto it : gr[v]){
		if(it != p) {
			p64 tmp = dfs1(it,val1,val2,v);
			if(tmp.fi != -1) ans = tmp;
			dp[v]+=dp[it];
		}
	}
	if(dp[v]==val1) return mp(p,v);
	if(dp[v]==val2) return mp(v,p);
	else return ans;
}

bool dfs(ll in, p64 ans){
	// cout << v << " " << in << endl;
	ll v = ans.fi;
	ll p = ans.se;
	if(v==-1) return false;
	if(in<2) return true;
	gr[v].erase(p);
	gr[p].erase(v);
	if(in-2 > 1){
		p64 cur = dfs1(v,fib[in-3],fib[in-4]);
		if(!dfs(in-2,cur)) {
			// cout <<  v << ln;
			return false;
		}
	}
	if(in-1 > 1){
		p64 cur = dfs1(p,fib[in-2],fib[in-3]);
		if(!dfs(in-1,cur)) {
			// cout << p << ln;
			return false;
		}
	}
	return true;
}

void solve(){
	ll n;
	cin >> n;
	if(n<4){
		cout << "YES" << ln;
		return;
	}
	gr.resize(n);
	dp.resize(n,1);
	fib.pb(1);
	fib.pb(1);
	ll cur = 1;
	while(fib[cur]<n){
		fib.pb(fib[cur]+fib[cur-1]);
		cur++;
	}
	if(fib.back()!=n){
		cout << "NO" << ln;
		return;
	}
	forn(i,n-1){
		ll a,b;
		cin >> a>> b;
		a--,b--;
		gr[a].insert(b);
		gr[b].insert(a);
	}
	p64 ans = dfs1(0,fib[cur-1],fib[cur-2]);
	// cout << ans.fi << " " << ans.se << ln;
	if(dfs(cur,ans)){
		cout << "YES" << ln;
	}
	else{
		cout << "NO" << ln;
	}
}

int main()
{
	fast_cin();
	ll t=1;
	// cin >> t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}