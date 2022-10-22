#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1e5 + 1;

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

vector<ll> adj[MAX_N];
ll dis[MAX_N];
queue<ll> q;
ll n;

ll gh(){
	ll ans , r;
	for(int i = 2 ; i <= n ; i++){
		dis[i] = 1e9;
	}
	dis[1] = 0;
	q.push(1);
	while(q.size() > 0){
		ll f = q.front() , fs = adj[f].size();
		q.pop();
		for(int i = 0 ; i < fs ; i++){
			if(dis[adj[f][i]] > dis[f] + 1){
				q.push(adj[f][i]);
				dis[adj[f][i]] = dis[f] + 1;
			}
		}
		if(q.size() == 0){
			r = f;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		dis[i] = 1e9;
	}
	dis[r] = 0;
	q.push(r);
	while(q.size() > 0){
		ll f = q.front() , fs = adj[f].size();
		q.pop();
		for(int i = 0 ; i < fs ; i++){
			if(dis[adj[f][i]] > dis[f] + 1){
				q.push(adj[f][i]);
				dis[adj[f][i]] = dis[f] + 1;
			}
		}
		if(q.size() == 0){
			ans = f;
		}
	}
	return dis[ans];
}

void BFS(ll r){
	for(int i = 1 ; i <= n ; i++){
		dis[i] = 1e9;
	}
	dis[r] = 0;
	q.push(r);
	while(q.size() > 0){
		ll f = q.front() , fs = adj[f].size();
		q.pop();
		for(int i = 0 ; i < fs ; i++){
			if(dis[adj[f][i]] > dis[f] + 1){
				q.push(adj[f][i]);
				dis[adj[f][i]] = dis[f] + 1;
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll u , v , a , b , da , db;
		cin>>n>>a>>b>>da>>db;
		for(int i = 1 ; i < n ; i++){
			cin>>u>>v;
			adj[u].push_back(v); adj[v].push_back(u);
		}
		db = min(db , gh());
		if(db > da * 2){
			BFS(a);
			if(dis[b] > da){
				cout<<"Bob\n";
			} else {
				cout<<"Alice\n";
			}
		} else {
			cout<<"Alice\n";
		}
		for(int i = 1 ; i <= n ; i++){
			adj[i].clear();
		}
	}
	return 0;
}