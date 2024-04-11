#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,no-stack-protector")

#define all(x) x.begin() , x.end()
#define mp make_pair
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	return ((b == 0) ? a : gcd(b , a % b));
}

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 1e18;

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

vector<pll> adj[MAXN];
ll dis[MAXN] , cnt[MAXN];
priority_queue<pll , vector<pll> , greater<pll> > pq;
bitset<MAXN> mark;

void dij(){
	dis[0] = 0;
	pq.push({0 , 0});
	while(!pq.empty()){
		pll p = pq.top(); pq.pop();
		ll v = p.second;
		if(mark[v]) continue;
		for(auto q : adj[v]){
			ll w = q.second , i = q.first;
			if(w < 0) w = -w;
			if(!mark[i]){
				dis[i] = min(dis[i] , dis[v] + w);
				pq.push({dis[i] , i});
			}
		}
		mark[v] = true;
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	memset(dis , 63 , sizeof(dis));
	ll n , m , k , ans = 0;
	cin>>n>>m>>k;
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		adj[v].push_back({u , w}); adj[u].push_back({v , w});
	}
	for(ll i = 0 ; i < k ; i++){
		ll v , w;
		cin>>v>>w; v--;
		cnt[v]++;
		adj[v].push_back({0 , -w}); adj[0].push_back({v , -w});
	}
	dij();
	for(ll i = 1 ; i < n ; i++){
		bool ch = false;
		for(auto p : adj[i]){
			ll j = p.first , w = p.second;
			if(w < 0) continue;
			ch |= (dis[j] + w == dis[i]);
		}
		if(ch){
			ans += cnt[i];
		} else {
			ans += max(0ll , cnt[i] - 1);
		}
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/