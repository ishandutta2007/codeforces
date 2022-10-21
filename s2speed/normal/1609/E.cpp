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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

	ll a1 , a2 , a3 , a12 , a23 , a123;
	bool t;

	void init(ll x){
		a1 = a2 = a3 = a12 = a23 = a123 = 0;
		if(x == 0) a1 = 1;
		if(x == 1) a2 = 1;
		if(x == 2) a3 = 1;
		t = (x == -1);
		return;
	}

	friend node operator+ (node a , node b){
		node res;
		if(b.t) return a;
		if(a.t) return b;
		res.a1 = a.a1 + b.a1;
		res.a2 = a.a2 + b.a2;
		res.a3 = a.a3 + b.a3;
		res.a12 = min(a.a1 + b.a12 , a.a12 + b.a2);
		res.a23 = min(a.a2 + b.a23 , a.a23 + b.a3);
		res.a123 = min(min(a.a1 + b.a123 , a.a123 + b.a3) , a.a12 + b.a23);
		res.t = false;
		return res;
	}

};

struct segtree {

	ll sz = 1;
	node def;
	vector<node> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		def.init(-1);
		val.assign(sz << 1 , def);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x].init(k);
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

	node cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return def;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		node a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		node h = cal(l , r , 0 , 0 , sz);
		return h.a123;
	}

};

ll n , q;
string s;
segtree st;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>q>>s;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		st.set(i , s[i] - 'a');
	}
	for(ll e = 0 ; e < q ; e++){
		ll i;
		char c;
		cin>>i>>c; i--;
		st.set(i , c - 'a');
		cout<<st.cal(0 , n)<<'\n';
	}
	return 0;
}