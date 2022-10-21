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

	ll a , b;

	void init(ll x){
		a = x;
		b = 1;
		return;
	}

	friend node operator + (node a , node b){
		node res;
		if(a.b == 0){
			res = b;
			return res;
		}
		if(b.b == 0){
			res = a;
			return res;
		}
		if((a.a == b.a) ^ (a.b & 1)){
			res.a = a.a;
			res.b = a.b + b.b;
		} else {
			if(a.b >= b.b){
				res.a = a.a;
				res.b = a.b - b.b;
			} else {
				res.a = 1 ^ a.a;
				res.b = b.b - a.b;
			}
		}
		return res;
	}

};

struct segtree {

	ll sz = 1;
	vector<node> val;
	node def;

	void init(ll n){
		while(sz < n) sz <<= 1;
		def.a = def.b = 0;
		val.assign(sz << 1 , def);
		return;
	}

	void set(ll i , bool k , ll x , ll lx , ll rx){
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

	void set(ll i , bool k){
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
		return h.b >> 1;
	}

	void clear(){
		sz = 1;
		val.clear();
	}

};

segtree st;

void solve(){
	st.clear();
	ll n , q;
	string s;
	cin>>s>>q;
	n = sze(s);
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		char c = s[i];
		st.set(i , (c == '[') | (c == ']'));
	}
	for(ll e = 0 ; e < q ; e++){
		ll l , r;
		cin>>l>>r; l--;
		cout<<st.cal(l , r)<<'\n';
	}
	return;	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin>>T; 
	while(T--) solve();
	return 0;
}