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

const ll MAXN = 50 + 15 , md = 1e9 + 7;

char a[MAXN][MAXN];
vector<ll> adj[MAXN * MAXN] , v;
bitset<MAXN * MAXN> mark;
ll n , m;

void BFS(){
	v.clear();
	mark[n * m - 1] = true;
	v.push_back(n * m - 1);
	ll x = 0;
	while(x < v.size()){
		ll r = v[x];
		for(auto i : adj[r]){
			if(mark[i]) continue;
			mark[i] = true;
			v.push_back(i);
		}
		x++;
	}
	return;
}

void solve(){
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			cin>>a[i][j];
			adj[i * m + j].clear();
			mark[i * m + j] = false;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			if(a[i][j] == 'B'){
				if(i > 0){
					if(a[i - 1][j] == 'G'){
						cout<<"No\n";
						return;
					}
					if(a[i - 1][j] != 'B'){
						a[i - 1][j] = '#';
					}
				}
				if(i < n - 1){
					if(a[i + 1][j] == 'G'){
						cout<<"No\n";
						return;
					}
					if(a[i + 1][j] != 'B'){
						a[i + 1][j] = '#';
					}
				}
				if(j > 0){
					if(a[i][j - 1] == 'G'){
						cout<<"No\n";
						return;
					}
					if(a[i][j - 1] != 'B'){
						a[i][j - 1] = '#';
					}
				}
				if(j < m - 1){
					if(a[i][j + 1] == 'G'){
						cout<<"No\n";
						return;
					}
					if(a[i][j + 1] != 'B'){
						a[i][j + 1] = '#';
					}
				}
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			if(a[i][j] == '#') continue;
			ll v = i * m + j;
			if(i > 0){
				if(a[i - 1][j] != '#'){
					adj[v].push_back(v - m); adj[v - m].push_back(v);
				}
			}
			if(j > 0){
				if(a[i][j - 1] != '#'){
					adj[v].push_back(v - 1); adj[v - 1].push_back(v);
				}
			}
		}
	}
	BFS();
	ll v = 0;
	bool ans = true;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			if(a[i][j] == 'G'){
				ans &= mark[v];
			}
			v++;
		}
	}
	cout<<(ans ? "Yes\n" : "No\n");
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/