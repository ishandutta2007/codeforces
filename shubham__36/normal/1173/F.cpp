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

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

void solve(){
	ll n;
	cin >> n;
	ll p1[n],p2[n];
	ll a[n],b[n];
	forn(i,n) {
		ll t;
		cin >> t;
		t--;
		p1[i]=t;
		a[t]=i;
	}
	forn(i,n) {
		ll t;
		cin >> t;
		t--;
		p2[i]=t;
		b[t]=i;
	}
	vp64 v;
	v64 in;
	forn(i,n){
		ll r = a[i];
		ll c = b[i];
		if(r!=i || c!=i) {
			v.pb(mp(r,c));
			in.pb(i);
		}
		ll a1 = a[i], b1 = b[i];
		swap(a[i],a[p1[i]]);
		swap(b[i],b[p2[i]]);
		swap(p1[i],p1[a1]);
		swap(p2[i],p2[b1]);
	}
	cout << (ll)v.size() << ln;
	forn(i,(ll)v.size()){
		cout << v[i].fi+1 << " " << in[i]+1 << " " << in[i]+1 << " " << v[i].se+1 << ln;
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}