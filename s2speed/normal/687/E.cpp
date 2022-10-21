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

const ll maxn = 5e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

vector<ll> adj[maxn] , jda[maxn] , f , vc[maxn];
bitset<maxn> mark , sink , mdj[maxn];
ll c[maxn] , o = 0;

void fDFS(ll r){
	mark[r] = true;
	for(auto i : adj[r]){
		if(mark[i]) continue;
		fDFS(i);
	}
	f.push_back(r);
	return;
}

void cDFS(ll r){
	c[r] = o;
	for(auto i : jda[r]){
		if(c[i] != -1) continue;
		cDFS(i);
	}
	return;
}

ll dis[maxn];
vector<ll> bfs;

void BFS(ll r){
	memset(dis , 63 , sizeof(dis));
	bfs.clear();
	dis[r] = 0;
	bfs.push_back(r);
	ll x = 0;
	while(x < sze(bfs)){
		ll v = bfs[x++];
		for(auto i : adj[v]){
			if(c[i] != c[r]) continue;
			if(dis[i] > dis[v] + 1){
				dis[i] = dis[v] + 1;
				bfs.push_back(i);
			}
		}
	}
	return;
}

ll find_kamar(ll j){
	ll res = inf;
	for(auto i : vc[j]){
		BFS(i);
		for(auto v : vc[j]){
			if(mdj[v][i]){
				res = min(res , dis[v] + 1);
			}
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(c , -1 , sizeof(c));
	sink.set();
	ll n , m , ans;
	cin>>n>>m; ans = n;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); jda[u].push_back(v);
		mdj[v][u] = true;
	}
	for(ll i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		fDFS(i);
	}
	reverse(all(f));
	for(auto i : f){
		if(c[i] != -1) continue;
		cDFS(i);
		o++;
	}
	for(ll i = 0 ; i < n ; i++){
		vc[c[i]].push_back(i);
		if(!sink[c[i]]) continue;
		for(auto j : adj[i]){
			if(c[i] == c[j]) continue;
			sink[c[i]] = false;
			break;
		}
	}
	for(ll j = 0 ; j < o ; j++){
		if(!sink[j]) continue;
		if(sze(vc[j]) == 1) continue;
		ans++;
		ll h = find_kamar(j);
		ans += 998 * h;
	}
	cout<<ans<<'\n';
	return 0;
}