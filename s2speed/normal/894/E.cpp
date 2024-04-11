#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll { ll first , second , third; };
typedef pair<int , pii> piii;

const ll MAXN = 1e6 + 20 , md = 1e9 + 7 , inf = 1e16;
// check problem statement

vector<plll> ed;
vector<pll> adj[MAXN] , jda[MAXN] , ad[MAXN];
vector<ll> f , o , po;
ll c[MAXN] , x = 0 , d[MAXN] , dp[MAXN] , t[MAXN];
bitset<MAXN> mark;
priority_queue<pll , vector<pll> , greater<pll> > pq;

ll g(ll x){
	vector<ll>::iterator it = lower_bound(all(o) , x);
	if(it != o.begin()) it--;
	ll h = it - o.begin() , res;
	res = 1ll * (h + 1) * x;
	res -= po[h];
	return res;
}

void DFS1(ll r){
	mark[r] = true;
	for(auto p : adj[r]){
		ll i = p.first;
		if(mark[i]) continue;
		DFS1(i);
	}
	f.push_back(r);
	return;
}

void DFS2(ll r){
	c[r] = x;
	for(auto p : jda[r]){
		ll i = p.first;
		if(c[i] != -1 && c[i] != x) continue;
		t[x] += g(p.second);
		if(~c[i]) continue;
		DFS2(i);
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m , q = 0;
	for(int i = 1 ; q <= 1e8 ; i++){
		o.push_back(q);
		q += i;
	}
	po.resize(o.size());
	partial_sum(all(o) , po.begin());
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		adj[v].push_back({u , w}); jda[u].push_back({v , w});
		ed.push_back({v , u , w});
	}
	for(int i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		DFS1(i);
	}
	memset(c , -1 , sizeof(c));
	memset(t , 0 , sizeof(t));
	reverse(all(f));
	for(int e = 0 ; e < n ; e++){
		ll i = f[e];
		if(c[i] != -1) continue;
		DFS2(i);
		x++;
	}
	memset(d , 0 , sizeof(d));
	for(int i = 0 ; i < m ; i++){
		ll v , u , w;
		v = c[ed[i].first] , u = c[ed[i].second] , w = ed[i].third;
		if(v == u) continue;
		ad[v].push_back({u , w});
		d[u]++;
	}
	mark.flip();
	for(int i = 0 ; i < x ; i++){
		pq.push({d[i] , i});
	}
	ll s , h = 0;
	cin>>s; s--;
	memset(dp , -1 , sizeof(dp));
	while(!pq.empty()){
		pll p = pq.top(); pq.pop();
		ll v = p.second;
		if(mark[v]) continue;
		if(v == c[s]) dp[v] = 0;
		if(dp[v] != -1) dp[v] += t[v];
		for(auto u : ad[v]){
			ll i = u.first , w = u.second;
			dp[i] = max(dp[i] , (dp[v] == -1 ? -1 : dp[v] + w));
			d[i]--;
			pq.push({d[i] , i});
		}
		mark[v] = true;
	}
	for(int i = 0 ; i < x ; i++){
//		cout<<dp[i]<<' ';
		h = max(h , dp[i]);
	}
	cout<<h<<'\n';
	return 0;
}

/*
5 8
1 2 4
2 1 4
2 3 8
4 3 4
5 4 4
4 5 4
5 2 1
1 4 1
3
*/