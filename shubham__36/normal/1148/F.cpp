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
	ll a[n][62];
	ll l[n];
	vv64 v(62);
	ll val[n];
	ll sum = 0;
	forn(i,n){
		ll t1;
		cin >> val[i] >> t1;
		sum += val[i];
		forn(j,62){
			if(((ll)1<<j) & t1){
				a[i][j]=1;
				l[i]=j;
			}
			else{
				a[i][j]=0;
			}
		}
	}
	forn(i,n){
		v[l[i]].pb(i);
	}
	ll ans=0;
	forn(i,62){
		ll tans = 0;
		forn(j,(ll)v[i].size()){
			tans += val[v[i][j]];
		}
		if((tans > 0 && sum>0) || (tans < 0 && sum<0)){
			ans+=((ll)1<<i);
			forn(j,n){
				if(a[j][i]==1){
					val[j]*=-1;
				}
			}
		}
	}
	cout << ans << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) solve();
    return 0;
}