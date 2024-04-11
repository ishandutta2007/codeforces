#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

vector<int> adj[MAX_N];
int jad[MAX_N][20] , dis[MAX_N] , dep = 0 , ps[MAX_N] , ans[MAX_N];
map<pii , int> mp;

void DFS1(int r , int par){
	dis[r] = dep++;
	for(int i = 1 ; i < 20 ; i++){
		if(jad[r][i - 1] == -1){
			break;
		}
		jad[r][i] = jad[jad[r][i - 1]][i - 1];
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		jad[i][0] = r;
		DFS1(i , r);
	}
	dep--;
	return;
}

int find_jad(int r , int d){
	d = dis[r] - d;
	int h = 1 << 19;
	for(int i = 19 ; i >= 0 ; i--){
		if(d >= h){
			r = jad[r][i];
			d -= h;
		}
		h /= 2;
	}
	return r;
}

int LCA(int v , int u){
	if(dis[v] > dis[u]){
		v = find_jad(v , dis[u]);
	}
	if(dis[u] > dis[v]){
		u = find_jad(u , dis[v]);
	}
	if(u == v){
		return v;
	}
	for(int i = 19 ; i >= 0 ; i--){
		if(jad[v][i] != jad[u][i]){
			v = jad[v][i];
			u = jad[u][i];
		}
	}
	return jad[v][0];
}

void DFS2(int r , int par){
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS2(i , r);
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		ps[r] += ps[i];
	}
	if(par == -1) return;
	ans[mp[{r , par}]] = ps[r];
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n , q;
	cin>>n;
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin>>v>>u; v--; u--;
		mp[{v , u}] = i;
		mp[{u , v}] = i;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 20 ; j++){
			jad[i][j] = -1;
		}
		ps[i] = 0;
	}
	DFS1(0 , -1);
	cin>>q;
	while(q--){
		int v , u , l;
		cin>>v>>u; v--; u--;
		ps[v]++; ps[u]++;
		l = LCA(v , u);
		ps[l] -= 2;
	}
	DFS2(0 , -1);
	for(int i = 1 ; i < n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}