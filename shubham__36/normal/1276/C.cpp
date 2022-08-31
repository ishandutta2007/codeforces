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

ll n;
ll m,r,c;
vp64 vec;
v64 pr;

ll check(ll v){
	ll l1=0,r1=sz(vec);
	while(l1!=r1){
		ll mid = (l1+r1)/2;
		if(vec[mid].fi < v) l1=mid+1;
		else r1 = mid;
	}
	ll am = (sz(vec)-l1)*v+(l1 ? pr[l1-1] : 0);
	return am;
}

void solve(){
	cin >> n;
	map<ll,ll> m1;
	forn(i,n){
		ll t;
		cin >> t;
		m1[t]++;
	}
	for(auto it : m1){
		vec.pb(mp(it.se,it.fi));
	}
	sort(all(vec));
	ll pre = 0;
	forn(i,sz(vec)){
		pre += vec[i].fi;
		pr.pb(pre);
	}
	forsn(i,1,n+1){
		ll l=0,r1=i;
		while(l!=r1){
			ll mid = (l+r1+1)/2;
			if(check(mid)>=i*mid) l = mid;
			else r1 = mid-1;
		}
		if(i*l > m){
			m = i*l;
			r = i;
			c = l;
		}
	}
	forn(i,sz(vec)) vec[i]=mp(min(c,vec[i].fi),vec[i].se);
	cout << m << ln;
	cout << r << " " << c << ln;
	ll a[r][c];
	ll cr=0,cc=0;
	ll ci = sz(vec)-1;
	while(1){
		a[cr][cc] = vec[ci].se;
		vec[ci].fi--;
		if(vec[ci].fi==0) ci--;
		if(cc == c-1){
			cr = (cr-cc+1+r)%r;
			cc = 0;
		}
		else{
			cr++;
			cc++;
			cr %= r;
		}
		if(cc==0 && cr==0) break;
	}
	forn(i,r){
		forn(j,c) cout << a[i][j] << " ";
		cout << ln;
	}
}
 
int main()
{
    fast_cin();
    ll t=1;
    // cin>>t;
    forn(i,t) {
        // cout << "Case #" << i+1 << ": " << ln;
        solve();
    }
    return 0;
}