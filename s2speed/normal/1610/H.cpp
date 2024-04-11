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

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

struct fentree {

	ll sz;
	vector<ll> val;

	void init(ll n){
		sz = n;
		val.assign(sz , 0);
		return;
	}

	void add(ll i , ll k){
		ll h = i;
		while(h < sz){
			val[h] += k;
			h |= (h + 1);
		}
		return;
	}

	ll cal(ll i){
		ll h = i , res = 0;
		while(~h){
			res += val[h];
			h &= (h + 1); h--;
		}
		return res;
	}

};

fentree ft;
vector<ll> adj[maxn];
vector<pll> y , t , w;
ll st[maxn] , et[maxn] , tme = 0 , pr[maxn] , jad[maxn][20] , dis[maxn] , dep = 0;

void pDFS(ll r , ll par){
	st[r] = tme++;
	dis[r] = dep++;
	jad[r][0] = pr[r] = par;
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		pDFS(i , r);
	}
	dep--;
	et[r] = tme;
	return;
}

ll find_jad(ll v , ll d){
	d = dis[v] - d;
	for(ll j = 0 ; j < 20 ; j++){
		if(d & (1 << j)){
			v = jad[v][j];
		}
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
	ll n , m;
	cin>>n>>m;
	for(ll i = 1 ; i < n ; i++){
		ll a;
		cin>>a; a--;
		adj[a].push_back(i); adj[i].push_back(a);
	}
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		y.push_back({v , u});
	}
	wall;
	pDFS(0 , -1);
	for(ll i = 0 ; i < m ; i++){
		ll v = y[i].first , u = y[i].second;
		if(v == pr[u] || u == pr[v]){
			cout<<"-1\n";
			return 0;
		}
		if(dis[v] > dis[u]){
			swap(v , u);
			swap(y[i].first , y[i].second);
		}
		if(st[v] < st[u] && et[v] >= et[u]){
			t.push_back({dis[v] , i});
		} else {
			w.push_back({v , u});
		}
	}
	sort(all(t) , greater<pll>());
	ll ts = sze(t) , ans = 0;
	ft.init(n);
	for(ll e = 0 ; e < ts ; e++){
		ll i = t[e].second , u = y[i].second , v = find_jad(u , t[e].first + 1);
		ll h = ft.cal(et[v] - 1) - ft.cal(st[v] - 1) - (ft.cal(et[u] - 1) - ft.cal(st[u] - 1));
		if(h > 0) continue;
		ans++;
		ft.add(st[v] , 1);
	}
	bool o = false;
	for(auto p : w){
		ll v = p.first , u = p.second;
		ll h = ft.cal(et[v] - 1) - ft.cal(st[v] - 1) + ft.cal(et[u] - 1) - ft.cal(st[u] - 1);
		o |= (h == ans);
	}
	cout<<ans + o<<'\n';
	return 0;
}

/*
7 4
1 1 2 2 3 3
1 4
1 7
6 1
2 3
*/