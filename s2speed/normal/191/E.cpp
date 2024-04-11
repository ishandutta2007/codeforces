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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e14;

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

	ll sz = 1 , cur;
	vector<ll> val , ln , rn , ls , rt;

	void build(ll x , ll lx , ll rx){
		ls[x] = x;
		if(rx - lx == 1) return;
		ll m = (rx + lx) >> 1;
		ln[x] = (x << 1) + 1; rn[x] = ln[x] + 1;
		build(ln[x] , lx , m); build(rn[x] , m , rx);
		return;
	}

	void build(){
		build(0 , 0 , sz);
		return;
	}

	void init(ll n){
		while(sz < n) sz <<= 1;
		cur = sz << 1;
		val.assign(sz << 1 , 0);
		ln.resize(sz << 1);
		rn.resize(sz << 1);
		ls.resize(sz << 1);
		rt.push_back(0);
		build();
		return;
	}

	void add(ll i , ll x , ll lx , ll rx , ll bx){
		val.push_back(-1); ln.push_back(-1); rn.push_back(-1);
		ls[bx] = x;
		if(rx - lx == 1){
			val[x] = 1;
			return;
		}
		ll m = (rx + lx) >> 1;
		if(i < m){
			ln[x] = cur++;
			rn[x] = ls[rn[bx]];
			add(i , ln[x] , lx , m , ln[bx]);
		} else {
			ln[x] = ls[ln[bx]];
			rn[x] = cur++;
			add(i , rn[x] , m , rx , rn[bx]);
		}
		val[x] = val[ln[x]] + val[rn[x]];
		return;
	}

	void add(ll i){
		rt.push_back(cur);
		add(i , cur++ , 0 , sz , 0);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
//		cout<<x<<' '<<lx<<' '<<rx<<' '<<ln[x]<<' '<<rn[x]<<'\n';
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1;
		ll a = cal(l , r , ln[x] , lx , m) , b = cal(l , r , rn[x] , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r , ll t){
		return cal(l , r , rt[t] , 0 , sz);
	}

};

ll n , k;
segtree st;
ll a[maxn] , ps[maxn];
vector<pll> v;

bool check(ll x){
	ll cur = x , res = 0;
	for(ll i = 0 ; i < n ; i++){
		ll t = lower_bound(all(v) , mp(-cur , n)) - v.begin();
		res += st.cal(i , n , t);
	//	cout<<t<<' '<<cur<<' '<<res<<'\n';
		cur += a[i];
	}
	return (res < k);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ps[0] = a[0]; v.push_back({-a[0] , 0});
	for(ll i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + a[i];
		v.push_back({-ps[i] , i});
	}
	sort(all(v));
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		st.add(v[i].second);
	}
	ll l = -inf , r = inf;
	while(l < r - 1){
		ll m = (r + l) >> 1ll;
		if(check(m)){
			r = m;
		} else {
			l = m;
		}
	}
	cout<<l<<'\n';
	return 0;
}