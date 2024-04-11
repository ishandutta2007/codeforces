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
ll MOD = 1e9+7;
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

const ll MAX = 1e3+5;
set<ll> pr;

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	forn(i,n) cin >> a[i];
	ll ans = n;
	ll d = 10000000;
	v64 processed(n,0);
	forn(i,100){
		ll j = range(0,n-1);
		if(a[j]<MAX || processed[j]) {
			if(d){
				d--;
				i--;
				continue;
			}
			else{
				break;
			}
		}
		// cout << j << ln;
		processed[j] = 1;
		ll temp = a[j];
		forsn(i1,2,a[j]+1){
			if(i1*i1>a[j]) break;
			while(a[j]%i1 == 0) {
				a[j]/=i1;
				pr.insert(i1);
			}
		}
		if(a[j]!=1) pr.insert(a[j]);
		a[j]=temp+1;
		forsn(i1,2,a[j]+1){
			if(i1*i1>a[j]) break;
			while(a[j]%i1 == 0) {
				a[j]/=i1;
				pr.insert(i1);
			}
		}
		if(a[j]!=1) pr.insert(a[j]);
		if(temp>1){
			a[j]=temp-1;
			forsn(i1,2,a[j]+1){
				if(i1*i1>a[j]) break;
				while(a[j]%i1 == 0) {
					a[j]/=i1;
					pr.insert(i1);
				}
			}
			if(a[j]!=1) pr.insert(a[j]);
		}
		a[j]=temp;
	}
	v64 pr1;
	for(auto it : pr) pr1.pb(it);
	for(auto it : pr1){
		ll cans = 0;
		forn(j,n){
			ll fact = a[j]/it;
			if(fact) cans += min(a[j]-fact*it,(fact+1)*it-a[j]);
			else cans += (fact+1)*it-a[j];
		}
		// if(cans == 3) cout << it << ln;
		ans = min(ans,cans);
	}
	cout << ans << ln;
}
 
int main()
{
	v64 val(MAX,0);
	forsn(i,2,MAX){
		if(val[i]==0) pr.insert(i);
		for(ll j = i*i; j<MAX; j+=i) val[j]=1;
	}
	fast_cin();
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}