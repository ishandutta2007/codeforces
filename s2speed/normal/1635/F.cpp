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

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 4e18;

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
		val.assign(sz << 1 , inf);
		return;
	}

	void add(ll l , ll r , ll k , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			val[x] = min(val[x] , k);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll i , ll x , ll lx , ll rx){
		if(rx - lx == 1) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a;
		if(i < m){
			a = cal(i , ln , lx , m);
		} else {
			a = cal(i , rn , m , rx);
		}
		return min(val[x] , a);
	}

	ll cal(ll i){
		return cal(i , 0 , 0 , sz);
	}

};

segtree st;
ll x[maxn] , a[maxn] , ans[maxn] , l[maxn] , r[maxn];
vector<ll> v , upd[maxn];
vector<pll> qu[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		cin>>x[i]>>a[i];
	}
	for(ll i = 0 ; i < q ; i++){
		ll l , r;
		cin>>l>>r; l--; r--;
		qu[r].push_back({l , i});
	}
	for(ll i = 0 ; i < n ; i++){
		ll h = -1;
		while(!v.empty()){
			ll j = v.back();
			if(a[j] <= a[i]){
				h = j;
				break;
			}
			v.pop_back();
		}
		l[i] = h;
		v.push_back(i);
	}
	v.clear();
	for(ll i = n - 1 ; ~i ; i--){
		ll h = -1;
		while(!v.empty()){
			ll j = v.back();
			if(a[j] <= a[i]){
				h = j;
				break;
			}
			v.pop_back();
		}
		r[i] = h;
		v.push_back(i);
	}
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		if(l[i] != -1){
			ll h = (x[i] - x[l[i]]) * (a[i] + a[l[i]]);
			st.add(0 , l[i] + 1 , h);
		}
		for(auto j : upd[i]){
			ll h = (x[i] - x[j]) * (a[i] + a[j]);
			st.add(0 , j + 1 , h);
		}
		for(auto p : qu[i]){
			ll l = p.first , j = p.second;
			ans[j] = st.cal(l);
		}
		if(r[i] != -1){
			upd[r[i]].push_back(i);
		}
	}
	for(ll i = 0 ; i < q ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}