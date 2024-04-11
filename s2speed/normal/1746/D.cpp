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

const ll maxn = 5e5 + 17 , md = 1e9 + 7 , inf = 2e16;

vector<ll> adj[maxn] , v;
ll a[maxn] , dp[maxn] , f[maxn];

void dDFS(ll r , ll w){
	ll d = sze(adj[r]);
	if(d == 0){
		dp[r] = w * a[r];
		f[r] = a[r];
		return;
	}
	ll h = w / d;
	dp[r] = w * a[r];
	for(auto i : adj[r]){
		dDFS(i , h);
		dp[r] += dp[i];
	}
	v.clear();
	for(auto i : adj[r]){
		v.push_back(f[i]);
	}
	sort(all(v) , greater<ll>());
	h = w % d;
	for(ll i = 0 ; i < h ; i++){
		dp[r] += v[i];
	}
	f[r] = a[r] + v[h];
	return;
}

void solve(){
	ll n , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++) adj[i].clear();
	for(ll i = 1 ; i < n ; i++){
		ll p;
		cin>>p; p--;
		adj[p].push_back(i);
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	dDFS(0 , k);
	cout<<dp[0]<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}