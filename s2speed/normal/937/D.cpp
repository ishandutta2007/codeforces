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

const ll MAX_N = 1e5 + 20 , md = 1e9 + 7 , inf = 1e17;
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

vector<ll> adj[MAX_N] , path;
bool mark[MAX_N][2] , ret = false , cy = false;
set<ll> s;

void DFS(ll r , bool zoj){
	path.push_back(r);
	s.insert(r);
	if(adj[r].size() == 0 && zoj == 1){
		ret = true;
		return;
	}
	bool ne = 1 - zoj;
	mark[r][zoj] = true;
	for(auto i : adj[r]){
		if(s.count(i)) cy = true;
		if(mark[i][ne]) continue;
		DFS(i , ne);
		if(ret) return;
	}
	path.pop_back();
	s.erase(r);
	return;
}

int main(){ // check MAX_N
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m;
	cin>>n>>m;
	memset(mark , 0 , sizeof(mark));
	for(int i = 0 ; i < n ; i++){
		ll k;
		cin>>k;
		for(int j = 0 ; j < k ; j++){
			ll v;
			cin>>v; v--;
			adj[i].push_back(v);
		}
	}
	ll st;
	cin>>st; st--;
	DFS(st , 0);
	if(!ret){
		cout<<(cy ? "Draw\n" : "Lose\n");
		return 0;
	}
	cout<<"Win\n";
	ll ans = path.size();
	for(int i = 0 ; i < ans ; i++){
		cout<<path[i] + 1<<' ';
	}
	cout<<'\n';
	return 0;
}

/*

*/