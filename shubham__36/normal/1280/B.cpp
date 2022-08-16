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

void solve(){
	ll r,c;
	cin >> r >> c;
	char ch[r][c];
	forn(i,r) forn(j,c) cin >> ch[i][j];
	ll n=0;
	forn(i,r) forn(j,c) if(ch[i][j]=='A') n++;
	bool b1=0,b2=0,b3=0;
	forn(i,r){
		ll t = 0;
		forn(j,c) if(ch[i][j]=='A') t++;
		if(t==c){
			b2 = 1;
			if(i==0 || i==r-1) b1=1;
		}
		if((i==0 || i==r-1) && t) b3=1;
	}
	forn(i,c){
		ll t = 0;
		forn(j,r) if(ch[j][i]=='A') t++;
		if(t==r){
			b2 = 1;
			if(i==0 || i==c-1) b1=1;
		}
		if((i==0 || i==c-1) && t) b3=1;
	}
	if(ch[0][0]=='A' || ch[0][c-1]=='A' || ch[r-1][0]=='A' || ch[r-1][c-1]=='A') b2=1;
	if(n==r*c) cout << 0 << ln;
	else if(n==0) cout << "MORTAL" << ln;
	else if(b1) cout << 1 << ln;
	else if(b2) cout << 2 << ln;
	else if(b3) cout << 3 << ln; 
	else cout << 4 << ln;
}
 
int main()
{
    fast_cin();
    ll t=1;
    cin>>t;
    forn(i,t) {
        // cout << "Case #" << i+1 << ": " << ln;
        solve();
    }
    return 0;
}