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
#define ln '\n'
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define zero ll(0)
 
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

void solve(){
	ll n;
	cin >> n;
	ll p1=-1,p2=-1,p=-1,exp;
	ll n1 = n;
	for(ll i = 2; i*i <= n1; i++){
		if(n1%(i*i)==0){
			p = i;
			exp = 2;
			n/=i;
			n/=i;
			while(n%i==0){
				exp++;
				n/=i;
			}
			break;
		}
		if(n1%i == 0){
			if(p1==-1) p1=i;
			else if(p2==-1) p2=i;
			n1/=i;
		}
	}
	if(n1>1){
		if(p1==-1) p1=n1;
		else if(p2==-1) p2=n1;
	}
	if(p==-1){
		n/=p1;
		n/=p2;
		cout << p2 << " " << p1*p2 << " " << p1 << " ";
		for(ll i = 1; i*i <= n; i++){
			if(n%i==0){
				if(i!=1) cout << p1*i << " " << i << " " << p2*i << " " << p1*p2*i << " ";
				if(i*i!=n) cout << p1*(n/i) << " " << (n/i) << " " << p2*(n/i) << " " << p1*p2*(n/i) << " ";
			}
		}
		cout << ln;
		if(n==1) cout << 1 << ln;
		else cout << 0 << ln;
	}
	else{
		for(ll i = 1; i*i <= n; i++){
			if(n%i==0){
				cout << p*i << " ";
				if(i!=1) cout << i << " ";
				ll cur = p*p;
				forsn(j,2,exp+1) {
					cout << cur*i << " ";
					cur*=p;
				}
				if(i*i!=n){
					cout << p*(n/i) << " ";
					if((n/i)!=1) cout << (n/i) << " ";
					ll cur = p*p;
					forsn(j,2,exp+1) {
						cout << cur*(n/i) << " ";
						cur*=p;
					}
				}
			}
		}
		cout << ln;
		cout << 0 << ln;
	}
}
 
int main()
{
	fast_cin();
	ll t=1;
    cin >> t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}