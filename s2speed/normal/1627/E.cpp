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

map<pll , ll> ind;
vector<ll> t[maxn];
vector<pll> adj[maxn] , nd;
vector<plll> ed;
ll x[maxn] , dis[maxn];
priority_queue<pll , vector<pll> , greater<pll>> pq[maxn];

void solve(){
	ed.clear(); nd.clear(); ind.clear();
	ll n , m , k;
	cin>>n>>m>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>x[i];
		t[i].clear();
	}
	for(ll i = 0 ; i < 2 * k + 2 ; i++){
		dis[i] = inf;
		adj[i].clear();
	}
	for(ll i = 0 ; i < k ; i++){
		ll a , b , c , d , h;
		cin>>a>>b>>c>>d>>h; a--; b--; c--; d--;
		ed.push_back({{a * m + b , c * m + d} , h});
		t[a].push_back(b); t[c].push_back(d);
	}
	t[0].push_back(0);
	t[n - 1].push_back(m - 1);
	ll cur = 0;
	for(ll i = 0 ; i < n ; i++){
		sort(all(t[i]));
		t[i].resize(distance(t[i].begin() , unique(all(t[i]))));
		ll ts = sze(t[i]);
		for(ll e = 0 ; e < ts ; e++){
			ll j = t[i][e];
			ind[{i , j}] = cur++;
			nd.push_back({i , j});
			if(e){
				ll w = (j - t[i][e - 1]) * x[i];
				adj[cur - 1].push_back({cur - 2 , w});
				adj[cur - 2].push_back({cur - 1 , w});
			}
		}
	}
	for(auto q : ed){
		pll p = q.first;
		ll h = q.second;
		ll a = p.first / m , b = p.first % m , c = p.second / m , d = p.second % m;
		adj[ind[{a , b}]].push_back({ind[{c , d}] , -h});
	}
	pq[0].push({0 , 0});
	dis[0] = 0;
	for(ll i = 0 ; i < n ; i++){
		while(!pq[i].empty()){
			pll q = pq[i].top(); pq[i].pop();
			ll v = q.second;
			if(dis[v] < q.first) continue;
			for(auto p : adj[v]){
				ll j = p.first , w = p.second;
				if(dis[j] > dis[v] + w){
					dis[j] = dis[v] + w;
					pq[nd[j].first].push({dis[j] , j});
				}
			}
		}
	}
	if(dis[cur - 1] == inf){
		cout<<"NO ESCAPE\n";
		return;
	}
	cout<<dis[cur - 1]<<'\n';
	return;
}

/*
1
5 3 3
5 17 8 1 4
1 3 3 3 4
3 1 5 2 5
3 2 5 1 6
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}