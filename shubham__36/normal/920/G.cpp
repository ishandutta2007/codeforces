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

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

v64 vec;
vp64 factors;
const ll M = 1e6+5;
ll sieve[M];

void fill_sieve(){
	forsn(i,2,M){
		if(!sieve[i]){
			for(ll j = i; j<M; j+=i){
				if(!sieve[j]) sieve[j] = i; 
			}
		}
	}
}

void fun(ll val){
	if(val==1) return;
	while(val!=1){
		ll smf = sieve[val];
		while(!(val%smf)){
			val /= smf;
		}
		vec.pb(smf);
	}
	ll maxmask = (1<<((ll)vec.size()));
	forsn(i,1,maxmask){
		ll fact = 1;
		ll tot = 0;
		forn(j,(ll)vec.size()){
			if(i&(1<<j)){
				tot ++;
				fact *= vec[j];
			}
		}
		if(tot%2){
			factors.pb(mp(fact,1));
		}
		else{
			factors.pb(mp(fact,-1));
		}
	}
}

ll eval(ll val){
	if((ll)vec.size()==0) return val;
	ll ans = 0;
	forn(i,(ll)factors.size()){
		ans += (val/factors[i].fi)*factors[i].se;
	}
	return val-ans;
}

void solve(){
	ll x,p,k;
	cin >> x >> p >> k;
	fun(p);
	k += eval(x);
	ll l = 1,r = 1e18;
	while(l!=r){
		ll mid = (l+r)/2;
		if(eval(mid)>=k) r = mid;
		else l = mid+1;
	}
	cout << l << ln;
	vec.clear();
	factors.clear();
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill_sieve();
    ll t=1;
    cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}