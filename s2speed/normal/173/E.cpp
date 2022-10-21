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

const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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
	vector<ll> val , cnt;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , -1);
		cnt.assign(sz << 1 , 0);
		return;
	}

	void add(ll i , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			cnt[x]++;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			add(i , ln , lx , m);
		} else {
			add(i , rn , m , rx);
		}
		cnt[x] = cnt[ln] + cnt[rn];
		return;
	}

	void add(ll i){
		add(i , 0 , 0 , sz);
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

	ll get(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return cnt[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = get(l , r , ln , lx , m) , b = get(l , r , rn , m , rx);
		return a + b;
	}

	ll get(ll l , ll r){
		if(l >= r) return 0;
		return get(l , r , 0 , 0 , sz);
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return -1;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return max(a , b);
	}

	ll cal(ll l , ll r){
		if(l >= r) return -1;
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
ll a[maxn] , b[maxn] , c[maxn] , d[maxn] , f[maxn] , ans[maxn] , l[maxn] , r[maxn];
vector<ll> v , u[maxn] , t[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	for(ll i = 0 ; i < n ; i++){
		c[i] = lower_bound(all(v) , a[i]) - v.begin();
		u[c[i]].push_back(i);
	}
	v.clear();
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i];
		v.push_back(b[i]);
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	for(ll i = 0 ; i < n ; i++){
		d[i] = lower_bound(all(v) , b[i]) - v.begin();
	}
	st.init(n);
	for(ll j = 0 ; j < n ; j++){
		for(auto i : u[j]){
			st.add(d[i]);
		}
		for(auto i : u[j]){
			ll l = lower_bound(all(v) , b[i] - k) - v.begin() , r = upper_bound(all(v) , b[i] + k) - v.begin();
			f[i] = st.get(l , r);
		}
	}
//	for(ll i = 0 ; i < n ; i++){
//		cout<<c[i]<<' ';
//	}
//	cout<<'\n';
//	for(ll i = 0 ; i < n ; i++){
//		cout<<d[i]<<' ';
//	}
//	cout<<'\n';
//	for(ll i = 0 ; i < n ; i++){
//		cout<<f[i]<<' ';
//	}
//	cout<<'\n';
	ll q;
	cin>>q;
	for(ll i = 0 ; i < q ; i++){
		ll x , y;
		cin>>x>>y; x--; y--;
		if(c[x] < c[y]) swap(x , y);
		t[c[x]].push_back(i);
		if(b[x] < b[y]) swap(x , y);
		l[i] = lower_bound(all(v) , b[x] - k) - v.begin();
		r[i] = upper_bound(all(v) , b[y] + k) - v.begin();
	}
	for(ll j = n - 1 ; j >= 0 ; j--){
		for(auto i : u[j]){
			st.set(d[i] , f[i]);
		}
		for(auto i : t[j]){
			ans[i] = st.cal(l[i] , r[i]);
		}
	}
	for(ll i = 0 ; i < q ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}