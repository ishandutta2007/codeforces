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

ll r[MAX_N] , v[MAX_N] , ans = 0;
bool mark[MAX_N] , br = false;
vector<ll> adj[MAX_N];
vector<pll> q;

void DFS(ll r , ll par){
	mark[r] = true;
	ans++;
	for(auto i : adj[r]){
		if(i == par){
			continue;
		}
		if(mark[i]){
			ans++;
			br = true;
			return;
		}
		DFS(i , r);
		if(br){
			return;
		}
	}
	return;
}

void solve(){
	ll n , m;
	cin>>n>>m;
	q.clear();
	ans = 0;
	for(int i = 0 ; i < n ; i++){
		adj[i].clear();
		r[i] = -1;
		v[i] = -1;
		mark[i] = false;
	}
	for(int i = 0 ; i < m ; i++){
		int a , b;
		cin>>a>>b; a--; b--;
		r[a] = i;
		v[b] = i;
		q.push_back({a , b});
	}
	for(int i = 0 ; i < m ; i++){
		int a = q[i].first , b = q[i].second;
		if(v[a] != -1){
			adj[i].push_back(v[a]);
		}
		if(r[b] != -1){
			adj[i].push_back(r[b]);
		}
	}
	for(int i = 0 ; i < m ; i++){
		br = false;
		if(q[i].first == q[i].second || mark[i]){
			continue;
		}
		DFS(i , -1);
	}
	cout<<ans<<'\n';
	return;
}

/*
1
7 6
1 6 2 5 3 4 4 3 5 2 6 1
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}