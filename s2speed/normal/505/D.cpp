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

const ll MAXN = 1e5 + 2 , md = 1e9 + 7 , inf = 1e16;
// check problem statement

ll cnt;
vector<ll> adj[MAXN] , jda[MAXN] , ajd[MAXN] , c;
set<ll> s;
bitset<MAXN> mark , mrk;
bool ch;

void DFS(ll r){
	mrk[r] = true;
	c.push_back(r);
	for(auto i : ajd[r]){
		if(mrk[i]) continue;
		DFS(i);
	}
	return;
}

void DFS1(ll r){
	mark[r] = true;
	s.insert(r);
	for(auto i : adj[r]){
		if(s.count(i)){
			ch = false;
			continue;
		}
		if(mark[i]) continue;
		DFS1(i);
	}
	s.erase(r);
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m , ans;
	cin>>n>>m; ans = n;
	for(int i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); jda[u].push_back(v);
		ajd[v].push_back(u); ajd[u].push_back(v);
	}
	for(int i = 0 ; i < n ; i++){
		if(mrk[i]){
			continue;
		}
		DFS(i);
		ch = true;
		int cs = c.size();
		for(int j = 0 ; j < cs ; j++){
			if(mark[c[j]]) continue;
			DFS1(c[j]);
		}
		ans -= ch;
		c.clear();
	}
	cout<<ans<<'\n';
	return 0;
}

/*
6 5
1 2
1 3
4 1
4 5
4 6
*/