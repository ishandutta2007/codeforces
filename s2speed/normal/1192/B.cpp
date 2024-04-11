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

const ll maxn = 2e5 + 16 , md = 998244353 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll lcm(ll a , ll b){
	ll res = 1ll * a * b / gcd(a , b);
	return res;
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

	ll ans , pre , suf , mx , mn;

	void def(){
		ans = pre = suf = mx = mn = 0;
		return;
	}

	void init(ll x){
		ans = 0; pre = suf = -x; mx = mn = x;
		return;
	}

	friend node operator+ (node a , node b){
		node res;
		res.mx = max(a.mx , b.mx);
		res.mn = min(a.mn , b.mn);
		res.pre = max(max(a.pre , b.pre) , a.mx - 2ll * b.mn);
		res.suf = max(max(a.suf , b.suf) , b.mx - 2ll * a.mn);
		res.ans = max(max(a.ans , b.ans) , max(a.pre + b.mx , b.suf + a.mx));
		return res;
	}

};

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

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = 0;
		val[x].pre -= h; val[x].suf -= h;
		val[x].mx += h; val[x].mn += h;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		if(rx - lx == 1) return;
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
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(){
		return val[0].ans;
	}

};

segtree st;
ll bt[maxn] , ft[maxn] , cur = 0 , pr[maxn];
vector<ll> adj[maxn] , h;
vector<plll> ed;

void tDFS(ll r , ll par){
	pr[r] = par;
	bt[r] = cur++;
	h.push_back(r);
	for(auto i : adj[r]){
		if(i == par) continue;
		tDFS(i , r);
		cur++;
		h.push_back(r);
	}
	ft[r] = cur;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q , W;
	cin>>n>>q>>W;
	for(ll i = 1 ; i < n ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
		ed.push_back({{v , u} , w});
	}
	st.init(2 * n);
	tDFS(0 , -1);
	for(ll e = 0 ; e < n - 1 ; e++){
		plll q = ed[e];
		ll v = q.first.first , u = q.first.second , w = q.second;
		if(v == pr[u]){
			swap(v , u);
			swap(ed[e].first.first , ed[e].first.second);
		}
		st.add(bt[v] , ft[v] , w);
	}
	ll o = 0;
	for(ll e = 0 ; e < q ; e++){
		ll j , k;
		cin>>j>>k;
		j = (j + o) % (n - 1); k = (k + o) % W;
		ll w = ed[j].second , v = ed[j].first.first;
		st.add(bt[v] , ft[v] , k - w);
		ed[j].second = k;
		o = st.cal();
		cout<<o<<'\n';
	}
	return 0;
}