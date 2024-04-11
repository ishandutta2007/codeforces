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

ll cur = 0 , ans = inf;
vector<ll> adj[maxn] , q;
set<pll , greater<pll>> s[maxn];
ll a[maxn] , dp[maxn];

void iDFS(ll r , ll par){
	for(auto i : adj[r]){
		if(i == par) continue;
		iDFS(i , r);
		dp[r] = max(dp[r] , dp[i]);
		s[r].insert({dp[i] , i});
	}
	cur += max(0ll , a[r] - dp[r]) * (par != -1);
	dp[r] = max(dp[r] , a[r]);
	return;
}

void reroot(ll v , ll u){
	ll h = max(0ll , a[u] - (*s[u].begin()).first);
	cur -= h;
	s[v].erase({dp[u] , u});
	dp[v] = max((*s[v].begin()).first , a[v]);
	h = max(0ll , a[v] - (*s[v].begin()).first);
	cur += h;
	s[u].insert({dp[v] , v});
	return;
}

void rDFS(ll r , ll par){
	ll h = cur + (a[r] == q[0] ? q[0] - q[1] : 0);
	ans = min(ans , h);
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

	memset(dp , 0 , sizeof(dp));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		q.push_back(a[i]);
		s[i].insert({0 , -1});
	}
	sort(all(q) , greater<ll>());
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	iDFS(0 , -1);
	rDFS(0 , -1);
	cout<<ans + q[0]<<'\n';
	return 0;
}