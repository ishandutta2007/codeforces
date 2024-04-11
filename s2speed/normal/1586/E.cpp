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

ll ds[maxn];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

bool merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	if(v == u) return false;
	ds[u] = v;
	return true;
}

vector<ll> adj[maxn] , a , b;
vector<pll> qu;
ll f[maxn] , g[maxn] , jad[maxn][20] , pr[maxn] , dis[maxn] , dep = 0;

void jDFS(ll r , ll par){
	dis[r] = dep++;
	jad[r][0] = par;
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		jDFS(i , r);
	}
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
	if(dis[u] < dis[v]) swap(v , u);
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

void fDFS(ll r , ll par){
	for(auto i : adj[r]){
		if(i == par) continue;
		fDFS(i , r);
		f[r] += f[i];
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(jad , -1 , sizeof(jad));
	memset(f , 0 , sizeof(f));
	memset(g , 0 , sizeof(g));
	ll n , m;
	cin>>n>>m;
	iota(ds , ds + n , 0);
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		if(merge(v , u)){
			adj[v].push_back(u); adj[u].push_back(v);
		}
	}
	jDFS(0 , -1);
	ll q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll v , u;
		cin>>v>>u; v--; u--;
		qu.push_back({v , u});
		f[v]++; f[u]++; f[lca(v , u)] -= 2;
	}
	fDFS(0 , -1);
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		cnt += f[i] & 1;
		pr[i] = jad[i][0];
	}
	if(cnt > 0){
		cout<<"NO\n";
		for(ll i = 1 ; i < n ; i++){
			if(f[i] & 1){
				g[i]++; g[pr[i]]++;
			}
		}
		cnt = 0;
		for(ll i = 0 ; i < n ; i++){
			cnt += g[i] & 1;
		}
		cout<<cnt / 2<<'\n';
		return 0;
	}
	cout<<"YES\n";
	for(ll e = 0 ; e < q ; e++){
		a.clear();
		b.clear();
		ll v = qu[e].first , u = qu[e].second , l = lca(v , u) , h;
		h = v;
		while(h != l){
			a.push_back(h);
			h = pr[h];
		}
		h = u;
		while(h != l){
			b.push_back(h);
			h = pr[h];
		}
		reverse(all(b));
		cout<<sze(a) + sze(b) + 1<<'\n';
		for(auto i : a){
			cout<<i + 1<<' ';
		}
		cout<<l + 1<<' ';
		for(auto i : b){
			cout<<i + 1<<' ';
		}
		cout<<'\n';
	}
	return 0;
}