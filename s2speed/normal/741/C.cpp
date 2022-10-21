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
ll ans[maxn];

void DFS(ll r){
	for(auto i : adj[r]){
		if(ans[i] != -1) continue;
		ans[i] = ans[r] ^ 1;
		DFS(i);
	}
	return;
}

ll a[maxn] , b[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(ans , -1 , sizeof(ans));
	ll n;
	cin>>n;
	ll lm = (n << 1);
	for(ll i = 0 ; i < lm ; i += 2){
		adj[i].push_back(i + 1); adj[i + 1].push_back(i);
	}
	for(ll i = 0 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
		a[i] = v; b[i] = u;
	}
	for(ll i = 0 ; i < lm ; i++){
		if(ans[i] != -1) continue;
		ans[i] = 0;
		DFS(i);
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[a[i]] + 1<<' '<<ans[b[i]] + 1<<'\n';
	}
	return 0;
}