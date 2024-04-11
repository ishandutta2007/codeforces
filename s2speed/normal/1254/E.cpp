#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pll;

const ll MAX_N = 5e5 + 20 , md = 1e9 + 7;

vector<ll> adj[MAX_N] , path;
vector<vector<ll> > dsu[MAX_N];
vector<ll> ds[MAX_N];
map<pll , ll> nu;
vector<bool> dir0[MAX_N] , dir1[MAX_N];
ll a[MAX_N][20] , dis[MAX_N] , d = 0 , fact[MAX_N] , c[MAX_N] , sw = 0 , n , f = 1;
bool ans = true;

void fact_build(){
    fact[0] = 1;
    for(int i = 1 ; i < MAX_N ; i++){
		fact[i] = fact[i - 1] * i;
		fact[i] %= md;
    }
}

void DFS(ll r){
	for(int j = 1 ; j < 20 ; j++){
		if(a[r][j - 1] == -1){
			break;
		}
		a[r][j] = a[a[r][j - 1]][j - 1];
	}
	dis[r] = d++;
	for(auto i : adj[r]){
		if(dis[i] == -1){
			a[i][0] = r;
			DFS(i);
		}
	}
	d--;
}

ll LCA(ll v , ll u){
	if(u == v){
		return v;
	}
	for(int j = 19 ; j >= 0 ; j--){
		if(a[v][j] != a[u][j]){
			v = a[v][j];
			u = a[u][j];
		}
	}
	return a[v][0];
}

void merge(ll v , ll u , ll p){
	if(ds[p][v] == ds[p][u]){
		ans = false;
		return;
	} else if(dsu[p][ds[p][v]].size() > dsu[p][ds[p][u]].size()){
		ll pl = ds[p][u];
		for(auto i : dsu[p][pl]){
			ds[p][i] = ds[p][v];
			dsu[p][ds[p][v]].push_back(i);
		}
		dsu[p][pl].clear();
	} else {
		ll pl = ds[p][v];
		for(auto i : dsu[p][pl]){
			ds[p][i] = ds[p][u];
			dsu[p][ds[p][u]].push_back(i);
		}
		dsu[p][pl].clear();
	}
	if(!dir0[p][v] || !dir1[p][u]){
		ans = false;
	}
	dir0[p][v] = false;
	dir1[p][u] = false;
}

void update(ll u , ll v){
	vector<ll> h;
	ll t , o;
	path.clear();
	path.push_back(u);
	if(dis[u] > dis[v]){
		t = u;
		while(dis[t] > dis[v]){
			t = a[t][0];
			path.push_back(t);
		}
		u = t;
	} else {
		h.push_back(v);
		t = v;
		while(dis[t] > dis[u]){
			t = a[t][0];
			h.push_back(t);
		}
		h.pop_back();
		v = t;
	}
	o = LCA(u , v);
	while(dis[u] > dis[o]){
		u = a[u][0];
		path.push_back(u);
	}
	while(dis[v] > dis[o]){
		h.push_back(v);
		v = a[v][0];
	}
	reverse(h.begin() , h.end());
	for(auto i : h){
		path.push_back(i);
	}
	ll ps = path.size();
	sw += ps - 1;
	if(sw > 2 * n - 2){
		ans = false;
		return;
	}
	merge(0 , nu[{path[0] , path[1]}] , path[0]);
	merge(nu[{path[ps - 1] , path[ps - 2]}] , adj[path[ps - 1]].size() + 1 , path[ps - 1]);
	for(int i = 1 ; i < ps - 1 ; i++){
		merge(nu[{path[i] , path[i - 1]}] , nu[{path[i] , path[i + 1]}] , path[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fact_build();
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		dis[i] = -1;
		for(int j = 0 ; j < 20 ; j++){
			a[i][j] = -1;
		}
	}
	for(int i = 1 ; i < n ; i++){
		pll p;
		cin>>p.first>>p.second; p.first--; p.second--;
		adj[p.first].push_back(p.second); adj[p.second].push_back(p.first);
		nu[p] = adj[p.first].size();
		swap(p.first , p.second);
		nu[p] = adj[p.first].size();
	}
	for(int i = 0 ; i < n ; i++){
		cin>>c[i];
		c[i]--;
		if(c[i] == i){
			cout<<"0\n";
			return 0;
		}
	}
	for(int i = 0 ; i < n ; i++){
		ll as = adj[i].size();
		ds[i].resize(as + 2);
		dsu[i].resize(as + 2);
		dir0[i].resize(as + 2);
		dir1[i].resize(as + 2);
		for(int j = 0 ; j <= as + 1 ; j++){
			ds[i][j] = j;
			dsu[i][j].push_back(j);
			dir0[i][j] = true;
			dir1[i][j] = true;
		}
	}
	DFS(0);
	for(int i = 0 ; i < n ; i++){
		if(c[i] != -1){
			update(c[i] , i);
		}
		if(!ans){
			cout<<"0\n";
			return 0;
		}
	}
	for(int i = 0 ; i < n ; i++){
		ll as = adj[i].size() , h = 0;
		if(ds[i][0] == ds[i][as + 1] && dsu[i][ds[i][0]].size() < as + 2){
			cout<<"0\n";
			return 0;
		}
		for(int j = 0 ; j <= as + 1 ; j++){
			if(dsu[i][j].size()){
				h++;
			}
		}
		h -= 2;
		if(h > 1){
			f *= fact[h];
			f %= md;
		}
	}
	cout<<f<<"\n";
	return 0;
}