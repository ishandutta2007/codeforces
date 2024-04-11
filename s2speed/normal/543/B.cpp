#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 3000 + 20 , MAX_NN = 250000 + 20 , md = 1e9 + 7 , inf = 1e17;
// check problem statement

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

vector<ll> adj[MAX_N] , bfs;
ll dis[MAX_N][MAX_N];

void BFS(ll r){
	bfs.push_back(r);
	dis[r][r] = 0;
	ll x = 0;
	while(x < bfs.size()){
		ll v = bfs[x];
		for(auto i : adj[v]){
			if(dis[i][r] > dis[v][r] + 1){
				dis[i][r] = dis[v][r] + 1;
				bfs.push_back(i);
			}
		}
		x++;
	}
	bfs.clear();
	return;
}

int main(){ // check MAX_N
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m , s1 , s2 , t1 , t2 , l1 , l2 , ans;
	cin>>n>>m;
	memset(dis , 63 , sizeof(dis));
	for(int i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	cin>>s1>>t1>>l1>>s2>>t2>>l2; s1--; s2--; t1--; t2--;
	for(int i = 0 ; i < n ; i++){
		BFS(i);
	}
	ans = dis[s1][t1] + dis[s2][t2];
	if(dis[s1][t1] > l1 || dis[s2][t2] > l2){
		cout<<"-1\n";
		return 0;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			ll a = dis[s1][i] , b = dis[s2][i] , c = dis[i][j] , d = dis[t1][j] , e = dis[t2][j];
			if(a + c + d <= l1 && b + c + e <= l2){
				ans = min(ans , a + b + c + d + e);
			}
			b = dis[t2][i]; e = dis[s2][j];
			if(a + c + d <= l1 && b + c + e <= l2){
				ans = min(ans , a + b + c + d + e);
			}
		}
	}
	cout<<m - ans<<'\n';
	return 0;
}

/*

*/