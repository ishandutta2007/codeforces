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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> a;
vector<ll> adj[maxn];
ll dp[maxn] , dep = 0 , cnt[maxn] , res;
bool ans;

void dDFS(ll r , ll par){
	if(a[r]){
		dp[r] = 0;
		cnt[r] = 1;
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		dDFS(i , r);
		dp[r] = min(dp[r] , dp[i] + 1);
		cnt[r] += cnt[i];
	}
	return;
}

void fDFS(ll r , ll par){
	if(r && sze(adj[r]) == 1){
		ans = true;
		return;
	}
	dep++;
	for(auto i : adj[r]){
		if(i == par) continue;
		if(dep >= dp[i]){
			res++;
			continue;
		}
		fDFS(i , r);
	}
	dep--;
	return;
}

void solve(){
	ll n , k;
	cin>>n>>k;
	ans = false;
	res = 0;
	for(ll i = 0 ; i < n ; i++){
		adj[i].clear();
		a[i] = false;
		dp[i] = inf;
	}
	for(ll i = 0 ; i < k ; i++){
		ll h;
		cin>>h;
		a[--h] = true;
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	dDFS(0 , -1);
	fDFS(0 , -1);
	cout<<(ans ? -1 : res)<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}