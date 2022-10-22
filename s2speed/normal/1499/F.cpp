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

const ll maxn = 5e3 + 16 , md = 998244353 , inf = 2e18;

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

ll dv(ll a , ll b){
	return 1ll * a * tav(b , md - 2) % md;
}

int16_t n , k , l;
int dp[maxn][maxn], h[maxn / 2][maxn] , g[maxn / 2][maxn] , pd[maxn];
ll sum[maxn];
vector<int16_t> adj[maxn];

void DFS(ll r , ll par){
	ll cnt = 0;
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
		cnt++;
	}
	if(cnt == 0){
		dp[r][0] = 1;
		sum[r] = 1;
		return;
	}
	ll o = 1 , as = adj[r].size();
	for(ll j = 0 ; j <= l ; j++){
		for(auto i : adj[r]){
			if(i == par) continue;
			if(j == 0){
				pd[i] = sum[i];
			} else {
				pd[i] += dp[i][j - 1];
				if(pd[i] > md) pd[i] -= md;
			}
		}
		for(ll e = 0 ; e < as ; e++){
			ll i = adj[r][e];
			if(i == par){
				if(e == 0){
					h[j][0] = 1;
				} else {
					h[j][e] = h[j][e - 1];
				}
				continue;
			}
			if(e == 0){
				h[j][0] = pd[i];
				continue;
			}
			h[j][e] = 1ll * pd[i] * h[j][e - 1] % md;
		}
		for(ll e = as - 1 ; e >= 0 ; e--){
			ll i = adj[r][e];
			if(i == par){
				if(e == as - 1){
					g[j][as - 1] = 1;
				} else {
					g[j][e] = g[j][e + 1];
				}
				continue;
			}
			if(e == as - 1){
				g[j][e] = pd[i];
				continue;
			}
			g[j][e] = 1ll * pd[i] * g[j][e + 1] % md;
		}
		dp[r][j] = h[j][as - 1];
		if(j > 0){
			dp[r][j] -= h[j - 1][as - 1];
			if(dp[r][j] < 0) dp[r][j] += md;
		}
		sum[r] += dp[r][j];
	}
	for(ll j = l + 1 ; j <= k ; j++){
		for(ll e = 0 ; e < as ; e++){
			ll i = adj[r][e];
			if(i == par) continue;
			o = dp[i][j - 1];
			if(e > 0){
				o *= h[k - j][e - 1]; o %= md;
			}
			if(e < as - 1){
				o *= g[k - j][e + 1]; o %= md;
			}
			dp[r][j] += o;
			if(dp[r][j] >= md) dp[r][j] -= md;
		}
		sum[r] += dp[r][j];
	}
	sum[r] %= md;
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp)); memset(pd , 0 , sizeof(pd));
	cin>>n>>k; l = k / 2;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	DFS(0 , -1);
	ll ans = 0;
	for(ll i = 0 ; i <= k ; i++){
		ans += dp[0][i];
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}