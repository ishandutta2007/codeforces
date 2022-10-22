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

const ll MAXN = 2e5 + 15 , md = 998244353 , inf = 1e15;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

unordered_map<ll , ll , custom_hash> t;

ll dv(ll p , ll q){
	if(!t.count(q)){
		t[q] = tav(q , md - 2);
	}
	ll res = 1ll * p * t[q] % md;
	return res;
}

vector<ll> adj[MAXN];
ll dp[MAXN][3];

void DFS(ll r){
	for(auto i : adj[r]){
		DFS(i);
	}
	if(adj[r].empty()){
		dp[r][2] = 1;
		return;
	}
	dp[r][0] = 1; dp[r][2] = 1;
	for(auto i : adj[r]){
		dp[r][0] *= (dp[i][2] + dp[i][0]); dp[r][0] %= md;
		ll h = 2ll * dp[i][2] + dp[i][0] + dp[i][1]; h %= md;
		dp[r][2] *= h; dp[r][2] %= md;
	}
	for(auto i : adj[r]){
		ll h = dv(dp[r][0] , (dp[i][0] + dp[i][2]) % md);
		h = 1ll * h * (dp[i][1] + dp[i][2]) % md;
		dp[r][1] += h;
	}
	dp[r][1] %= md;
	dp[r][2] -= dp[r][0] + dp[r][1] - 2ll * md; dp[r][2] %= md;
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	ll n;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll p;
		cin>>p; p--;
		adj[p].push_back(i);
	}
	DFS(0);
	ll ans = (dp[0][0] + dp[0][2]) % md;
	cout<<ans<<'\n';
	return 0;
}

/*

*/