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

ll n,m;
const ll N = 3e5 + 5;
ll a[2*N];
set<ll> in;
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

ll fun(ll val){
	ll ans = 1;
	while(val!=1){
		ll fact = 1;
		ll smf = sieve[val];
		while(!(val%smf)){
			fact++;
			val /= smf;
		}
		ans *= fact;
	}
	return ans;
}

ll query(ll l, ll r) {  // sum on interval [l, r)
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += a[l++];
    if (r&1) res += a[--r];
  }
  return res;
}

void update(ll index, ll value){
	ll temp = index+n;
	a[temp] = value;
	while(temp!=1){
		temp = (temp>>1);
		a[temp] = a[(temp<<1)] + a[(temp<<1)|1];
	} 
}

void solve(){
	fill_sieve();
	cin >> n >> m;
	forn(i,n){
		ll t1;
		cin >> t1;
		if(t1>2) in.insert(i);
		update(i,t1);
	}
	forn(i,m){
		ll qt,l,r;
		cin >> qt >> l >> r;
		l--,r--;
		if(qt==1){
			ll val = l;
			while(1){
				if(in.lower_bound(val)==in.end()) break;
				ll nin = *(in.lower_bound(val));
				if (nin>r) break;
				ll nval = fun(a[nin+n]);
				update(nin,nval);
				if(nval<=2) in.erase(nin);
				val = nin+1;
			}
		}
		else{
			cout << query(l,r+1) << ln;
		}
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