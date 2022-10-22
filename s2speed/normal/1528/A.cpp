#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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

ll dp[maxn][2] , l[maxn] , r[maxn];
vector<ll> adj[maxn];

void DFS(ll v , ll par){
	for(auto i : adj[v]){
		if(i == par) continue;
		DFS(i , v);
		dp[v][0] += max(dp[i][0] + abs(l[v] - l[i]) , dp[i][1] + abs(l[v] - r[i]));
		dp[v][1] += max(dp[i][0] + abs(r[v] - l[i]) , dp[i][1] + abs(r[v] - r[i]));
	}
	return;
}

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>l[i]>>r[i];
		dp[i][0] = dp[i][1] = 0;
		adj[i].clear();
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	DFS(0 , -1);
	cout<<max(dp[0][0] , dp[0][1])<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}