#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 5e5 + 20;

vector<ll> v[MAX_N] , d , adj[MAX_N];
ll ans[MAX_N] , h[MAX_N] , f[MAX_N], q[MAX_N] , n;
string s;

void DFS(ll r){
	ll rs = adj[r].size();
	q[r] = d.size();
	for(int e = 0 ; e < rs ; e++){
		int i = adj[r][e];
		if(q[i] == -1){
			d.push_back(i);
			DFS(i);
			d.pop_back();
		}
	}
	return;
}

void bDFS(ll r){
	ll rs = adj[r].size() , b = 1 << (s[r] - 'a') , vs = v[r].size();
	for(int e = 0 ; e < vs ; e++){
		int t = v[r][e];
		ans[t] = f[h[t]];
	}
	f[q[r]] ^= b;
	for(int e = 0 ; e < rs ; e++){
		int i = adj[r][e];
		if(q[i] > q[r]){
			bDFS(i);
		}
	}
	for(int e = 0 ; e < vs ; e++){
		int t = v[r][e];
		ans[t] ^= f[h[t]];
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll m;
	cin>>n>>m;
	ans[0] = 0;
	f[0] = 0;
	for(int i = 1 ; i < n ; i++){
		ans[i] = 0;
		f[i] = 0;
		q[i] = -1;
		ll u;
		cin>>u;
		u--;
		adj[i].push_back(u); adj[u].push_back(i);
	}
	cin>>s;
	for(int i = 0 ; i < m ; i++){
		ll u;
		cin>>u>>h[i]; u--;
		v[u].push_back(i);
	}
	q[0] = 1;
	d.push_back(0);
	DFS(0);
	d.clear();
	bDFS(0);
	for(int i = 0 ; i < m ; i++){
		ll w = ans[i] & (ans[i] - 1);
		if(w == 0){
			cout<<"Yes\n";
		} else {
			cout<<"No\n";
		}
	}
	return 0;
}