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
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e18;

bitset<maxn> mark , ch;
vector<ll> adj[maxn] , ans;
ll cnt = 0;

void DFS(ll r){
	cnt++;
	mark[r] = true;
	if(ch[r]){
		for(auto i : adj[r]){
			ch[i] = false;
		}
		ans.push_back(r);
		ch[r] = false;
	}
	for(auto i : adj[r]){
		if(mark[i]) continue;
		DFS(i);
	}
	return;
}



void solve(){
	ll n , m;
	cin>>n>>m;
	ans.clear(); cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		mark[i] = false;
		ch[i] = true;
		adj[i].clear();
	}
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	DFS(0);
	if(cnt < n){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n"<<ans.size()<<'\n';
	for(auto i : ans){
		cout<<i + 1<<' ';
	}
	cout<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}