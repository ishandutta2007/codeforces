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
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

struct segtree {
 
	int sz = 1;
	vector<int> val , laz;
 
	void init(int n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		laz.assign(sz << 1 , 0);
		return;
	}
 
	void shift(int x , int lx , int rx){
		int h = laz[x];
		laz[x] = 0;
		val[x] += 1ll * h * (rx - lx);
		if(rx - lx == 1) return;
		int ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln] += h; laz[rn] += h;
		return;
	}
 
	void add(int l , int r , int k , int x , int lx , int rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = k;
			shift(x , lx , rx);
			return;
		}
		int m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}
 
	void add(int l , int r , int k){
		if(l >= r) return;
		add(l , r , k , 0 , 0 , sz);
		return;
	}
 
	int cal(int l , int r , int x , int lx , int rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		int m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		int a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return a + b;
	}
 
	int cal(int l , int r){
		if(l >= r) return 0;
		return cal(l , r , 0 , 0 , sz);
	}
 
};

int ds[maxn];

int dsu(int v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

bool merge(int v , int u){
	v = dsu(v); u = dsu(u);
	if(v == u) return false;
	ds[u] = v;
	return true;
}

bitset<maxn> an , mark;
vector<piii> ed;
vector<pii> adj[maxn];
int f[maxn];
segtree st;
int hc[maxn] , hp[maxn] , lb[maxn] , z[maxn] , cur = 0 , jad[maxn][20] , dis[maxn] , dep = 0;

void fDFS(int r , int par , bool c){
	mark[r] = true;
	if(par != -1) f[r] = f[par] ^ c;
	dis[r] = dep++;
	jad[r][0] = par;
	for(int j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	z[r] = 1;
	int m = -1;
	for(auto p : adj[r]){
		int i = p.first;
		if(i == par) continue;
		fDFS(i , r , p.second);
		z[r] += z[i];
		if(z[i] > m){
			m = z[i];
			hc[r] = i;
		}
	}
	dep--;
	return;
}

void hDFS(int r , int par){
	mark[r] = true;
	lb[r] = cur++;
	if((par == -1 ? false : hc[par] == r)){
		hp[r] = hp[par];
	} else {
		hp[r] = r;
	}
	if(z[r] == 1) return;
	hDFS(hc[r] , r);
	for(auto p : adj[r]){
		int i = p.first;
		if(i == par || i == hc[r]) continue;
		hDFS(i , r);
	}
	return;
}

int find_jad(int v , int d){
	d = dis[v] - d;
	for(int j = 0 ; j < 20 ; j++){
		if(d & (1 << j)){
			v = jad[v][j];
		}
	}
	return v;
}

int lca(int v , int u){
	if(dis[v] > dis[u]) swap(v , u);
	u = find_jad(u , dis[v]);
	if(v == u) return v;
	for(int j = 19 ; j >= 0 ; j--){
		if(jad[v][j] != jad[u][j]){
			v = jad[v][j];
			u = jad[u][j];
		}
	}
	return jad[v][0];
}

void add(int v , int u , int k){
	int r = v , l = lca(v , u);
	while(r != -1){
		int t = hp[r];
		if(dis[t] <= dis[l]){
			st.add(lb[r] - dis[r] + dis[l] + 1 , lb[r] + 1 , k);
			break;
		}
		st.add(lb[hp[r]] , lb[r] + 1 , k);
		r = jad[hp[r]][0];
	}
	r = u;
	while(r != -1){
		int t = hp[r];
		if(dis[t] <= dis[l]){
			st.add(lb[r] - dis[r] + dis[l] + 1 , lb[r] + 1 , k);
			break;
		}
		st.add(lb[hp[r]] , lb[r] + 1 , k);
		r = jad[hp[r]][0];
	}
	return;
}

int cal(int v , int u){
	int r = v , res = 0 , h , l = lca(v , u);
	while(r > 0){
		int t = hp[r];
		if(dis[t] <= dis[l]){
			h = st.cal(lb[r] - dis[r] + dis[l] + 1 , lb[r] + 1);
			res += h;
			break;
		}
		h = st.cal(lb[hp[r]] , lb[r] + 1);
		res += h;
		r = jad[hp[r]][0];
	}
	r = u;
	while(r > 0){
		int t = hp[r];
		if(dis[t] <= dis[l]){
			h = st.cal(lb[r] - dis[r] + dis[l] + 1 , lb[r] + 1);
			res += h;
			break;
		}
		h = st.cal(lb[hp[r]] , lb[r] + 1);
		res += h;
		r = jad[hp[r]][0];
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(f , 0 , sizeof(f));
	memset(jad , -1 , sizeof(jad));
	int n , m;
	cin>>n>>m;
	st.init(n);
	iota(ds , ds + n , 0);
	for(int i = 0 ; i < m ; i++){
		int v , u , c;
		cin>>v>>u>>c; v--; u--;
		an[i] = merge(v , u);
		if(an[i]){
			adj[v].push_back({u , c}); adj[u].push_back({v , c});
		}
		ed.push_back({{v , u} , c});
	}
	for(int i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		fDFS(i , -1 , 0);
	}
	mark.reset();
	for(int i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		hDFS(i , -1);
	}
	for(int i = 0 ; i < m ; i++){
		if(an[i]){
			cout<<"YES\n";
			continue;
		}
		int v = ed[i].first.first , u = ed[i].first.second , c = ed[i].second;
		if(!(f[v] ^ f[u] ^ c)){
			cout<<"NO\n";
			continue;
		}
		int h = cal(v , u);
		if(!h){
			cout<<"YES\n";
			add(v , u , 1);
		} else {
			cout<<"NO\n";
		}
	}
	return 0;
}