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

const ll MAXN = 2e5 + 20 , md = 2000000357 , inf = 2e9 + 1;
// check problem statement

bitset<MAXN> mark;
vector<ll> v , adj[MAXN];

void DFS(ll r){
	mark[r] = true;
	for(auto i : adj[r]){
		if(mark[i]) continue;
		DFS(i);
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , o;
	cin>>n>>m;
	o = n * m / gcd(n , m);
	ll k;
	cin>>k;
	for(ll i = 0 ; i < k ; i++){
		ll h;
		cin>>h;
		v.push_back(h);
	}
	cin>>k;
	for(ll i = 0 ; i < k ; i++){
		ll h;
		cin>>h;
		v.push_back(h + n);
	}
	for(ll i = 0 ; i < o ; i++){
		ll v = i % n , u = i % m + n;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(auto i : v){
		if(mark[i]) continue;
		DFS(i);
	}
	cout<<(mark.count() == n + m ? "Yes\n" : "No\n");
	return 0;
}

/*

*/