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

vector<ll> adj[maxn] , vdj[maxn];
ll jad[maxn][20] , dis[maxn] , dep = 0 , st[maxn] , ft[maxn] , tme = 0;
pll dp[maxn];
ll s[maxn] , rad[maxn];
vector<ll> in , qu , t;
vector<pll> v , u;

void pDFS(ll r , ll par){
	dis[r] = dep++;
	st[r] = tme++;
	jad[r][0] = par;
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		pDFS(i , r);
	}
	ft[r] = tme;
	dep--;
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

ll dist(ll v , ll u){
	ll l = lca(v , u);
	return dis[v] + dis[u] - 2 * dis[l];
}

void dDFS(ll r){
	pll res = {inf , -1};
	for(auto i : vdj[r]){
		dDFS(i);
		ll j = dp[i].second;
		if(j == -1) continue;
		ll k = in[j] , h = (dist(r , k) + s[j] - 1) / s[j];
		res = min(res , {h , j});
	}
	dp[r] = res;
	if(rad[r] != -1){
		dp[r] = {0 , rad[r]};
	}
	return;
}

void uDFS(ll r , ll par){
	if(par != -1){
		ll j = dp[par].second;
		ll k = in[j] , h = (dist(r , k) + s[j] - 1) / s[j];
		dp[r] = min(dp[r] , {h , j});
	}
	for(auto i : vdj[r]){
		uDFS(i , r);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(jad , -1 , sizeof(jad));
	memset(rad , -1 , sizeof(rad));
	ll n;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	pDFS(0 , -1);
	ll q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		for(auto i : in) rad[i] = -1;
		in.clear(); qu.clear(); v.clear(); u.clear(); t.clear();
		ll k , m;
		cin>>k>>m;
		for(ll i = 0 ; i < k ; i++){
			ll h;
			cin>>h>>s[i]; h--;
			in.push_back(h);
			u.push_back({st[h] , h});
			rad[h] = i;
		}
		for(ll i = 0 ; i < m ; i++){
			ll h;
			cin>>h; h--;
			qu.push_back(h);
			u.push_back({st[h] , h});
		}
		sort(all(u));
		v = u;
		for(ll i = 1 ; i < k + m ; i++){
			ll h = lca(u[i].second , u[i - 1].second);
			v.push_back({st[h] , h});
		}
		sort(all(v));
		v.resize(distance(v.begin() , unique(all(v))));
		for(auto p : v){
			vdj[p.second].clear();
		}
		ll vs = sze(v);
		for(ll e = 0 ; e < vs ; e++){
			ll i = v[e].second , pr = -1;
			while(!t.empty()){
				ll u = t.back();
				if(st[u] < st[i] && ft[i] <= ft[u]){
					pr = u;
					break;
				}
				t.pop_back();
			}
			if(pr != -1) vdj[pr].push_back(i);
			t.push_back(i);
		}
		ll r = v[0].second;
		dDFS(r);
		uDFS(r , -1);
		for(auto i : qu){
			cout<<dp[i].second + 1<<' ';
		}
		cout<<'\n';
	}
	return 0;
}