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

struct segtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		return;
	}

	void add(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] += k;
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

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
ll bt[maxn] , ft[maxn] , tme = 0 , dis[maxn] , dep = 0 , jad[maxn][20] , ps[maxn];
vector<pll> adj[maxn];
set<pll> s;

void pDFS(ll r , ll par){
	bt[r] = tme++;
	dis[r] = dep++;
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	for(auto p : adj[r]){
		ll i = p.first , w = p.second;
		if(i == par) continue;
		jad[i][0] = r;
		ps[i] = ps[r] + w;
		pDFS(i , r);
	}
	ft[r] = tme;
	dep--;
	return;
}

ll find_jad(ll v , ll d){
	d = dis[v] - d;
	for(ll j = 0 ; j < 20 ; j++){
		if(d & (1 << j)) v = jad[v][j];
	}
	return v;
}

ll lca(ll v , ll u){
	if(dis[v] > dis[u]) swap(v , u);
	u = find_jad(u , dis[v]);
	if(v == u) return v;
	for(ll j = 19 ; j >= 0 ; j--){
		if(jad[v][j] != jad[u][j]){
			v = jad[v][j];
			u = jad[u][j];
		}
	}
	return jad[v][0];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(jad , -1 , sizeof(jad));
	memset(ps , 0 , sizeof(ps));
	ll n , q;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		adj[v].push_back({u , w}); adj[u].push_back({v , w});
	}
	pDFS(0 , -1);
	st.init(n);
	ll cnt = 0 , cur = 0 , l = -1;
	cin>>q;
	for(ll i = 0 ; i < q ; i++){
		char c;
		cin>>c;
		if(c == '?'){
			cout<<cur<<'\n';
			continue;
		}
		if(c == '-'){
			cnt--;
			ll v;
			cin>>v; v--;
			s.erase({bt[v] , v});
			st.add(bt[v] , -1);
			if(cnt == 0){
				cur = 0;
				continue;
			}
			auto it = s.begin();
			ll r , t , h;
			r = (*it).second;
			it = s.end(); it--;
			t = (*it).second;
			h = lca(r , t);
			cur -= ps[h] - ps[l];
			l = h;
			h = v;
			for(ll j = 19 ; j >= 0 ; j--){
				if(jad[h][j] == -1) continue;
				ll o = jad[h][j];
				if(st.cal(bt[o] , ft[o])) continue;
				h = o;
			}
			if(st.cal(bt[h] , ft[h]) == 0) h = jad[h][0];
			cur -= ps[v] - (h == -1 ? 0 : ps[h]);
		} else {
			cnt++;
			ll v;
			cin>>v; v--;
			s.insert({bt[v] , v});
			st.add(bt[v] , 1);
			if(cnt == 1){
				l = v;
				continue;
			}
			auto it = s.begin();
			ll r , t , h;
			r = (*it).second;
			it = s.end(); it--;
			t = (*it).second;
			h = lca(r , t);
			cur += ps[l] - ps[h];
			l = h;
			h = v;
			for(ll j = 19 ; j >= 0 ; j--){
				ll o = jad[h][j];
				if(o == -1) continue;
				if(st.cal(bt[o] , ft[o]) > 1) continue;
				h = o;
			}
			if(st.cal(bt[h] , ft[h]) == 1) h = jad[h][0];
			cur += ps[v] - (h == -1 ? 0 : ps[h]);
		}
	}
	return 0;
}