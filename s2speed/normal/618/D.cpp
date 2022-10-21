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

vector<ll> adj[maxn];
ll dp[maxn] , pd[maxn];

void DFS(ll r , ll par){
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
	}
	ll m1 = -1 , m2 = -1 , h = 0;
	for(auto i : adj[r]){
		if(i == par) continue;
		h += dp[i];
		ll x = pd[i] - dp[i];
		if(x > m2){
			m2 = x;
		}
		if(x > m1){
			m2 = m1;
			m1 = x;
		}
	}
	pd[r] = h + m1 + 1;
	dp[r] = h + m1 + m2 + 2;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , x , y;
	cin>>n>>y>>x;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	if(y >= x){
		ll ans = 1ll * (n - 1) * x;
		for(ll i = 0 ; i < n ; i++){
			if(sze(adj[i]) == n - 1){
				ans -= x - y;
				break;
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	DFS(0 , -1);
	ll ans = 1ll * y * dp[0] + 1ll * x * (n - dp[0] - 1);
	cout<<ans<<'\n';
	return 0;
}