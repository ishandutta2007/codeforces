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

struct sgtree {

	ll sz = 1;
	vector<ll> val , laz;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		laz.assign(sz << 1 , 0);
	}

	void shift(ll x , ll lx , ll rx){
		if(laz[x] == 0) return;
		ll h = laz[x]; laz[x] = 0;
		val[x] += h;
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
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
		val[x] = max(val[ln] , val[rn]);
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
		return max(a , b);
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

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

	void clear(){
		sz = 1;
		val.clear();
		return;
	}

};

ll n;
sgtree nt;
segtree st;
ll jad[maxn][20] , bt[maxn] , ft[maxn] , tme = 0 , dis[maxn] , dep = 0 , f[maxn];
vector<pll> adj[maxn];

void aDFS(ll r , ll par , ll w){
	bt[r] = tme++;
	dep += w;
	dis[r] = dep;
	for(auto p : adj[r]){
		ll i = p.first;
		if(i == par) continue;
		aDFS(i , r , p.second);
	}
	dep -= w;
	ft[r] = tme;
	return;
}

void fDFS(ll r , ll par , ll w){
	nt.add(0 , n , w);
	nt.add(bt[r] , ft[r] , -2ll * w);
	f[r] = nt.cal(0 , n);
	for(auto p : adj[r]){
		ll i = p.first;
		if(i == par) continue;
		fDFS(i , r , p.second);
	}
	nt.add(0 , n , -w);
	nt.add(bt[r] , ft[r] , 2ll * w);
	return;
}

void jDFS(ll r , ll par){
	bt[r] = tme++;
	jad[r][0] = par;
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	for(auto p : adj[r]){
		ll i = p.first;
		if(i == par) continue;
		jDFS(i , r);
	}
	ft[r] = tme;
	return;
}

ll find_jad(ll v , ll l){
	ll h = f[v];
	for(ll j = 19 ; j >= 0 ; j--){
		if(jad[v][j] == -1) continue;
		if(f[jad[v][j]] < h - l) continue;
		v = jad[v][j];
	}
	return v;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(jad , -1 , sizeof(jad));
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		adj[v].push_back({u , w}); adj[u].push_back({v , w});
	}
	aDFS(0 , -1 , 0);
	nt.init(n);
	for(ll i = 0 ; i < n ; i++){
		nt.add(bt[i] , bt[i] + 1 , dis[i]);
	}
	fDFS(0 , -1 , 0);
	ll r = 0;
	for(ll i = 1 ; i < n ; i++){
		if(f[i] < f[r]) r = i;
	}
	tme = 0;
	jDFS(r , -1);
	ll q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll l;
		cin>>l;
		st.init(n);
		for(ll i = 0 ; i < n ; i++){
			ll j = find_jad(i , l);
			st.add(bt[i] , 1);
			if(jad[j][0] != -1){
				st.add(bt[jad[j][0]] , -1);
			}
		}
		ll ans = 0;
		for(ll i = 0 ; i < n ; i++){
			ans = max(ans , st.cal(bt[i] , ft[i]));
		}
		cout<<ans<<'\n';
		st.clear();
	}
	return 0;
}