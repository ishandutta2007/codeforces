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

const ll maxn = 1e5 + 16 , maxm = 3e2 + 16 , md = 1e9 + 7 , inf = 2e16;

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
ll st[maxn] , et[maxn] , tme = 0 , jad[maxn][20] , dis[maxn] , dep = 0 , dp[maxm] , pd[maxm];
vector<pll> g;

void sDFS(ll r , ll par){
	st[r] = tme++;
	dis[r] = dep++;
	jad[r][0] = par;
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		sDFS(i , r);
	}
	dep--;
	et[r] = tme;
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
	for(ll j = 19 ; ~j ; j--){
		if(jad[v][j] != jad[u][j]){
			v = jad[v][j];
			u = jad[u][j];
		}
	}
	return jad[v][0];
}

ll dist(ll v , ll u){
	ll l = lca(v , u);
	return dis[v] + dis[u] - 2 * dis[l];
}

ll cal(ll v , ll u){
	ll l = lca(v , u);
	return ft.cal(st[v]) + ft.cal(st[u]) - (l == 0 ? 0 : ft.cal(st[jad[l][0]])) - ft.cal(st[l]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(jad , -1 , sizeof(jad));
	memset(dp , 0 , sizeof(dp));
	ll n , q;
	cin>>n>>q;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	sDFS(0 , -1);
	ft.init(n);
	for(ll e = 0 ; e < q ; e++){
		g.clear();
		ll k , r , m;
		cin>>k>>m>>r; r--;
		for(ll i = 0 ; i < k ; i++){
			ll v;
			cin>>v; v--;
			g.push_back({dist(v , r) , v});
		}
		sort(all(g));
		memset(pd , 0 , sizeof(pd));
		pd[1] = 1;
		ft.add(st[g[0].second] , 1); ft.add(et[g[0].second] , -1);
		for(ll i = 1 ; i < k ; i++){
			ll v = g[i].second , z = cal(v , r);
			for(ll j = 1 ; j <= m ; j++){
				dp[j] = pd[j - 1];
				dp[j] += (j - z) * pd[j] % md;
				dp[j] %= md;
			}
			ft.add(st[v] , 1); ft.add(et[v] , -1);
			memcpy(pd , dp , sizeof(pd));
			memset(dp , 0 , sizeof(dp));
		}
		ll ans = 0;
		for(ll j = 1 ; j <= m ; j++){
			ans += pd[j];
		}
		ans %= md;
		cout<<ans<<'\n';
		for(auto p : g){
//			cout<<p.first<<' '<<p.second<<'\n';
			ft.add(st[p.second] , -1); ft.add(et[p.second] , 1);
		}
	}
	return 0;
}

/*
7 1
5 4
2 6
5 3
1 2
7 5
4 6
3 3 2 7 4 3
*/