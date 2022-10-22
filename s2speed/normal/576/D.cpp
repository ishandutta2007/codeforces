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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;

const ll MAXN = 150 + 2 , md = 1e9 + 7 , inf = 1e16;
// check problem statement

ll n , m , tme , ans = inf , dis[MAXN];
bool a[MAXN][MAXN] , p[MAXN][MAXN] , has[MAXN][MAXN] , res[MAXN][MAXN] , cur[MAXN][MAXN];
vector<ll> adj[MAXN] , v;
vector<plll> ed;

void mul(bool b[MAXN][MAXN] , bool c[MAXN][MAXN]){
	bitset<MAXN> z[MAXN] , x[MAXN];
	memset(has , 0 , sizeof(has));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			z[i][j] = b[i][j] , x[j][i] = c[i][j];
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			bitset<MAXN> y = z[i] & x[j];
			has[i][j] = y.any();
		}
	}
	return;
}

void tav(ll k){
	memset(res , 0 , sizeof(res));
	for(int i = 0 ; i < n ; i++){
		res[i][i] = 1;
	}
	while(k > 0){
		if(k & 1){
			mul(p , res);
			memcpy(res , has , sizeof(has));
		}
		mul(p , p);
		memcpy(p , has , sizeof(has));
		k /= 2;
	}
	return;
}

void BFS(){
	fill(dis , dis + n , inf);
	for(int i = 0 ; i < n ; i++){
		if(cur[0][i]){
			v.push_back(i);
			dis[i] = tme;
		}
	}
	ll x = 0;
	while(x < v.size()){
		ll u = v[x];
		for(auto i : adj[u]){
			if(dis[i] > dis[u] + 1){
				dis[i] = dis[u] + 1;
				v.push_back(i);
			}
		}
		x++;
	}
	ans = min(ans , dis[n - 1]);
	v.clear();
	return;
}


int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(a , 0 , sizeof(a));
	memset(cur , 0 , sizeof(cur)); cur[0][0] = 1;
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		ll v , u , d;
		cin>>v>>u>>d; v--; u--;
		ed.push_back({d , {v , u}});
	}
	sort(all(ed));
	for(int i = 0 ; i < m ; i++){
		ll d = ed[i].first , v = ed[i].second.first , u = ed[i].second.second;
		memcpy(p , a , sizeof(a));
		tav(d - tme);
		tme = d;
		a[v][u] = 1;
		adj[v].push_back(u);
		mul(cur , res); memcpy(cur , has , sizeof(has));
		BFS();
	}
//	for(int i = 0 ; i < n ; i++){
//		for(int j = 0 ; j < n ; j++){
//			cout<<cur[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	if(ans == inf){
		cout<<"Impossible\n";
	} else {
		cout<<ans<<'\n';
	}
	return 0;
}

/*

*/