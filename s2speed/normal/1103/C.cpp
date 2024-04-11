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
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 2.5e5 + 16 , md = 998244353 , inf = 2e18;

ll tav(ll n , ll k){
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

vector<ll> adj[maxn] , chd[maxn] , leaf;
ll par[maxn] , dis[maxn] , dep = 0;
bitset<maxn> mark;

void DFS(ll r){
	mark[r] = true;
	dis[r] = dep++;
	for(auto i : adj[r]){
		if(mark[i]) continue;
		par[i] = r;
		chd[r].push_back(i);
		DFS(i);
	}
	if(chd[r].empty()) leaf.push_back(r);
	dep--;
	return;
}
	

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(par , -1 , sizeof(par));
	ll n , m , k , l;
	cin>>n>>m>>k; l = (n - 1) / k;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	DFS(0);
	for(auto i : leaf){
		if(dis[i] >= l){
			cout<<"PATH\n"<<dis[i] + 1<<'\n';
			ll v = i;
			while(v != -1){
				cout<<v + 1<<' ';
				v = par[v];
			}
			cout<<'\n';
			return 0;
		}
	}
	cout<<"CYCLES\n";
	ll cnt = 0;
	for(auto r : leaf){
		if(cnt == k) break;
		cnt++;
		ll a = adj[r][0] , b = adj[r][1] , c = adj[r][2];
		if(a == par[r]) swap(a , c);
		if(b == par[r]) swap(b , c);
		if((dis[r] - dis[a]) % 3 != 2){
			cout<<dis[r] - dis[a] + 1<<'\n';
			ll v = r;
			while(dis[v] >= dis[a]){
				cout<<v + 1<<' ';
				v = par[v];
				if(v == -1) break;
			}
			cout<<'\n';
			continue;
		}
		if((dis[r] - dis[b]) % 3 != 2){
			cout<<dis[r] - dis[b] + 1<<'\n';
			ll v = r;
			while(dis[v] >= dis[b]){
				cout<<v + 1<<' ';
				v = par[v];
				if(v == -1) break;
			}
			cout<<'\n';
			continue;
		}
		if(dis[a] > dis[b]) swap(a , b);
		cout<<dis[b] - dis[a] + 2<<'\n'<<r + 1<<' ';
		ll v = b;
		while(dis[v] >= dis[a]){
			cout<<v + 1<<' ';
			v = par[v];
			if(v == -1) break;
		}
		cout<<'\n';
	}
	return 0;
}