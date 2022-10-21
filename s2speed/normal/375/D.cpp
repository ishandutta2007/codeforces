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

map<ll , ll> cnt[maxn] , res[maxn];
ll z[maxn];
vector<ll> adj[maxn];
ll a[maxn] , ans[maxn];
vector<pll> w[maxn];

void add(ll r , ll x){
	res[r][++cnt[r][x]]++;
	return;
}

void DFS(ll r , ll par){
	z[r] = 1;
	ll m = 0 , ind = -1;
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
		if(z[i] > m){
			m = z[i];
			ind = i;
		}
		z[r] += z[i];
	}
	if(ind != -1){
		cnt[r].swap(cnt[ind]);
		res[r].swap(res[ind]);
	}
	add(r , a[r]);
	for(auto i : adj[r]){
		if(i == par || i == ind) continue;
		for(auto p : cnt[i]){
			for(ll e = 0 ; e < p.second ; e++){
				add(r , p.first);
			}
		}
		cnt[i].clear(); res[i].clear();
	}
	for(auto p : w[r]){
		ans[p.second] = res[r][p.first];
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(ll i = 0 ; i < q ; i++){
		ll v , k;
		cin>>v>>k;
		w[--v].push_back({k , i});
	}
	DFS(0 , -1);
	for(ll i = 0 ; i < q ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}