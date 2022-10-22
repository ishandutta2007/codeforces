#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e2 + 16 , md = 1e9 + 7 , inf = 2e18;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

ll dp[maxn][maxn] , pd[maxn][maxn] , p[maxn];
vector<pll> adj[maxn * maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(pd , 0 , sizeof(pd));
	memset(dp , 63 , sizeof(dp));
	ll n , m , k;
	cin>>n>>m>>k;
	if(k & 1){
		for(ll i = 0 ; i < n ; i++){
			for(ll j = 0 ; j < m ; j++){
				cout<<"-1 ";
			}
			cout<<'\n';
		}
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		ll v = i * m;
		for(ll j = 0 ; j < m - 1 ; j++){
			ll h;
			cin>>h;
			adj[v].push_back({v + 1 , h});
			adj[v + 1].push_back({v , h});
			v++;
		}
	}
	for(ll i = 0 ; i < n - 1 ; i++){
		ll v = i * m;
		for(ll j = 0 ; j < m ; j++){
			ll h;
			cin>>h;
			adj[v].push_back({v + m , h});
			adj[v + m].push_back({v , h});
			v++;
		}
	}
	k >>= 1;
	for(ll e = 1 ; e <= k ; e++){
		for(ll i = 0 ; i < n ; i++){
			for(ll j = 0 ; j < m ; j++){
				ll v = i * m + j;
				for(auto p : adj[v]){
					ll w = p.second , u = p.first;
					dp[i][j] = min(dp[i][j] , pd[u / m][u % m] + 2ll * w);
				}
			}
		}
		memcpy(pd , dp , sizeof(dp));
		memset(dp , 63 , sizeof(dp));
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			cout<<pd[i][j]<<' ';
			}
		cout<<'\n';
	}
	return 0;
}