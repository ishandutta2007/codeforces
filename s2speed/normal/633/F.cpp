#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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

ll n;
ll a[maxn] , dp[maxn][6];
vector<ll> adj[maxn];

void dDFS(ll r , ll par){
	for(auto i : adj[r]){
		if(i == par) continue;
		dDFS(i , r);
	}
	dp[r][0] = dp[r][2] = a[r];
	for(auto i : adj[r]){
		if(i == par) continue;

		dp[r][5] = max(max(max(dp[r][5] , dp[i][5]) , dp[r][2] + dp[i][2]) , max(dp[r][3] + dp[i][0] , dp[r][0] + dp[i][3]));
		dp[r][4] = max(max(dp[r][4] , dp[i][5]) , dp[r][1] + dp[i][2]);
		dp[r][3] = max(max(dp[r][3] , dp[i][3] + a[r]) , max(dp[r][1] + dp[i][0] + a[r] , dp[r][0] + dp[i][2]));
		dp[r][2] = max(max(dp[r][2] , dp[i][2]) , dp[r][0] + dp[i][0]);
		dp[r][1] = max(dp[r][1] , dp[i][2]);
		dp[r][0] = max(dp[r][0] , dp[i][0] + a[r]);

		dp[r][2] = max(dp[r][2] , max(dp[r][0] , dp[r][1]));
		dp[r][5] = max(dp[r][5] , max(dp[r][3] , dp[r][4]));
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , -15 , sizeof(dp));
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	dDFS(0 , -1);
	cout<<dp[0][5]<<'\n';
//	for(ll i = 0 ; i < n ; i++){
//		for(ll j = 0 ; j < 6 ; j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	return 0;
}