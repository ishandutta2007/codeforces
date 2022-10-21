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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

vector<ll> adj[maxn] , ans[2] , bfs;
ll g[maxn] , pr[maxn];

void BFS(){
	ll x = 0;
	while(x < sze(bfs)){
		ll v = bfs[x++];
		for(auto i : adj[v]){
			if(g[i] == g[v]) continue;
			if(g[i] == -1){
				g[i] = g[v];
				bfs.push_back(i);
				pr[i] = v;
				continue;
			}
			ans[0].push_back(i);
			ll h = v;
			while(~h){
				ans[0].push_back(h);
				h = pr[h];
			}
			h = i;
			while(~h){
				ans[1].push_back(h);
				h = pr[h];
			}
			return;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(g , -1 , sizeof(g));
	ll n , m , r;
	cin>>n>>m>>r; r--;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		if(u == r) continue;
		adj[v].push_back(u);
	}
	pr[r] = -1;
	for(auto i : adj[r]){
		g[i] = i;
		pr[i] = r;
		bfs.push_back(i);
	}
	BFS();
	if(ans[0].empty()){
		cout<<"Impossible\n";
		return 0;
	}
	cout<<"Possible\n";
	reverse(all(ans[0])); reverse(all(ans[1]));
	cout<<sze(ans[0])<<'\n';
	for(auto i : ans[0]){
		cout<<i + 1<<' ';
	}
	cout<<'\n';
	cout<<sze(ans[1])<<'\n';
	for(auto i : ans[1]){
		cout<<i + 1<<' ';
	}
	cout<<'\n';
	return 0;
}