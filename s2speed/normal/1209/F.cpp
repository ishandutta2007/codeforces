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
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e6 + 15 , md = 1e9 + 7 , inf = 1e10;

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

struct item {
	ll ish , last , val , ind;
};

bool cmp(item a , item b){
	if(a.ish != b.ish){
		return (a.ish > b.ish);
	}
	if(a.last != b.last){
		return (a.last > b.last);
	}
	return (a.val > b.val);
}

priority_queue<item , vector<item> , std::function<bool(item , item)> > pq(cmp);
item dis[MAXN] , pr = {0 , 0 , 0 , 0};
ll h;
vector<pll> adj[MAXN];
bitset<MAXN> mark;

void dij(){
	dis[0] = {0 , 0 , 0 , 0};
	pq.push(dis[0]);
	h = 1;
	pr = dis[0];
	while(!pq.empty()){
		item o = pq.top(); pq.pop();
		ll v = o.ind;
		if(mark[v]) continue;
		if(dis[v].ish != pr.ish || dis[v].last != pr.last){
			h++;
			pr = dis[v];
		}
		for(auto p : adj[v]){
			ll i = p.first;
			if(mark[i]) continue;
			item q = {h , p.second , (10ll * o.val + p.second) % md , i};
			if(h < dis[i].ish){
				dis[i] = q;
				pq.push(q);
			}
			if(h == dis[i].ish && p.second < dis[i].last){
				dis[i] = q;
				pq.push(q);
			}
		}
		mark[v] = true;
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(dis , 63 , sizeof(dis));
	ll n , m , fake;
	cin>>n>>m; fake = n;
	for(ll i = 1 ; i <= m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		ll o = i , c = v;
		while(o > 0){
			if(o < 10){
				adj[u].push_back({c , o});
				break;
			}
			adj[fake].push_back({c , o % 10});
			c = fake++;
			o /= 10;
		}
		o = i; c = u;
		while(o > 0){
			if(o < 10){
				adj[v].push_back({c , o});
				break;
			}
			adj[fake].push_back({c , o % 10});
			c = fake++;
			o /= 10;
		}
	}
	dij();
	for(ll i = 1 ; i < n ; i++){
		cout<<dis[i].val<<'\n';
	}
	return 0;
}

/*

*/