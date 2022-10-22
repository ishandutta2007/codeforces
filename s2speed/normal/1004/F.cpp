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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

ll x;

struct node {

	vector<pll> v , u;
	ll ans;

	void def(){
		ans = 0;
		v.push_back({0 , 0});
		u.push_back({0 , 0});
		return;
	}

	void set(ll y){
		v.clear(); u.clear();
		v.push_back({y , 1}); u.push_back({y , 1});
		ans = (y >= x);
		return;
	}

	friend node operator * (node a , node b){
		node res;
		ll cur , cnt , as = sze(a.v) , bs = sze(b.v);
		for(ll e = 0 ; e < as - 1 ; e++){
			res.v.push_back(a.v[e]);
		}
		cur = a.v[as - 1].first;
		cnt = a.v[as - 1].second;
		for(ll e = 0 ; e < bs ; e++){
			ll h = b.v[e].first | cur;
			if(h == cur){
				cnt += b.v[e].second;
				continue;
			}
			res.v.push_back({cur , cnt});
			cur = h;
			cnt = b.v[e].second;
		}
		res.v.push_back({cur , cnt});
		as = sze(a.u); bs = sze(b.u);
		for(ll e = 0 ; e < bs - 1 ; e++){
			res.u.push_back(b.u[e]);
		}
		cur = b.u[bs - 1].first;
		cnt = b.u[bs - 1].second;
		for(ll e = 0 ; e < as ; e++){
			ll h = a.u[e].first | cur;
			if(h == cur){
				cnt += a.u[e].second;
				continue;
			}
			res.u.push_back({cur , cnt});
			cur = h;
			cnt = a.u[e].second;
		}
		res.u.push_back({cur , cnt});
		res.ans = a.ans + b.ans;
		as = sze(a.u); bs = sze(b.v);
		ll h = 0 , y = bs - 1;
		for(ll i = 0 ; i < as ; i++){
			ll o = a.u[i].first;
			while(y != -1){
				pll p = b.v[y];
				if((p.first | o) < x) break;
				h += p.second;
				y--;
			}
			res.ans += 1ll * a.u[i].second * h;
		}
		return res;
	}

};

struct segtree {

	ll sz = 1;
	node def;
	vector<node> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		def.def();
		val.assign(sz << 1 , def);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x].set(k);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = val[ln] * val[rn];
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
		node a , b;
		a = cal(l , r , ln , lx , m); b = cal(l , r , rn , m , rx);
		return a * b;
	}

	ll cal(ll l , ll r){
		node res = cal(l , r , 0 , 0 , sz);
		return res.ans;
	}

};

segtree st;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q>>x;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		st.set(i , h);
	}
	for(ll i = 0 ; i < q ; i++){
		ll t;
		cin>>t; t--;
		if(t){
			ll l , r;
			cin>>l>>r; l--;
			cout<<st.cal(l , r)<<'\n';
		} else {
			ll j , h;
			cin>>j>>h; j--;
			st.set(j , h);
		}
	}
	return 0;
}

/*
4 1 7
0 3 6 1
2 1 4
*/