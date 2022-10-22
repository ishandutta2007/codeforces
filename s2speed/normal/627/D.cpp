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

ll n , k;
ll dp[maxn] , pd[maxn] , res[maxn] , par[maxn] , mi[maxn] , a[maxn];
vector<ll> adj[maxn];
ll z[maxn] , c[maxn] , cnt;
bitset<maxn> b;

void aDFS(ll r){
	z[r] = 1;
	c[r] = b[r];
	for(auto i : adj[r]){
		if(i == par[r]) continue;
		par[i] = r;
		aDFS(i);
		z[r] += z[i];
		c[r] += c[i];
	}
	if(z[r] == c[r]){
		dp[r] = z[r];
		return;
	}
	if(!b[r]){
		dp[r] = 0;
		return;
	}
	dp[r] = 1;
	ll m = -1 , ind = -1;
	for(auto i : adj[r]){
		if(i == par[r]) continue;
		if(z[i] == c[i]){
			dp[r] += z[i];
			continue;
		}
		if(dp[i] > m){
			m = dp[i];
			ind = i;
		}
	}
	dp[r] += m;
	mi[r] = ind;
	return;
}

void bDFS(ll r){
	if(par[r] == -1){
		pd[r] = 0;
		res[r] = dp[r];
		for(auto i : adj[r]){
			bDFS(i);
		}
		return;
	}
	if(!b[r]){
		res[r] = pd[r] = 0;
		for(auto i : adj[r]){
			if(i == par[r]) continue;
			bDFS(i);
		}
		return;
	}
	if(z[r] == c[r]){
		res[r] = (b[par[r]] ? res[par[r]] : dp[r]);
		return;
	}
	if(mi[par[r]] != r){
		pd[r] = res[par[r]];
	} else {
		ll m = (z[par[r]] - c[par[r]] != cnt ? pd[par[r]] : 0);
		for(auto i : adj[par[r]]){
			if(i == par[par[r]]) continue;
			if(z[i] == c[i]) continue;
			if(i == r) continue;
			m = max(m , dp[i]);
		}
		pd[r] = res[par[r]] - dp[r] + m;
	}
	ll m = pd[r] , ind = -1;
	res[r] = 1;
	if(z[r] - c[r] == cnt){
		m = 0;
		res[r] += n - z[r];
	}
	for(auto i : adj[r]){
		if(i == par[r]) continue;
		if(z[i] == c[i]){
			res[r] += z[i];
			continue;
		}
		if(dp[i] > m){
			m = dp[i];
			ind = i;
		}
	}
	mi[r] = ind;
	res[r] += m;
	for(auto i : adj[r]){
		if(i == par[r]) continue;
		bDFS(i);
	}
	return;
}

bool check(ll x){
	memset(mi , -1 , sizeof(mi));
	memset(res , -1 , sizeof(res));
	cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		b[i] = (a[i] >= x);
		cnt += !b[i];
	}
	aDFS(0);
	bDFS(0);
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++) ans = max(ans , res[i]);
//	for(ll i = 0 ; i < n ; i++) cout<<res[i]<<' ';
	return (ans >= k);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	par[0] = -1;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	ll l = 0 , r = 1e6 + 1;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(m)){
			l = m;
		} else {
			r = m;
		}
	}
	cout<<l<<'\n';
//	check(2);
	return 0;
}

/*
9 7
2 2 2 2 2 2 2 1 1
1 2
1 3
2 4
2 5
3 6
3 7
6 8
7 9
*/