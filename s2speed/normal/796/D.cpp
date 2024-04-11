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

const ll maxn = 3e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

vector<ll> adj[maxn] , u , bfs , ans;
vector<pll> ed;
ll gr[maxn];

void BFS(){
	for(auto i : u){
		gr[i] = i;
	}
	bfs = u;
	ll x = 0;
	while(x < sze(bfs)){
		ll v = bfs[x++];
		for(auto i : adj[v]){
			if(gr[i] != -1) continue;
			gr[i] = gr[v];
			bfs.push_back(i);
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(gr , -1 , sizeof(gr));
	ll n , k , d;
	cin>>n>>k>>d;
	for(ll i = 0 ; i < k ; i++){
		ll h;
		cin>>h; h--;
		u.push_back(h);
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
		ed.push_back({v , u});
	}
	BFS();
	for(ll i = 0 ; i < n - 1 ; i++){
		pll p = ed[i];
		if(gr[p.first] != gr[p.second]){
			ans.push_back(i);
		}
	}
	cout<<sze(ans)<<'\n';
	for(auto i : ans){
		cout<<i + 1<<' ';
	}
	cout<<'\n';
	return 0;
}