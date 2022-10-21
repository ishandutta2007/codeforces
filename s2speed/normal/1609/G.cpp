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

struct node {

	ll ans , sum , len;

	void def(){
		sum = ans = len = 0;
		return;
	}

	void init(ll x){
		sum = ans = x;
		len = 1;
		return;
	}

	friend node operator + (node a , node b){
		node res;
		res.len = a.len + b.len;
		res.sum = a.sum + b.sum;
		res.ans = a.ans + b.ans + a.sum * b.len;
		return res;
	}

	friend void operator += (node &a , ll k){
		a.sum += k * a.len;
		a.ans += a.len * (a.len + 1) / 2 * k;
		return;
	}

};

struct segtree {

	ll sz = 1;
	vector<ll> laz , xal;
	vector<node> val;
	node def;

	void init(ll n){
		while(sz < n) sz <<= 1;
		def.def();
		val.assign(sz << 1 , def);
		laz.assign(sz << 1 , 0);
		xal.assign(sz << 1 , inf);
		return;
	}

	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < sze(a)){
				val[x].init(a[lx]);
				xal[x] = a[lx];
			}
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		build(a , ln , lx , m); build(a , rn , m , rx);
		val[x] = val[ln] + val[rn];
		xal[x] = max(xal[ln] , xal[rn]);
		return;
	}

	void build(vector<ll> &a){
		build(a , 0 , 0 , sz);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = 0;
		val[x] += h;
		xal[x] += h;
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
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
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		val[x] = val[ln] + val[rn];
		xal[x] = max(xal[ln] , xal[rn]);
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	node cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return def;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		node a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r , ll z){
		node h = cal(l , r , 0 , 0 , sz);
		ll res = h.ans + (z - h.len) * h.sum;
		return res;
	}

	ll get(ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(xal[x] <= k) return -1;
		if(rx - lx == 1) return lx;
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = get(k , ln , lx , m);
		if(a != -1) return a;
		return get(k , rn , m , rx);
	}

	ll get(ll k){
		return get(k , 0 , 0 , sz);
	}

};

ll n , m , q , w;
segtree st;
ll a[maxn] , b[maxn];
vector<ll> v , u;

ll hmmmm(){
	ll res = w * (n + m - 1);
//	cout<<res<<' ';
	ll x = 0;
	for(ll i = 0 ; i < n - 1 ; i++){
		ll j = st.get(u[i]) , z = n + m - 2 - x - i;
		res += st.cal(x , j , z);
		res += (n + m - 2 - (x = j) - i) * u[i];
//		cout<<res<<' ';
	}
	ll z = n + m - 2 - x - (n - 1);
//	cout<<'\n'<<x<<' '<<z<<'\n';
	res += st.cal(x , m - 1 , z);
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m>>q;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < m ; i++){
		cin>>b[i];
	}
	w = a[0] + b[0];
	for(ll i = 1 ; i < n ; i++){
		u.push_back(a[i] - a[i - 1]);
	}
	for(ll i = 1 ; i < m ; i++){
		v.push_back(b[i] - b[i - 1]);
	}
	st.init(m);
	st.build(v);
	for(ll e = 0 ; e < q ; e++){
		ll t , k , d;
		cin>>t>>k>>d;
		if(t == 1){
			ll lm = max(0ll , n - k - 1);
			for(ll i = n - 2 ; i >= lm ; i--){
				u[i] += d;
			}
			if(k == n) w += d;
		} else {
			ll lm = max(0ll , m - k - 1);
			st.add(lm , m - 1 , d);
			if(k == m) w += d;
		}
		cout<<hmmmm()<<'\n';
	}
	return 0;
}

/*
5 3 2
1 2 4 7 11
5 7 10
1 3 2
2 2 5
*/