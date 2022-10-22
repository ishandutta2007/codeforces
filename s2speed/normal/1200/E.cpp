#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define size(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 1e6 + 16 , md = 2000000357 , inf = 2e18;
 
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
	vector<ll> val;
	vector<pll> laz;
	pll def = {1 , 0};

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		laz.assign(sz << 1 , def);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll z = laz[x].first , v = laz[x].second;
		laz[x] = def;
		if(rx - lx == 1){
			val[x] *= z; val[x] %= md;
			val[x] += v; if(val[x] >= md) val[x] -= md;
			return;
		}
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln].first *= z; laz[ln].first %= md;
		laz[ln].second *= z; laz[ln].second %= md;
		laz[ln].second += v; if(laz[ln].second >= md) laz[ln].second -= md;
		laz[rn].first *= z; laz[rn].first %= md;
		laz[rn].second *= z; laz[rn].second %= md;
		laz[rn].second += v; if(laz[rn].second >= md) laz[rn].second -= md;
		return;
	}	

	void add(ll l , ll r , ll z , ll v , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = {z , v};
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) / 2 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , z , v , ln , lx , m); add(l , r , z , v , rn , m , rx);
		return;
	}

	void add(ll l , ll r , ll z , ll v){
		add(l , r , z , v , 0 , 0 , sz);
		return;
	}

	ll cal(ll i , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx - lx == 1){
			return val[x];
		}
		ll m = (rx + lx) / 2 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			return cal(i , ln , lx , m);
		}
		return cal(i , rn , m , rx);
	}

	ll cal(ll i){
		return cal(i , 0 , 0 , sz);
	}

};

segtree st;
ll ph[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , P = 101 , l = 0;
	string s , h;
	cin>>n;
	st.init(1e6);
	for(ll i = 0 ; i < n ; i++){
		cin>>h;
		ll hs = size(h) , lm = max(0ll , l - hs) , ind = 0;
		ph[0] = h[0] - 40;
		for(ll j = 1 ; j < hs ; j++){
			ph[j] = 1ll * P * ph[j - 1] + h[j] - 40;
			ph[j] %= md;
		}
		for(ll j = l - 1 ; j >= lm ; j--){
			if(ph[l - j - 1] == st.cal(j)) ind = l - j;
		}
		for(ll j = ind ; j < hs ; j++){
			l++;
			s += h[j];
			st.add(0 , l , P , h[j] - 40);
		}
	}
	cout<<s<<'\n';
	return 0;
}