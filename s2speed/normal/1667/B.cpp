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

const ll maxn = 5e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , -inf);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = max(val[x] , k);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return -inf;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return max(a , b);
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
	}

};

segtree st;
ll a[maxn] , dp[maxn] , ps[maxn] , h[maxn];
vector<ll> v;

void solve(){
	st.clear(); v.clear();
	ll n;
	cin>>n;
	ps[0] = 0;
	v.push_back(0);
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		ps[i] = ps[i - 1] + a[i];
		v.push_back(ps[i]);
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	for(ll i = 0 ; i <= n ; i++){
		ps[i] = lower_bound(all(v) , ps[i]) - v.begin();
	}
	ll vs = sze(v);
	for(ll i = 0 ; i < vs ; i++) h[i] = -inf;
	st.init(vs);
	st.set(ps[0] , 0);
	dp[0] = 0;
	h[ps[0]] = 0;
	for(ll i = 1 ; i <= n ; i++){
		dp[i] = max(dp[i - 1] - 1 , h[ps[i]]);
		dp[i] = max(dp[i] , st.cal(0 , ps[i]) + i);
		st.set(ps[i] , dp[i] - i);
		h[ps[i]] = max(h[ps[i]] , dp[i]);
	}
	cout<<dp[n]<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}