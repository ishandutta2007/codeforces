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

ll ds[maxn];
multiset<plll> adj[maxn][2];
bitset<maxn> ans , c , mark , st , fix;
vector<plll> del , add;
vector<pll> ed;
vector<ll> wd;

pll dsu(ll v){
	if(ds[v] == v){
		fix[v] = true;
		return {v , c[v]};
	}
	pll h = dsu(ds[v]);
	ds[v] = h.first;
	if(!fix[v]) c[v] = c[v] ^ h.second;
	fix[v] = true;
	return {ds[v] , c[v]};
}

void DFS(ll i , bool o){
	mark[i] = true;
	if(!adj[i][0].empty()){
		plll p = *(adj[i][0].begin());
		ll u = p.first.first , h = p.first.second , j = p.second;
		if(!mark[u]){
			ans[j] = h ^ o;
			DFS(u , o);
		}
	}
	if(!adj[i][1].empty()){
		plll p = *(adj[i][1].begin());
		ll u = p.first.first , h = p.first.second , j = p.second;
		if(!mark[u]){
			ans[j] = h ^ o;
			DFS(u , o ^ st[i]);
		}
		if(mark[u] && st[i]){
			ans[j] = h ^ 1;
		}
	}
	return;
}

string res;
ll d[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(d , 0 , sizeof(d));
	ll n , m;
	cin>>n>>m;
	iota(ds , ds + m , 0);
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--; w--;
		d[v] += w + 1; d[u] += w + 1;
		adj[v][w].insert({{u , 0} , i});
		adj[u][w].insert({{v , 1} , i});
		ed.push_back({v , u}); wd.push_back(w);
	}
	for(ll i = 0 ; i < n ; i++){
		while(sze(adj[i][0]) >= 2){
			auto it = adj[i][0].begin() , jt = it , et = adj[i][0].end();
			if(it != et) jt++;
			while(it != et && jt != et){
				plll p1 = *it , p2 = *jt;
				del.push_back(p1); del.push_back(p2);
				ll u1 = p1.first.first , u2 = p2.first.first;
				bool c1 = p1.first.second , c2 = p2.first.second;
				ll j1 = p1.second , j2 = p2.second;
				if(u1 != i) adj[u1][0].erase(adj[u1][0].find({{i , p1.first.second ^ 1} , p1.second}));
				if(u2 != i) adj[u2][0].erase(adj[u2][0].find({{i , p2.first.second ^ 1} , p2.second}));
				if(u1 != i){
					adj[u1][0].insert({{u2 , 0} , j2});
				} else {
					add.push_back({{u2 , 0} , j2});
				}
				if(u2 != u1){
					if(u2 != i){
						adj[u2][0].insert({{u1 , 1} , j2});
					} else {
						add.push_back({{u1 , 1} , j2});
					}
				}
				ds[j1] = j2;
				bool h = c2 ^ !c1;
				c[j1] = c[j1] ^ h ^ c[j2];
				c[j2] = c[j2] ^ c2;
				jt++; it = jt; jt++;
			}
			for(auto p : del){
				adj[i][0].erase(adj[i][0].find(p));
			}
			del.clear();
			for(auto p : add){
				adj[i][0].insert(p);
			}
			add.clear();
		}
		while(sze(adj[i][1]) >= 2){
			auto it = adj[i][1].begin() , jt = it , et = adj[i][1].end();
			if(it != et) jt++;
			while(it != et && jt != et){
				plll p1 = *it , p2 = *jt;
				del.push_back(p1); del.push_back(p2);
				ll u1 = p1.first.first , u2 = p2.first.first;
				bool c1 = p1.first.second , c2 = p2.first.second;
				ll j1 = p1.second , j2 = p2.second;
				if(u1 != i) adj[u1][1].erase(adj[u1][1].find({{i , p1.first.second ^ 1} , p1.second}));
				if(u2 != i) adj[u2][1].erase(adj[u2][1].find({{i , p2.first.second ^ 1} , p2.second}));
				if(u1 != i){
					adj[u1][1].insert({{u2 , 0} , j2});
				} else {
					add.push_back({{u2 , 0} , j2});
				}
				if(u2 != u1){
					if(u2 != i){
						adj[u2][1].insert({{u1 , 1} , j2});
					} else {
						add.push_back({{u1 , 1} , j2});
					}
				}
				ds[j1] = j2;
				bool h = c2 ^ !c1;
				c[j1] = c[j1] ^ h ^ c[j2];
				c[j2] = c[j2] ^ c2;
				jt++; it = jt; jt++;
			}
			for(auto p : del){
				adj[i][1].erase(adj[i][1].find(p));
			}
			del.clear();
			for(auto p : add){
				adj[i][1].insert(p);
			}
			add.clear();
		}
	}
//	wall;
//	for(ll i = 0 ; i < n ; i++){
//		if(!adj[i][0].empty()){
//			plll p = *(adj[i][0].begin());
//			if(p.first.first >= i){
//				cout<<i + 1<<' '<<p.first.first + 1<<' '<<p.first.second<<" 1\n";
//			}
//		}
//		if(!adj[i][1].empty()){
//			plll p = *(adj[i][1].begin());
//			if(p.first.first >= i){
//				cout<<i + 1<<' '<<p.first.first + 1<<' '<<p.first.second<<" 2\n";
//			}
//		}
//	}
//	wall;
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		cnt += d[i] & 1;
		if(mark[i]) continue;
		st[i] = true;
		DFS(i , 0);
	}
//	wall;
	for(ll i = 0 ; i < m ; i++){
		pll p = dsu(i);
		ll j = p.first , h = p.second;
		bool o = ans[j] ^ h;
		if(o) swap(ed[i].first , ed[i].second);
//		cerr<<ed[i].first + 1<<' '<<ed[i].second + 1<<' '<<wd[i] + 1<<'\n';
		res += '1' + o;
	}
//	wall;
	cout<<cnt<<'\n'<<res<<'\n';
	return 0;
}

/*
5 4
2 1 2
3 2 2
3 4 2
5 4 2
*/