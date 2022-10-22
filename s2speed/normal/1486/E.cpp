#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const int MAXN = 1e5 + 15 , md = 1e9 + 7;
int inf;

vector<pii> adj[MAXN * 51];
int dis[MAXN * 51];
bitset<MAXN * 51> mark;
priority_queue<pii , vector<pii> , greater<pii> > pq;

void dij(){
	dis[0] = 0;
	pq.push({0 , 0});
	while(!pq.empty()){
		pii p = pq.top(); pq.pop();
		int v = p.second;
		if(mark[v]) continue;
		for(auto q : adj[v]){
			int i = q.first , w = q.second;
			if(mark[i]) continue;
			if(dis[i] > dis[v] + w){
				dis[i] = dis[v] + w;
				pq.push({dis[i] , i});
			}
		}
		mark[v] = true;
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dis , 63 , sizeof(dis));
	inf = dis[0];
	int n , m;
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		int v , u , w;
		cin>>v>>u>>w; v--; u--;
		adj[v].push_back({w * n + u , w * w});
		adj[u].push_back({w * n + v , w * w});
		for(int j = 1 ; j <= 50 ; j++){
			adj[j * n + v].push_back({u , w * w + 2 * j * w});
			adj[j * n + u].push_back({v , w * w + 2 * j * w});
		}
	}
	dij();
	for(int i = 0 ; i < n ; i++){
		cout<<(dis[i] == inf ? -1 : dis[i])<<' ';
	}
	cout<<'\n';
	return 0;
}

/*

*/