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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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
		val.assign(sz << 1 , 0);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = val[ln] + val[rn];
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		if(l >= r) return 0;
		return cal(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
	}

};

segtree st;
vector<ll> v[26];
ll x[26] , vs[26];
string s , t;

void solve(){
	st.clear();
	for(ll i = 0 ; i < 26 ; i++){
		v[i].clear();
		x[i] = 0;
	}
	ll n;
	cin>>n>>s>>t;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		v[s[i] - 'a'].push_back(i);
	}
	for(ll i = 0 ; i < 26 ; i++){
		vs[i] = sze(v[i]);
	}
	ll ans = inf , cur = 0;
	for(ll i = 0 ; i < n ; i++){
		ll res = inf , c = t[i] - 'a';
		for(ll j = 0 ; j < c ; j++){
			if(x[j] == vs[j]) continue;
			ll k = v[j][x[j]];
			ll h = k + st.cal(k , n) - i;
			res = min(res , h);
		}
		ans = min(ans , res + cur);
		if(x[c] == vs[c]) break;
		ll k = v[c][x[c]++];
		ll h = k + st.cal(k , n) - i;
		cur += h;
		st.set(k , 1);
	}
	cout<<(ans == inf ? -1 : ans)<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}