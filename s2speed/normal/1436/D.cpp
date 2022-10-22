#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 2e5;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

ll m[MAX_N] , c[MAX_N] , b[MAX_N] , a[MAX_N] , dad[MAX_N];
vector<ll> adj[MAX_N] , v;
bool mark[MAX_N];

void DFS(ll r){
	ll rs = adj[r].size();
	mark[r] = true;
	if(rs == 1 && r != 0){
		c[r] = 1;
		m[r] = a[r];
		b[r] = 0;
		return;
	}
	for(int e = 0 ; e < rs ; e++){
		int i = adj[r][e];
		if(mark[i] == false){
			dad[i] = r;
			DFS(i);
		}
	}
	m[r] = 0;
	for(int e = 0 ; e < rs ; e++){
		int i = adj[r][e];
		if(i == dad[r]){
			continue;
		}
		m[r] = max(m[r] , m[i]);
	}
	c[r] = 0;
	for(int e = 0 ; e < rs ; e++){
		int i = adj[r][e];
		if(i == dad[r]){
			continue;
		}
		c[r] += c[i];
	}
	b[r] = 0;
	for(int e = 0 ; e < rs ; e++){
		int i = adj[r][e];
		if(i == dad[r]){
			continue;
		}
		b[r] += b[i];
		b[r] += (m[r] - m[i]) * c[i];
	}
	v.clear();
	if(c[r] == 0){
		return;
	}
	if(a[r] <= b[r]){
		b[r] -= a[r];
	} else {
		a[r] -= b[r];
		b[r] = (c[r] - (a[r] % c[r])) % c[r];
		m[r] += (a[r] + c[r] - 1) / c[r];
	}
	return;
}

/*
5
1 2 3 4
1 1 1 1 1
*/

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		mark[i] = false;
	}
	for(int i = 1 ; i < n ; i++){
		ll inp;
		cin>>inp; inp--;
		adj[inp].push_back(i); adj[i].push_back(inp);
	}
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	dad[0] = -1;
	DFS(0);
	cout<<m[0]<<"\n";
	return 0;
}