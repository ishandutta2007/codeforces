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
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e18;

struct item {
	
	ll res = -inf , mx = -inf , mn = inf , lt = -inf , rt = -inf;

	friend item operator* (item a , item b){
		item res;
		res.mx = max(a.mx , b.mx); res.mn = min(a.mn , b.mn);
		res.lt = max(a.lt , b.lt); res.lt = max(res.lt , b.mx - 2ll * a.mn);
		res.rt = max(a.rt , b.rt); res.rt = max(res.rt , a.mx - 2ll * b.mn);
		res.res = max(max(a.res , b.res) , max(b.lt + a.mx , a.rt + b.mx));
		return res;
	}

	void init(ll x){
		mn = mx = x;
		res = 0;
		lt = rt = -x;
		return;
	}

};

struct segtree {

	ll sz = 1;
	item def;
	vector<item> val;
	vector<ll> laz;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.resize(2 * sz);
		laz.assign(2 * sz , 0);
		return;
	}

	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < a.size()){
				val[x].init(a[lx]);
			}
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		build(a , ln , lx , m); build(a , rn , m , rx);
		val[x] = val[ln] * val[rn];
		return;
	}

	void build(vector<ll> &a){
		build(a , 0 , 0 , sz);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = 0;
		if(h == 0) return;
		val[x].mn += h; val[x].mx += h;
		val[x].lt -= h; val[x].rt -= h;
		if(rx - lx == 1) return;
		ll ln = 2 * x + 1 , rn = ln + 1;
		laz[ln] += h; laz[rn] += h;
		return;
	}

	void add(ll l , ll r , ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = k;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		val[x] = val[ln] * val[rn];
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	item cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return def;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		item a , b;
		a = cal(l , r , ln , lx , m); b = cal(l , r , rn , m , rx);
		return a * b;
	}

	ll cal(ll l , ll r){
		item h = cal(l , r , 0 , 0 , sz);
		return h.res;
	}

};

segtree st;
vector<ll> a;
char c[maxn];

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n , q , dep = 0;
	cin>>n>>q;
	a.push_back(0);
	ll lm = (n - 1) << 1;
	for(ll i = 0 ; i < lm ; i++){
		cin>>c[i];
		if(c[i] == '('){
			dep++;
		} else {
			dep--;
		}
		a.push_back(dep);
	}
	st.init(2 * n - 1);
	st.build(a);
	cout<<st.cal(0 , 2 * n - 1)<<'\n';
	while(q--){
		ll a , b;
		cin>>a>>b; a--; b--;
		if(a > b) swap(a , b);
		if(c[a] == '('){
			st.add(a + 1 , b + 1 , -2);
		} else {
			st.add(a + 1 , b + 1 , 2);
		}
		swap(c[a] , c[b]);
		cout<<st.cal(0 , 2 * n - 1)<<'\n';
	}
	return 0;
}