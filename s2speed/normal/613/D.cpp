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

vector<ll> adj[maxn] , vdj[maxn] , z , g;
vector<pll> ut , vt;
ll st[maxn] , ft[maxn] , tme = 0 , jad[maxn][20] , dis[maxn] , dep = 0;
ll dp[maxn] , pd[maxn];
bitset<maxn> mark;

void iDFS(ll r , ll par){
	st[r] = tme++;
	dis[r] = dep++;
	jad[r][0] = par;
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		iDFS(i , r);
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

void dDFS(ll r){
	for(auto i : vdj[r]){
		dDFS(i);
	}
	if(mark[r]){
		ll h = 0;
		for(auto i : vdj[r]){
			h += pd[i];
		}
		dp[r] = h;
		pd[r] = dp[r] + 1;
		return;
	}
	ll h = 0 , o = 0 , z = 0;
	for(auto i : vdj[r]){
		h += pd[i];
		o += dp[i];
		z = min(z , dp[i] - pd[i]);
	}
	dp[r] = min(h + z , o + 1);
	pd[r] = min(h , o + 1);
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(jad , -1 , sizeof(jad));
	ll n;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	iDFS(0 , -1);
	ll q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		for(auto p : vt){
			ll i = p.second;
			vdj[i].clear();
		}
		for(auto i : z) mark[i] = false;
		ut.clear(); vt.clear(); z.clear(); g.clear();
		ll k;
		cin>>k;
		for(ll i = 0 ; i < k ; i++){
			ll h;
			cin>>h; h--;
			z.push_back(h);
			mark[h] = true;
		}
		bool dead = false;
		for(auto i : z){
			if(!i) continue;
			if(mark[jad[i][0]]){
				dead = true;
				break;
			}
		}
		if(dead){
			cout<<"-1\n";
			continue;
		}
		for(auto i : z){
			ut.push_back({st[i] , i});
		}
		sort(all(ut));
		vt = ut;
		for(ll j = 1 ; j < k ; j++){
			ll v = ut[j - 1].second , u = ut[j].second , l;
			l = lca(v , u);
			vt.push_back({st[l] , l});
		}
		sort(all(vt));
		vt.resize(distance(vt.begin() , unique(all(vt))));
		ll vs = sze(vt) , rt = vt[0].second;
		for(ll i = 0 ; i < vs ; i++){
			ll v = vt[i].second , t = -1;
			while(!g.empty()){
				ll u = g.back();
				if(st[u] < st[v] && ft[v] <= ft[u]){
					t = u;
					break;
				}
				g.pop_back();
			}
			if(t != -1) vdj[t].push_back(v);
			g.push_back(v);
		}
		dDFS(rt);
//		for(auto p : vt){
//			ll i = p.first;
//			cout<<i<<": ";
//			for(auto v : vdj[i]){
//				cout<<v<<' ';
//			}
//			cout<<'\n';
//		}
		cout<<dp[rt]<<'\n';
	}
	return 0;
}