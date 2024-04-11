#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 15 , md = 1e9 + 7 , inf = 2e18;

ll ds[maxn];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	ds[u] = v;
	return;
}

ll n , m;
string s[] = {"none\n" , "at least one\n" , "any\n"};
ll t[maxn] , dis[maxn] , dep = 0 , hb[maxn] , hz[maxn];
vector<pll> adj[maxn];
vector<pllll> ed;
bitset<maxn> mark;
vector<ll> vd;

void DFS(ll r , ll ind){
	mark[r] = true;
	dis[r] = dep++;
	hb[r] = hz[r] = inf;
	for(auto p : adj[r]){
		ll i = p.first , j = p.second;
		if(j == ind) continue;
		if(mark[i]){
			t[j] = 1;
			hb[r] = min(hb[r] , dis[i]);
			continue;
		}
		DFS(i , j);
		hz[r] = min(hz[r] , hz[i]);
	}
	hz[r] = min(hz[r] , hb[r]);
	t[ind] = 2 - (hz[r] < dis[r]);
	dep--;
	return;
}

void update(){
	for(auto i : vd){
		if(mark[i]) continue;
		DFS(i , m);
	}
	for(auto i : vd){
		if(!mark[i]) continue;
		mark[i] = false;
		for(auto p : adj[i]){
			ll j = p.first;
			merge(i , j);
		}
		adj[i].clear();
	}
	vd.clear();
	return;
}

int main(){ // check maxn
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		ed.push_back({{w , i} , {v , u}});
	}
	sort(all(ed));
	iota(ds , ds + n , 0);
	ll vv = ed[0].second.first , uu = ed[0].second.second , ii = ed[0].first.second;
	adj[vv].push_back({uu , ii}); adj[uu].push_back({vv , ii});
	vd.push_back(vv); vd.push_back(uu);
	for(ll i = 1 ; i < m ; i++){
		ll v = ed[i].second.first , u = ed[i].second.second , w = ed[i].first.first , j = ed[i].first.second;
		if(w != ed[i - 1].first.first){
			update();
		}
		ll a = dsu(v) , b = dsu(u);
		if(a == b){
			t[j] = 0;
			continue;
		}
		adj[a].push_back({b , j}); adj[b].push_back({a , j});
		vd.push_back(a); vd.push_back(b);
	}
	update();
	for(ll i = 0 ; i < m ; i++){
		cout<<s[t[i]];
	}
	return 0;
}