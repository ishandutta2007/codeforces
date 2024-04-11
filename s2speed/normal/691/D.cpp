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

const ll MAX_N = 1e6 + 20 , md = 1e9 + 7;
 
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

string ist(int r){
	bool neg = false;
	string h;
	if(r < 0){
		neg = true;
		r -= 2 * r;
	}
	while(r > 0){
		h += '0' + r % 10;
		r /= 10;
	}
	if(neg) h += '-';
	reverse(all(h));
	return h;
}

int ans[MAX_N] , a[MAX_N];
vector<int> val , ind , adj[MAX_N];
bool mark[MAX_N];

void DFS(int r){
	val.push_back(a[r]);
	ind.push_back(r);
	mark[r] = true;
	for(auto i : adj[r]){
		if(mark[i]) continue;
		DFS(i);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n , m;
	cin>>n>>m;
	memset(mark , 0 , sizeof(mark));
	for(int i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(int i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		DFS(i);
		sort(all(val) , greater<ll>());
		sort(all(ind));
		int lm = val.size();
		for(int j = 0 ; j < lm ; j++){
			ans[ind[j]] = val[j];
		}
		ind.clear();
		val.clear();
	}
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i] + 1<<' ';
	}
	cout<<'\n';
	return 0;
}

/*
*/