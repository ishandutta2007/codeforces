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
int z[MAX_N] , S;
bool mark[MAX_N] , dead[MAX_N];
char ans[MAX_N];

void DFS(int r , int par){
	mark[r] = true;
	S++;
	for(auto i : adj[r]){
		if(i == par || dead[i]) continue;
		DFS(i , r);
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
		if(z[i] > S / 2){
			return find_centroid(i , r);
		}
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(int i = 0 ; i < n ; i++){
		dead[i] = false;
	}
	for(char i = 'A' ; i <= 'Z' ; i++){
		for(int j = 0 ; j < n ; j++){
			mark[j] = dead[j];
		}
		S = 0;
		for(int j = 0 ; j < n ; j++){
			if(mark[j]) continue;
			DFS(j , -1);
			int h = find_centroid(j , -1);
			dead[h] = true;
			ans[h] = i;
			S = 0;
		}
	}
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}