#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e5 + 20 , md = 1e9 + 7;
ll inf;
// check problem statement

vector<ll> adj[MAXN] , cdj[MAXN] , v[MAXN] , ps[MAXN] , bfs;
vector<pll> ed;
ll f[MAXN] , dis[MAXN] , z[MAXN] , d[MAXN] , sz[MAXN] , c = 0;
bitset<MAXN> mark;
map<pll , ll> mp;
priority_queue<pll , vector<pll> , greater<pll> > pq;

void BFS(ll r){
	bfs.clear();
	dis[r] = 0;
	bfs.push_back(r);
	ll x = 0;
	while(x < bfs.size()){
		ll v = bfs[x];
		mark[v] = true;
		z[v] = c;
		sz[c]++;
		for(auto i : adj[v]){
			if(dis[i] > dis[v] + 1){
				dis[i] = dis[v] + 1;
				bfs.push_back(i);
			}
		}
		x++;
	}
	return;
}

void ns(ll u , ll w){
	ll us = v[u].size() , ws = v[w].size() , o = max(v[u][us - 1] , v[w][ws - 1]) , ans = 0;
	for(int e = 0 ; e < us ; e++){
		ll i = v[u][e] , h;
		vector<ll>::iterator it = upper_bound(all(v[w]) , o - i - 1);
		h = it - v[w].begin();
		ans += 1ll * h * o;
		ans += ps[w][h];
		h = ws - h;
		ans += 1ll * h * (i + 1);
	}
	mp[{u , w}] = ans;
	mp[{w , u}] = ans;
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dis , 63 , sizeof(dis));
	memset(d , 0 , sizeof(d));
	memset(f , 0 , sizeof(f));
	inf = dis[0];
	ll n , m , q;
	cin>>n>>m>>q;
	for(int i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(int i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		BFS(i);
		ll h = i;
		for(auto j : bfs){
			h = j;
			f[j] = max(f[j] , dis[j]);
			dis[j] = inf;
		}
		sz[c] = 0;
		BFS(h);
		for(auto j : bfs){
			f[j] = max(f[j] , dis[j]);
			dis[j] = inf;
		}
		BFS(bfs[sz[c] - 1]);
		sz[c] /= 2;
		for(auto j : bfs){
			f[j] = max(f[j] , dis[j]);
			v[c].push_back(f[j]);
		}
		sort(all(v[c]));
		ps[c].resize(v[c].size());
		partial_sum(v[c].rbegin() , v[c].rend() , ps[c].rbegin());
		ps[c].push_back(0);
		c++;
	}
	for(int i = 0 ; i < q ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		v = z[v]; u = z[u];
		ed.push_back({v , u});
		if(v == u) continue;
		if(mp.count({v , u})) continue;
		cdj[v].push_back(u); cdj[u].push_back(v);
		d[v]++; d[u]++;
		mp[{v , u}] = -1; mp[{u , v}] = -1;
	}
	for(int i = 0 ; i < c ; i++){
		pq.push({d[i] , i});
	}
	mark.flip();
	while(!pq.empty()){
		pll p = pq.top(); pq.pop();
		ll v = p.second;
		if(mark[v]) continue;
		for(auto i : cdj[v]){
			if(mark[i]) continue;
			ns(v , i);
			d[i]--;
			pq.push({d[i] , i});
		}
		mark[v] = true;
	}
	for(int i = 0 ; i < q ; i++){
		ll v = ed[i].first , u = ed[i].second;
		if(v == u){
			printf("-1\n");
			continue;
		}
		db ans = mp[{v , u}] , h = 1ll * sz[v] * sz[u];
		ans /= h;
		printf("%.10Lf\n" , ans);
	}
	return 0;
}

/*

*/