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

const ll MAX_N = 1e3 + 20 , MAX_NN = 1e6 + 20 , md = 1e9 + 7;
 
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

string s[MAX_N];
vector<int> adj[MAX_NN];
int dis[MAX_NN][3];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		cin>>s[i];
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(s[i][j] == '#') continue;
			int v = i * m + j;
			if(i < n - 1){
				if(s[i + 1][j] != '#'){
					adj[v].push_back(v + m); adj[v + m].push_back(v);
				}
			}
			if(j < m - 1){
				if(s[i][j + 1] != '#'){
					adj[v].push_back(v + 1); adj[v + 1].push_back(v);
				}
			}
		}
	}
	memset(dis , 63 , sizeof(dis));
	vector<int> bfs;
	for(int e = 0 ; e < 3 ; e++){
		bfs.clear();
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(s[i][j] != '1' + e) continue;
				bfs.push_back(i * m + j);
				dis[i * m + j][e] = 0;
			}
		}
		int x = 0;
		while(x < bfs.size()){
			int v = bfs[x++];
			for(auto u : adj[v]){
				if(dis[u][e] > dis[v][e] + 1){
					bfs.push_back(u);
					dis[u][e] = dis[v][e] + 1;
				}
			}
		}
		int m1 = 1e9 , m2 = 1e9 , m3 = 1e9;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				int v = i * m + j;
				dis[v][e] = max(0 , dis[v][e] - 1);
				if(s[i][j] == '1'){
					m1 = min(m1 , dis[v][e]);
				}
				if(s[i][j] == '2'){
					m2 = min(m2 , dis[v][e]);
				}
				if(s[i][j] == '3'){
					m3 = min(m3 , dis[v][e]);
				}
			}
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				int v = i * m + j;
				if(s[i][j] == '1'){
					dis[v][e] = m1;
				}
				if(s[i][j] == '2'){
					dis[v][e] = m2;
				}
				if(s[i][j] == '3'){
					dis[v][e] = m3;
				}
			}
		}
	}
	int ans = 1e8 , lm = n * m;
	for(int v = 0 ; v < lm ; v++){
		int i = v / m , j = v % m;
		if(dis[v][0] > lm || dis[v][1] > lm || dis[v][2] > lm) continue; 
		ans = min(ans , dis[v][0] + dis[v][1] + dis[v][2] + (s[i][j] == '.'));
	}
	cout<<(ans == 1e8 ? -1 : ans)<<'\n';
	return 0;
}

/*
1 5
1.2.3
*/