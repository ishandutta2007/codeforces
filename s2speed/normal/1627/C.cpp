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

vector<pll> ed;
vector<ll> adj[maxn];
ll dis[maxn] , dep = 0;

void mDFS(ll r , ll par){
	dis[r] = dep++;
	for(auto i : adj[r]){
		if(i == par) continue;
		mDFS(i , r);
	}
	dep--;
	return;
}

void solve(){
	ed.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++) adj[i].clear();
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
		ed.push_back({v , u});
	}
	for(ll i = 0 ; i < n ; i++){
		if(sze(adj[i]) >= 3){
			cout<<"-1\n";
			return;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		if(sze(adj[i]) == 1){
			mDFS(i , -1);
			break;
		}
	}
	for(auto p : ed){
		ll v = p.first , u = p.second;
		if(dis[v] > dis[u]) swap(v , u);
		cout<<2 + (dis[v] & 1)<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}