#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
ll MOD = 1e9+13;
double eps = 1e-12;
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
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
ll mpow(ll a, ll b){
	if(a==0) return 0;
	if(b >= (MOD-1)) b %= (MOD-1);
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

const ll p = 31;
v64 a = {11,13};

void solve(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll hash[n+1][2];
	hash[0][0]=0;
	hash[0][1]=0;
	ll p1[n+1],pp[n+1];
	p1[0]=0;
	pp[0]=1;
	forsn(i,1,n+1) pp[i]=(pp[i-1]*p)%MOD;
	forsn(i,1,n+1){
		forn(j,2) hash[i][j]=hash[i-1][j];
		p1[i]=p1[i-1];
		if(s[i-1]=='0'){
			p1[i]++;
			hash[i][0] = (p*hash[i][0]+(i%2 ? a[0] : a[1]))%MOD;
			hash[i][1] = (p*hash[i][1]+(i%2 ? a[1] : a[0]))%MOD;
		}
	}
	ll q;
	cin >> q;
	forn(i,q){
		ll a,b,l;
		cin >> a >> b >> l;
		a--,b--;
		ll val1 = (hash[a+l][a%2]-hash[a][a%2]*pp[p1[a+l]-p1[a]])%MOD;
		if(val1 < 0) val1 += MOD;
		ll val2 = (hash[b+l][b%2]-hash[b][b%2]*pp[p1[b+l]-p1[b]])%MOD;
		if(val2 < 0) val2 += MOD;
		if(val1 == val2) cout << "Yes" << ln;
		else cout << "No" << ln;
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