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

const ll maxn = 2e2 + 16 , md = 1e9 + 7 , inf = 2e17;

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

vector<ll> adj[maxn];
ll dis[maxn][maxn] , dep = 0;

void DFS(ll r , ll par , ll v){
	dis[v][r] = dep++;
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r , v);
	}
	dep--;
	return;
}

ll t[maxn] , o = tav(2 , md - 2) , ch[maxn][maxn] , dp[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(ch , 0 , sizeof(ch));
	memset(dp , 0 , sizeof(dp));
	ll n;
	cin>>n;
	t[0] = 1;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
		t[i] = 1ll * t[i - 1] * o; t[i] %= md;
	}
	for(ll i = 0 ; i < n ; i++){
		DFS(i , -1 , i);
	}
	ch[0][0] = 1;
	for(ll i = 1 ; i < n ; i++){
		ch[i][0] = 1;
		for(ll j = 1 ; j <= i ; j++){
			ch[i][j] = ch[i - 1][j - 1] + ch[i - 1][j];
			if(ch[i][j] >= md) ch[i][j] -= md;
		}
	}
	for(ll i = 1 ; i < n ; i++){
		dp[0][i] = 1;
	}
	for(ll i = 1 ; i < n ; i++){
		dp[i][0] = 0;
		for(ll j = 1 ; j < n ; j++){
			db h = 1ll * ch[i + j - 2][j - 1] * t[i + j - 1] % md;
			dp[i][j] = dp[i][j - 1] + h; if(dp[i][j] >= md) dp[i][j] -= md;
		}
	}
	ll ans = 0;
	for(ll k = 0 ; k < n ; k++){
		for(ll i = 0 ; i < n ; i++){
			for(ll j = i + 1 ; j < n ; j++){
				if(dis[i][k] == dis[j][k] + dis[i][j]){
					ans++;
					continue;
				}
				if(dis[j][k] == dis[i][k] + dis[i][j]){
					continue;
				}
				ll l = (dis[i][k] + dis[j][k] - dis[i][j]) / 2;
				ans += dp[dis[j][k] - l][dis[i][k] - l];
				if(ans >= md) ans -= md;
			}
		}
	}
	ans %= md;
	ans = 1ll * ans * tav(n , md - 2) % md;
	cout<<ans<<'\n';
	return 0;
}