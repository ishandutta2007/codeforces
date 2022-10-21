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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

	ll ans , pre , suf;
	bool all;

	void init(bool c){
		ans = pre = suf = all = c;
		return;
	}

	friend node operator+ (node a , node b){
		node res;
		res.pre = a.pre + b.pre * a.all;
		res.suf = b.suf + a.suf * b.all;
		res.ans = max(max(a.ans , b.ans) , a.suf + b.pre);
		res.all = a.all & b.all;
		return res;
	}

};

struct segtree {

	ll sz = 1 , cur;
	node def;
	vector<node> val;
	vector<ll> ln , rn , rt , ls;

	void build(ll n , ll x , ll lx , ll rx){
		ls[x] = x;
		if(rx - lx == 1){
			val[x].init(lx < n);
			return;
		}
		ll m = (rx + lx) >> 1; ln[x] = (x << 1) + 1; rn[x] = ln[x] + 1;
		build(n , ln[x] , lx , m); build(n , rn[x] , m , rx);
		val[x] = val[ln[x]] + val[rn[x]];
		return;
	}

	void build(ll n){
		build(n , 0 , 0 , sz);
		return;
	}

	void init(ll n){
		while(sz < n) sz <<= 1;
		cur = sz << 1;
		def.init(0); def.all = true;
		val.assign(sz << 1 , def);
		ln.resize(sz << 1); rn.resize(sz << 1);
		ls.resize(sz << 1);
		rt.push_back(0);
		build(n);
		return;
	}

	void set(ll i , bool c , ll x , ll lx , ll rx , ll bx){
		val.push_back(def); ln.push_back(-1); rn.push_back(-1); ls[bx] = x;
		if(rx - lx == 1){
			val[x].init(c);
			return;
		}
		ll m = (rx + lx) >> 1;
		if(i < m){
			ln[x] = cur++;
			rn[x] = ls[(bx + 1) << 1];
			set(i , c , ln[x] , lx , m , ln[bx]);
		} else {
			ln[x] = ls[(bx << 1) + 1];
			rn[x] = cur++;
			set(i , c , rn[x] , m , rx , rn[bx]);
		}
		val[x] = val[ln[x]] + val[rn[x]];
		return;
	}

	void set(ll i , bool c){
		rt.push_back(cur);
		set(i , c , cur++ , 0 , sz , 0);
		return;
	}

	node cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return def;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1;
		node a = cal(l , r , ln[x] , lx , m) , b = cal(l , r , rn[x] , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r , ll t){
		return cal(l , r , rt[t] , 0 , sz).ans;
	}

};

segtree st;
ll a[maxn];
vector<pll> v;

/*
9
1 9 2 8 3 7 4 6 5
1
1 9 6
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back({a[i] , i});
	}
	sort(all(v));
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		st.set(v[i].second , false);
	}
	ll q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll a , b , w;
		cin>>a>>b>>w; a--;
		ll l = 0 , r = n;
		while(l < r - 1){
			ll m = (r + l) >> 1;
			if(st.cal(a , b , m) >= w){
				l = m;
			} else {
				r = m;
			}
		}
		cout<<v[l].first<<'\n';
	}
	return 0;
}