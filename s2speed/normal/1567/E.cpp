#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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

struct node {

	ll ans , pre , suf , fir , las , len;

	void init(ll x){
		ans = pre = suf = len = 1;
		fir = las = x;
		return;
	}

	void def(){
		ans = pre = suf = len = 0;
		fir = las = -inf;
		return;
	}

	friend node operator+ (node a , node b){
		node res;
		res.ans = a.ans + b.ans;
		if(a.las <= b.fir){
			res.ans += 1ll * a.suf * b.pre;
		}
		res.fir = a.fir; res.las = b.las;
		res.pre = a.pre;
		if(a.pre == a.len){
			if(a.las <= b.fir) res.pre += b.pre;
		}
		res.suf = b.suf;
		if(b.suf == b.len){
			if(a.las <= b.fir) res.suf += a.suf;
		}
		res.len = a.len + b.len;
		return res;
	}	

};

struct segtree {

	ll sz = 1;
	vector<node> val;
	node def;

	void init(ll n){
		while(sz < n) sz <<= 1;
		def.def();
		val.resize(sz << 1 , def);
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
		return h.ans;
	}

};

segtree st;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		st.set(i , h);
	}
	for(ll e = 0 ; e < q ; e++){
		ll t;
		cin>>t; t--;
		if(t){
			ll l , r;
			cin>>l>>r; l--;
			cout<<st.cal(l , r)<<'\n';
		} else {
			ll i , k;
			cin>>i>>k; i--;
			st.set(i , k);
		}
	}
	return 0;
}