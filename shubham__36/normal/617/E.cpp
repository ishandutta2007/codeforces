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
#define INF LLONG_MAX/2e5

const ll minput = 2e6+5;
ll c[minput];

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

void solve(ll in){
	ll n,m,k;
	cin >> n >> m >> k;
	ll a[n+1];
	ll temp = 0;
	a[0]=0;
	forn(i,n) {
		ll t1;
		cin >> t1;
		temp ^= t1;
		a[i+1]=temp;
	}
	// forn(i,n+1) cout << a[i] << " ";
	// cout << ln;
	ll b_size = sqrt(n);
	p64 q[m];
	ll ansarr[m];
	set<pair<p64,ll> > s;
	forn(i,m){
		ll t1,t2;
		cin >> t1 >> t2;
		q[i]=mp(t1-1,t2);
		s.insert(mp(mp(t1/b_size,t2),i));
	}
	ll sin=0,ein=0;
	ll ans=0;
	c[0]=1;
	for(auto it : s){
		ll index = it.se;
		if(ein<q[index].se){
			while(ein!=q[index].se){
				ein++;
				ans += c[a[ein]^k];
				c[a[ein]]++;
			}
		}
		else if(ein>q[index].se){
			while(ein!=q[index].se){
				c[a[ein]]--;
				ans -= c[a[ein]^k];
				ein--;
			}
		}
		if(sin<q[index].fi){
			while(sin!=q[index].fi){
				c[a[sin]]--;
				ans -= c[a[sin]^k];
				sin++;
			}
		}
		else if(sin>q[index].fi){
			while(sin!=q[index].fi){
				sin--;
				ans += c[a[sin]^k];
				c[a[sin]]++;
			}
		}
		ansarr[index]=ans;
	}
	forn(i,m) cout << ansarr[i] << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve(i+1);
    }
    return 0;
}