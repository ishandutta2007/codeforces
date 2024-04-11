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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

ll fact[maxn] , _fact[maxn];

void fact_build(){
	fact[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		fact[i] = fact[i - 1] * i % md;
	}
	_fact[maxn - 1] = tav(fact[maxn - 1] , md - 2);
	for(ll i = maxn - 2 ; ~i ; i--){
		_fact[i] = _fact[i + 1] * (i + 1) % md;
	}
	return;
}

ll chs(ll n , ll k){
	if(k < 0 || k > n) return 0;
	return fact[n] * _fact[k] % md * _fact[n - k] % md;
}

ll n , k;
vector<ll> adj[maxn];
ll z[maxn] , pd[maxn] , dp[maxn] , cur = 0 , ans = 0;

void pDFS(ll r , ll par){
	z[r] = 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		pDFS(i , r);
		z[r] += z[i];
		pd[r] += chs(z[i] , k);
	}
	pd[r] %= md;
	dp[r] = chs(z[r] , k) - pd[r];
	cur += dp[r] * z[r] % md;
	return;
}

void reroot(ll v , ll u){
	cur -= dp[v] * z[v] % md;
	pd[v] -= chs(z[u] , k); pd[v] %= md;
	z[v] -= z[u];
	dp[v] = chs(z[v] , k) - pd[v];
	cur += dp[v] * z[v] % md;
//	--------------------------------------
	cur -= dp[u] * z[u] % md;
	pd[u] += chs(z[v] , k); pd[u] %= md;
	z[u] = n;
	dp[u] = chs(z[u] , k) - pd[u];
	cur += dp[u] * z[u] % md;
	return;
}

void rDFS(ll r , ll par){
	ans += cur; ans %= md;
	for(auto i : adj[r]){
		if(i == par) continue;
		reroot(r , i);
		rDFS(i , r);
		reroot(i , r);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact_build();
	cin>>n>>k;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	pDFS(0 , -1);
	rDFS(0 , -1);
	ans += (ans < 0) * md;
	cout<<ans<<'\n';
	return 0;
}