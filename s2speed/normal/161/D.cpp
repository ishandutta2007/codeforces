#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
struct piii {
	int first , second , third;
};

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

bool dead[MAX_N] , mark[MAX_N];
vector<int> adj[MAX_N];
int z[MAX_N] , sz , cnt[MAX_N] , cn[MAX_N] , dis[MAX_N] , dep = 0 , k , dcnt = 0;
ll ans = 0;

void bcDFS(int r , int par){
	mark[r] = true;
	if(par == -1) sz = 0;
	sz++;
	for(auto i : adj[r]){
		if(i == par || dead[i]) continue;
		bcDFS(i , r);
	}
	z[r] = 1;
	for(auto i : adj[r]){
		if(i == par || dead[i]) continue;
		z[r] += z[i];
	}
	return;
}

int find_centroid(int r , int par){
	for(auto i : adj[r]){
		if(i == par || dead[i]) continue;
		if(z[i] > sz / 2){
			return find_centroid(i , r);
		}
	}
	return r;
}

void acDFS(int r , int par){
	dis[r] = dep++;
	ans += cnt[k - dis[r]];
	if(~par){
		cn[dis[r]]++;
	} else {
		cnt[0] = 1;
	}
	for(auto i : adj[r]){
		if(i == par || dead[i]) continue;
		acDFS(i , r);
		if(~par) continue;
		for(int j = 1 ; j <= z[i] ; j++){
			cnt[j] += cn[j];
			cn[j] = 0;
		}
	}
	z[r] = 1;
	for(auto i : adj[r]){
		if(i == par || dead[i]) continue;
		z[r] += z[i];
	}
	dep--;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n>>k;
	fill(dead , dead + n , false);
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	fill(dead , dead + n , false);
	while(dcnt < n){
		for(int i = 0 ; i < n ; i++){
			mark[i] = dead[i];
		}
		for(int i = 0 ; i < n ; i++){
			if(mark[i]) continue;
			bcDFS(i , -1);
			int h = find_centroid(i , -1);
			acDFS(h , -1);
			dead[h] = true;
			dcnt++;
			for(int i = 0 ; i < sz ; i++){
				cnt[i] = 0;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}