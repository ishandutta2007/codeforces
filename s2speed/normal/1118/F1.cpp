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

const ll maxn = 6e5 + 17 , md = 998244353 , inf = 2e16;

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

ll n , k;
vector<ll> adj[maxn] , cdj[maxn];
ll a[maxn] , z[maxn] , c[maxn] , dp[maxn][2] , cnt[maxn] , lb[maxn];
bool g = true;

void zDFS(ll r , ll par){
	if(a[r] != -1){
		z[r] = 1; c[r] = a[r];
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		zDFS(i , r);
		if(z[i] == 0) continue;
		if(c[r] == -1){
			c[r] = c[i];
			z[r] = z[i];
		} else {
			if(c[i] != c[r]){
				g = false;
				return;
			}
			z[r] += z[i];
		}
	}
	if(c[r] != -1){
		if(z[r] == cnt[c[r]]){
			z[r] = 0;
		}
	}
	return;
}

void cDFS(ll r , ll par){
	for(auto i : cdj[r]){
		if(i == par) continue;
		cDFS(i , r);
	}
	if(r >= n){
		ll h = 1;
		for(auto i : cdj[r]){
			if(i == par) continue;
			h *= dp[i][0]; h %= md;
		}
		dp[r][1] = dp[r][0] = h;
	} else {
		ll z = 1 , h = 0;
		for(auto i : cdj[r]){
			if(i == par) continue;
			z *= dp[i][0]; z %= md;
		}
		for(auto i : cdj[r]){
			if(i == par) continue;
			ll o = dp[i][1] * tav(dp[i][0] , md - 2) % md * z % md;
			h += o;
		}
		h %= md;
		dp[r][1] = h;
		h += z; h -= (h >= md) * md;
		dp[r][0] = h;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(c , -1 , sizeof(c));
	cin>>n; k = 2;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		if(a[i] != -1) cnt[a[i]]++;
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	zDFS(0 , -1);
	if(!g){
		cout<<"0\n";
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		if(c[i] == -1){
			lb[i] = i;
		} else {
			lb[i] = c[i] + n;
		}
	}
	for(ll v = 0 ; v < n ; v++){
		for(auto i : adj[v]){
			if(i < v) continue;
			if(lb[i] == lb[v]) continue;
			cdj[lb[i]].push_back(lb[v]); cdj[lb[v]].push_back(lb[i]);
		}
	}
	cDFS(lb[0] , -1);
	cout<<dp[lb[0]][1]<<'\n';
	return 0;
}