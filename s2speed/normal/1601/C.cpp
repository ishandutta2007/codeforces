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

struct fentree {

	ll sz;
	vector<ll> val;

	void init(ll n){
		sz = n;
		val.assign(sz , 0);
		return;
	}

	void add(ll i){
		ll h = i;
		while(h < sz){
			val[h]++;
			h |= (h + 1);
		}
		return;
	}

	ll cal(ll i){
		ll res = 0 , h = i;
		while(h > -1){
			res += val[h];
			h &= (h + 1); h--;
		}
		return res;
	}

	void clear(){
		val.clear();
		return;
	}

};

struct node {

	ll sum , ans , ind;

	void def(){
		sum = ans = ind = -1;
		return;
	}

	friend node operator+(node a , node b){
		node res;
		res.sum = a.sum + b.sum;
		if(a.ans >= b.ans + a.sum){
			res.ans = a.ans;
			res.ind = a.ind;
		} else {
			res.ans = a.sum + b.ans;
			res.ind = b.ind;
		}
		return res;
	}

};

struct segtree {

	ll sz = 1;
	vector<node> val;
	node def;

	void build(ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x].ind = lx;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		build(ln , lx , m); build(rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void build(){
		build(0 , 0 , sz);
		return;
	}

	void init(ll n){
		while(sz < n) sz <<= 1;
		def.def();
		val.assign(sz << 1 , def);
		build();
		return;
	}

	void add(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x].sum = val[x].ans = val[x].sum + k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			add(i , k , ln , lx , m);
		} else {
			add(i , k , rn , m , rx);
		}
		val[x] = val[ln] + val[rn];
		return;
	}

	void add(ll i , ll k){
		add(i , k , 0 , 0 , sz);
		return;
	}

	void clear(){
		sz = 1;
		val.clear();
		return;
	}

};

fentree ft;
segtree st;
ll a[maxn] , b[maxn] , ap[maxn];
vector<ll> v , u;
vector<pll> t;

void solve(){
	ft.clear(); st.clear(); v.clear(); u.clear(); t.clear();
	ll n , m , ans = 0;
	cin>>n>>m;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		v.push_back(a[i]);
		t.push_back({a[i] , i});
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	ft.init(sze(v));
	for(ll i = 1 ; i <= n ; i++){
		ap[i] = lower_bound(all(v) , a[i]) - v.begin();
		ft.add(ap[i]);
		ans += i - ft.cal(ap[i]);
	}
	for(ll i = 0 ; i < m ; i++){
		cin>>b[i];
		u.push_back(b[i]);
	}
	sort(all(u));
	sort(all(t)); t.push_back({inf , -1});
	ll x = 0;
	st.init(n + 1); st.add(0 , 1);
	ll ps = -1 , pi = -1 , ls = 0;
	for(ll i = 0 ; i < m ; i++){
		if(i){
			if(u[i] == u[i - 1]){
				ans += ls;
				st.add(pi , 1);
				continue;
			}
		}
		while(t[x].first < u[i]){
			st.add(t[x++].second , 2);
		}
		ll y = x;
		while(t[y].first == u[i]){
			st.add(t[y++].second , 1);
		}
		ps = st.val[0].ans; pi = st.val[0].ind; ls = x + i - ps;
		ans += x + i - ps; st.add(pi , 1);
		while(t[x].first == u[i]){
			st.add(t[x++].second , 1);
		}
	}
	cout<<ans<<'\n';
	return;
}

/*
1
3 4
10 20 30
24 11 39 2
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}