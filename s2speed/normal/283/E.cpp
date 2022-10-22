#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 2e9;

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
	vector<ll> val , laz;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(2 * sz , 0);
		laz.assign(2 * sz , 0);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		if(!laz[x]) return;
		laz[x] = 0;
		val[x] = rx - lx - val[x];
		if(rx - lx == 1) return;
		ll ln = 2 * x + 1 , rn = ln + 1;
		laz[ln] ^= 1;
		laz[rn] ^= 1;
		return;
	}

	void swap(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = 1;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		swap(l , r , ln , lx , m); swap(l , r , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void swap(ll l , ll r){
		if(r <= l) return;
		swap(l , r , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		ll a , b;
		a = cal(l , r , ln , lx , m); b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		if(r <= l) return 0;
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
vector<ll> v;
vector<pll> qe , eq;

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n , k , h , ans = 0;
	cin>>n>>k; ans = 1ll * n * (n - 1) * (n - 2) / 6;
	for(ll i = 0 ; i < n ; i++){
		cin>>h;
		v.push_back(h);
	}
	sort(all(v));
	for(ll i = 0 ; i < k ; i++){
		ll a , b , l , r;
		cin>>a>>b;
		l = lower_bound(all(v) , a) - v.begin();
		r = upper_bound(all(v) , b) - v.begin();
		qe.push_back({l , r});
		eq.push_back({r , l});
	}
	sort(all(eq)); sort(all(qe)); eq.push_back({inf , inf}); qe.push_back({inf , inf});
	st.init(n);
	ll x = 0 , y = 0;
	for(ll i = 0 ; i < n ; i++){
		while(qe[x].first == i){
			st.swap(qe[x].first , qe[x].second);
			x++;
		}
		while(eq[y].first == i){
			st.swap(eq[y].second , eq[y].first);
			y++;
		}
		ll d = i;
		d -= st.cal(0 , i);
		d += st.cal(i + 1 , n);
		ans -= 1ll * d * (d - 1) / 2;
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/