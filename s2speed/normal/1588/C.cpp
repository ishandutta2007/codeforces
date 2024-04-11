#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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
	vector<ll> val , cnt;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , inf);
		cnt.assign(sz << 1 , 0);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = k; cnt[x] = 1;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = min(val[ln] , val[rn]);
		cnt[x] = (val[x] == val[ln]) * cnt[ln] + (val[x] == val[rn]) * cnt[rn];
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll get(ll l , ll r , ll k , ll x , ll lx , ll rx){
		if(val[x] >= k) return inf;
		if(rx <= l || lx >= r) return inf;
		if(rx - lx == 1) return lx;
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = get(l , r , k , ln , lx , m);
		if(a != inf) return a;
		return get(l , r , k , rn , m , rx);
	}

	ll get(ll l , ll r , ll k){
		return get(l , r , k , 0 , 0 , sz);
	}

	ll cal(ll l , ll r , ll k , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return (val[x] == k) * cnt[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , k , ln , lx , m) , b = cal(l , r , k , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r , ll k){
		return cal(l , r , k , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
		cnt.clear();
	}

};

segtree st[2];
ll ps[maxn] , a[maxn];

void solve(){
	st[0].clear(); st[1].clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ps[0] = a[0];
	for(ll i = 1 ; i < n ; i++){
		ps[i] = a[i] - ps[i - 1];
	}
	st[0].init(n); st[1].init(n);
	for(ll i = 0 ; i < n ; i++){
		st[i & 1].set((i >> 1) , ps[i]);
	}
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		ll p = (i ? ps[i - 1] : 0) , pl = p * (1 - 2 * ((i - 1) & 1)) , pr = p * (1 - 2 * (i & 1)) , h;
		h = min(st[0].get((i + 1) / 2 , n , pl) * 2ll , st[1].get(i / 2 , n , pr) * 2ll + 1);
		if(h > n) h = n;
		ans += st[0].cal((i + 1) / 2 , (h + 1) / 2 , pl) + st[1].cal(i / 2 , h / 2 , pr);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}