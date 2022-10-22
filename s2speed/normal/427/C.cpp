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

vector<ll> adj[MAXN] , jda[MAXN] , f , sc;
ll a[MAXN];
bitset<MAXN> mark;

void DFS1(ll r){
	mark[r] = true;
	for(auto i : adj[r]){
		if(mark[i]) continue;
		DFS1(i);
	}
	f.push_back(r);
	return;
}

void DFS2(ll r){
	mark[r] = true;
	sc.push_back(r);
	for(auto i : jda[r]){
		if(mark[i]) continue;
		DFS2(i);
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m , ans = 1 , sum = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); jda[u].push_back(v);
	}
	for(int i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		DFS1(i);
	}
	reverse(all(f));
	mark.flip();
	for(int i = 0 ; i < n ; i++){
		if(mark[f[i]]) continue;
		ll mn = inf , cnt;
		DFS2(f[i]);
		for(auto v : sc){
			if(a[v] == mn){
				cnt++;
			}
			if(a[v] < mn){
				mn = a[v];
				cnt = 1;
			}
		}
		ans *= cnt; ans %= md;
		sum += mn;
		sc.clear();
	}
	cout<<sum<<' '<<ans<<'\n';
	return 0;
}

/*

*/