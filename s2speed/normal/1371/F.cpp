#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

	ll anss , ansn;
	ll prefn , prefs , sufn , sufs;
	ll pref0 , pref1 , suf0 , suf1;

	void def(){
		anss = ansn = prefn = prefs = sufn = sufs = pref0 = pref1 = suf0 = suf1 = 0;
		return;
	}

	void init(bool c){
		anss = ansn = prefn = prefs = sufn = sufs = 1;
		if(c){
			pref0 = suf0 = 0;
			pref1 = suf1 = 1;
		} else {
			pref0 = suf0 = 1;
			pref1 = suf1 = 0;
		}
		return;
	}

	void swtch(){
		swap(anss , ansn);
		swap(prefn , prefs);
		swap(sufn , sufs);
		swap(pref0 , pref1);
		swap(suf0 , suf1);
		return;
	}

};

node merge(node a , node b , ll la , ll ra , ll lb , ll rb){
	node res;
	res.pref0 = a.pref0 + (a.pref0 == ra - la) * b.pref0;
	res.pref1 = a.pref1 + (a.pref1 == ra - la) * b.pref1;
	res.suf0 = b.suf0 + (b.suf0 == rb - lb) * a.suf0;
	res.suf1 = b.suf1 + (b.suf1 == rb - lb) * a.suf1;
	res.prefs = a.prefs;
	if(a.prefs == ra - la) res.prefs = a.prefs + b.pref1;
	if(a.pref0 == ra - la) res.prefs = a.pref0 + b.prefs;
	res.prefn = a.prefn;
	if(a.prefn == ra - la) res.prefn = a.prefn + b.pref0;
	if(a.pref1 == ra - la) res.prefn = a.pref1 + b.prefn;
	res.sufs = b.sufs;
	if(b.sufs == rb - lb) res.sufs = b.sufs + a.suf0;
	if(b.suf1 == rb - lb) res.sufs = b.sufs + a.sufs;
	res.sufn = b.sufn;
	if(b.sufn == rb - lb) res.sufn = b.sufn + a.suf1;
	if(b.suf0 == rb - lb) res.sufn = b.sufn + a.sufn;
	res.anss = max(max(a.anss , b.anss) , max(a.sufs + b.pref1 , b.prefs + a.suf0));
	res.ansn = max(max(a.ansn , b.ansn) , max(a.sufn + b.pref0 , b.prefn + a.suf1));
	return res;
}

struct segtree {

	ll sz = 1;
	vector<node> val;
	vector<ll> laz;
	node def;

	void init(ll n){
		while(sz < n) sz <<= 1;
		def.def();
		val.assign(sz << 1 , def);
		laz.assign(sz << 1 , 0);
		return;
	}

	void set(ll i , bool c , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x].init(c);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , c , ln , lx , m);
			val[x] = val[ln];
		} else {
			set(i , c , rn , m , rx);
			val[x] = merge(val[ln] , val[rn] , lx , m , m , i + 1);
		}
		return;
	}

	void set(ll i , bool c){
		set(i , c , 0 , 0 , sz);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		if(!laz[x]) return;
		laz[x] = 0;
		val[x].swtch();
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln] ^= 1;
		laz[rn] ^= 1;
		return;
	}

	void swtch(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = 1;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		swtch(l , r , ln , lx , m);
		swtch(l , r , rn , m , rx);
		val[x] = merge(val[ln] , val[rn] , lx , m , m , rx);
		return;
	}

	void swtch(ll l , ll r){
		swtch(l , r , 0 , 0 , sz);
		return;
	}

	node cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return def;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		node a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		if(a.anss == 0) return b;
		if(b.anss == 0) return a;
		return merge(a , b , max(l , lx) , m , m , min(r , rx));
	}

	node cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		char c;
		cin>>c;
		st.set(i , (c == '<'));
	}
	for(ll e = 0 ; e < q ; e++){
		ll l , r;
		cin>>l>>r; l--;
		st.swtch(l , r);
		node res = st.cal(l , r);
		cout<<res.anss<<'\n';
	}
	return 0;
}