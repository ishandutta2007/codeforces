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

const ll maxn = 5e5 + 17 , md = 1e9 + 7 , inf = 2e7;

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

vector<int> adj[maxn] , gdj[maxn] , bfs;
int dis[maxn] , par[maxn] , ans[maxn][2];

void BFS(int r){
	dis[r] = 0;
	bfs.push_back(r);
	int x = 0;
	while(x < sze(bfs)){
		int v = bfs[x++];
		for(auto i : adj[v]){
			if(dis[i] > dis[v] + 1){
				dis[i] = dis[v] + 1;
				par[i] = v;
				bfs.push_back(i);
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dis , 63 , sizeof(dis));
	int n , m;
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin>>v>>u; v--; u--;
		gdj[v].push_back(u); gdj[u].push_back(v);
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			int v = i * n + j;
			for(auto k : gdj[i]){
				int u = k * n + j + n * n;
				adj[v].push_back(u);
			}
			v += n * n;
			for(auto k : gdj[j]){
				int u = i * n + k;
				if(i == k) continue;
				adj[v].push_back(u);
			}
		}
	}
	BFS(n - 1);
	if(dis[(n - 1) * n] > inf){
		cout<<"-1\n";
		return 0;
	}
	int j = dis[(n - 1) * n] / 2;
	cout<<j<<'\n';
	int h = (n - 1) * n;
	while(j){
		int v = h / n , u = h % n;
		ans[j][0] = v;
		ans[j--][1] = u;
		h = par[par[h]];
	}
	ans[0][0] = 0;
	ans[0][1] = n - 1;
	j = dis[(n - 1) * n] / 2;
	for(int c = 0 ; c < 2 ; c++){
		for(int i = 0 ; i <= j ; i++){
			cout<<ans[i][c] + 1<<' ';
		}
		cout<<'\n';
	}
	return 0;
}