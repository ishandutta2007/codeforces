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
#define forsn(i,s,e) for(ll i = s; i < e; i++)
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
 
ll range(ll l, ll r){
	return l + rand()%(r-l+1);
}
 
ll rev(ll v){
	return mpow(v,MOD-2);
}

void solve1(){
	string s;
	cin >> s;
	ll n = sz(s);
	ll v[n+1];
	v[0]=-1;
	ll j = -1,i=0;
	while(i<n){
		while(j>=0 && s[j]!=s[i]) j=v[j];
		i++,j++;
		v[i]=j;
	}
	i=1,j=0;
	ll ans = 0;
	while(i<n-1){
		while(j>=0 && s[j]!=s[i]) j=v[j];
		j++,i++;
		ans = max(j,ans);
	}
	j=n;
	while(v[j]>ans) j = v[j];
	if(v[j]==0) cout << "Just a legend\n";
	else{
		forn(i,v[j]) cout << s[i];
		cout << ln;
	}
}

void solve(){
	ll n,k;
	cin >> n >> k;
	ll a[n-1];
	ll b[k-1];
	ll pr,t;
	cin >> pr;
	forn(i,n-1){
		cin >> t;
		a[i]=t-pr;
		pr = t;
	}
	cin >> pr;
	forn(i,k-1){
		cin >> t;
		b[i]=t-pr;
		pr = t;
	}
	if(k==1) cout << n << ln;
	else if(n<k) cout << 0 << ln;
	else{
		n--,k--;
		ll v[k+1];
		v[0]=-1;
		ll j = -1,i=0;
		while(i<k){
			while(j>=0 && b[j]!=b[i]) j=v[j];
			i++,j++;
			v[i]=j;
		}
		
		// forn(i,n) cout << a[i] << " ";
		// cout << ln;

		// forn(i,k) cout << b[i] << " ";
		// cout << ln;

		// forn(i,k+1) cout << v[i] << " ";
		// cout << ln;

		ll ans=0;
		j=0;
		forn(i,n){
			while(j>=0 && b[j]!=a[i]) j=v[j];
			j++;
			if(j==k) {
				ans++;
				j=v[j];
			}
		}
		cout << ans << ln;
	}
}
 
int main()
{
	fast_cin();
    ll t=1;
    // cin>>t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}