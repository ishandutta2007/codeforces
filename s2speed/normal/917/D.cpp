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
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 112 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn][maxn][maxn] , z[maxn] , pd[maxn][maxn] , f[maxn] , ans[maxn];
vector<ll> adj[maxn];

void DFS(ll r , ll par){
	z[r] = 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
	}
	dp[r][0][1] = 1;
	for(auto v : adj[r]){
		if(v == par) continue;
		memset(pd , 0 , sizeof(pd));
		for(ll i = 0 ; i < z[r] ; i++){
			for(ll s = 1 ; s <= i + 1 ; s++){
				for(ll j = 0 ; j < z[v] ; j++){
					for(ll k = 1 ; k <= j + 1 ; k++){
						ll h = dp[v][j][k] * dp[r][i][s];
						pd[i + j + 1][s + k] += h; pd[i + j][s + k] %= md;
						h = dp[v][j][k] * k % md * dp[r][i][s];
						pd[i + j][s] += h; pd[i + j][s] %= md;
					}
				}
			}
		}
		memcpy(dp[r] , pd , sizeof(pd));
		z[r] += z[v];
	}
	return;
}

ll chs[maxn][maxn] , tv[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	chs[0][0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		chs[i][0] = 1;
		for(ll j = 1 ; j <= i ; j++){
			chs[i][j] = chs[i - 1][j - 1] + chs[i - 1][j]; chs[i][j] -= (chs[i][j] >= md) * md;
		}
	}
	ll n;
	cin>>n;
	ll dv = tav(n , md - 2);
	tv[0] = tav(n , n - 2);
	for(ll i = 1 ; i < n ; i++){
		tv[i] = tv[i - 1] * dv % md;
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	DFS(0 , -1);
	for(ll i = 0 ; i < n ; i++){
		for(ll k = 1 ; k <= i + 1 ; k++){
			f[i] += dp[0][i][k] * k;
		}
		f[i] %= md;
		f[i] *= tv[i]; f[i] %= md;
//		cout<<f[i]<<' ';
	}
	for(ll i = n - 1 ; ~i ; i--){
		ll h = 0;
		for(ll j = n - 1 ; j > i ; j--){
			h += chs[j][i] * ans[j] % md;
		}
		h %= md;
		ans[i] = f[i] - h; ans[i] += (ans[i] < 0) * md;
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}