#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 1e6 + 20 , md = 1e9 + 7;
 
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

vector<int> adj[MAX_N] , v[MAX_N];
int jad[MAX_N][20] , dis[MAX_N] , dep = 0 , st[MAX_N] , ft[MAX_N] , tme = 0;

void DFS(int r , int par){
	jad[r][0] = par;
	for(int i = 1 ; i < 20 ; i++){
		if(jad[r][i - 1] == -1) break;
		jad[r][i] = jad[jad[r][i - 1]][i - 1];
	}
	st[r] = tme++;
	dis[r] = dep;
	v[dep++].push_back(st[r]);
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
	}
	ft[r] = tme;
	dep--;
}

int find_jad(int u , int d){
	int h = 1 << 19;
	for(int i = 19 ; i >= 0 && u > -1 ; i--){
		if(d >= h){
			u = jad[u][i];
			d -= h;
		}
		h /= 2;
	}
	return u;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		int v;
		cin>>v;
		adj[v].push_back(i); adj[i].push_back(v);
	}
	DFS(0 , -1);
	int q;
	cin>>q;
	for(int i = 0 ; i < q ; i++){
		int u , p , l;
		cin>>u>>p;
		l = find_jad(u , p);
		if(l < 1){
			cout<<"0 ";
			continue;
		}
		int ans = -1 , h;
		h = lower_bound(v[dis[u]].begin() , v[dis[u]].end() , st[l]) - v[dis[u]].begin();
		ans -= h;
		h = lower_bound(v[dis[u]].begin() , v[dis[u]].end() , ft[l]) - v[dis[u]].begin();
		ans += h;
		cout<<ans<<' ';
	}
	return 0;
}