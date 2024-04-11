#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

struct segtree {

	ll sz = 1;
	vector<ll> nal , xal;

	void init(ll n){
		while(sz < n) sz <<= 1;
		nal.assign(sz << 1 , inf);
		xal.assign(sz << 1 , -inf);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			nal[x] = xal[x] = k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		nal[x] = min(nal[ln] , nal[rn]);
		xal[x] = max(xal[ln] , xal[rn]);
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	pll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return {inf , -inf};
		if(rx <= r && lx >= l) return {nal[x] , xal[x]};
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		pll a , b , c;
		a = cal(l , r , ln , lx , m); b = cal(l , r , rn , m , rx);
		c.first = min(a.first , b.first); c.second = max(a.second , b.second);
		return c;
	}

	ll cal(ll l , ll r){
		pll p = cal(l , r , 0 , 0 , sz);
		return p.second - p.first;
	}

};

segtree st[20];
ll h[5];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k , lm , q;
	cin>>n>>k; lm = 1 << (k - 1);
	for(ll i = 0 ; i < lm ; i++){
		st[i].init(n);
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < k ; j++){
			cin>>h[j];
		}
		for(ll mask = 0 ; mask < lm ; mask++){
			ll o = 0;
			for(ll j = 0 ; j < k ; j++){
				if(mask & (1 << j)){
					o -= h[j];
				} else {
					o += h[j];
				}
			}
			st[mask].set(i , o);
		}
	}
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll t;
		cin>>t; t--;
		if(t){
			ll l , r , ans = 0;
			cin>>l>>r; l--;
			for(ll mask = 0 ; mask < lm ; mask++){
				ans = max(ans , st[mask].cal(l , r));
			}
			cout<<ans<<'\n';
			continue;
		}
		ll i;
		cin>>i; i--;
		for(ll j = 0 ; j < k ; j++){
			cin>>h[j];
		}
		for(ll mask = 0 ; mask < lm ; mask++){
			ll o = 0;
			for(ll j = 0 ; j < k ; j++){
				if(mask & (1 << j)){
					o -= h[j];
				} else {
					o += h[j];
				}
			}
			st[mask].set(i , o);
		}
	}
	return 0;
}