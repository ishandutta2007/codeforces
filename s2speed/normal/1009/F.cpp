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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

vector<ll> adj[maxn] , g[maxn];
ll dis[maxn] , dep = 0 , hv[maxn] , z[maxn];

void aDFS(ll r , ll par){
	z[r] = 1;
	dis[r] = dep++;
	ll m = -1 , ind = -1;
	for(auto i : adj[r]){
		if(i == par) continue;
		aDFS(i , r);
		z[r] += z[i];
		if(z[i] > m){
			m = z[i];
			ind = i;
		}
	}
	hv[r] = ind;
	dep--;
	return;
}

ll cnt[maxn] , cur = 0 , ans[maxn];

void add(ll x){
	cnt[x]++;
	if(cnt[x] > cnt[cur]){
		cur = x;
		return;
	}
	if(cnt[x] == cnt[cur] && x < cur){
		cur = x;
	}
	return;
}

void clear(ll v){
	for(auto i : g[v]){
		cnt[dis[i]]--;
	}
	cur = 0;
}

void gDFS(ll r , ll par){
	if(hv[r] == -1){
		g[r].push_back(r);
		add(dis[r]);
		ans[r] = 0;
		return;
	}
	for(auto i : adj[r]){
		if(i == par || i == hv[r]) continue;
		gDFS(i , r);
		clear(i);
	}
	gDFS(hv[r] , r);
	swap(g[r] , g[hv[r]]);
	g[r].push_back(r);
	add(dis[r]);
	for(auto i : adj[r]){
		if(i == par || i == hv[r]) continue;
		for(auto j : g[i]){
			add(dis[j]);
			g[r].push_back(j);
		}
		g[i].clear();
		g[i].shrink_to_fit();
	}
	ans[r] = cur - dis[r];
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	aDFS(0 , -1);
	gDFS(0 , -1);
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}