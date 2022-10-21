#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

struct sagtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 1);
		return;
	}

	void add(ll l , ll r , ll k , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			val[x] *= k; val[x] %= md;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll i , ll x , ll lx , ll rx){
		if(rx - lx == 1) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a;
		if(i < m){
			a = cal(i , ln , lx , m);
		} else {
			a = cal(i , rn , m , rx);
		}
		a *= val[x]; a %= md;
		return a;
	}

	ll cal(ll i){
		return cal(i , 0 , 0 , sz);
	}

};

struct segtree {

	ll sz = 1;
	vector<ll> val , laz;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		laz.assign(sz << 1 , 1);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = 1;
		val[x] *= h; val[x] %= md;
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln] *= h; laz[ln] %= md;
		laz[rn] *= h; laz[rn] %= md;
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(i < lx || i >= rx) return;
		if(rx - lx == 1){
			val[x] = k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		set(i , k , ln , lx , m); set(i , k , rn , m , rx);
		val[x] = val[ln] + val[rn]; val[x] -= (val[x] >= md) * md;
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
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
		val[x] = val[ln] + val[rn]; val[x] -= (val[x] >= md) * md;
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz) % md;
	}

};

sagtree z;
segtree st;
vector<ll> adj[maxn];
ll vl[maxn] , pr[maxn] , f[maxn];
vector<pll> qu;
ll bt[maxn] , ft[maxn] , tme = 0;

void tDFS(ll r){
	bt[r] = tme++;
	for(auto i : adj[r]){
	    tDFS(i);
	}
	ft[r] = tme;
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n = 1 , q;
	cin>>vl[0]>>q;
	for(ll i = 0 ; i < q ; i++){
	    ll t;
	    cin>>t;
	    if(t == 1){
	        cin>>pr[n]>>vl[n]; pr[n]--;
	        adj[pr[n]].push_back(n);
	        qu.push_back({1 , n++});
	    } else {
	        ll i;
	        cin>>i; i--;
	        qu.push_back({2 , i});
	    }
	}
	tDFS(0);
	fill(f , f + n , 1);
	st.init(n); z.init(n);
	st.set(0 , vl[0]);
	for(auto p : qu){
		ll t = p.first , v = p.second;
		if(t == 2){
			ll h = st.cal(bt[v] , ft[v]);
			ll d = (v == 0 ? 1 : z.cal(bt[pr[v]]));
			h *= tav(d , md - 2); h %= md;
			cout<<h<<'\n';
		} else {
			ll u = pr[v];
			ll h = tav(f[u] , md - 2) * ++f[u] % md;
			st.add(bt[u] , ft[u] , h);
			z.add(bt[u] , ft[u] , h);
			h = vl[v] * z.cal(bt[v]) % md;
			st.set(bt[v] , h);
		}
	}
	return 0;
}