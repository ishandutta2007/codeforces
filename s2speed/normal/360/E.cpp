#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;

struct plll{
	ll first , second , third;
};

const int MAX_N = 1e4 + 20;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

map< pair<int , int> , int> mp;
vector<pll> adj[MAX_N];
vector<plll> aj[MAX_N] , e;
set<pll> s;
ll mark[MAX_N] , dis[MAX_N] , ans[MAX_N];
bool com[MAX_N];

void dij(bool ch){
	while(s.size() > 0){
		pll p = *s.begin();
		ll v = p.second , d = p.first , h = mark[v];
		if(h == 0){
			if(ch){
				h = 2;
			} else {
				h = 1;
			}
		}
		h--;
		for(auto o : aj[v]){
			ll u = o.first , k;
			if(!h){
				k = o.second;
			} else {
				k = o.third;
			}
			ans[mp[{v , u}]] = k;
			adj[v].push_back( {u , k} );
		}
		for(auto o : adj[v]){
			ll u = o.first , w = o.second;
			if(com[u]){
				continue;
			}
			if(d + w < dis[u]){
				s.erase( {dis[u] , u} );
				dis[u] = d + w;
				mark[u] = mark[v];
				s.insert( {dis[u] , u} );
			}
			if(d + w == dis[u]){
				if(mark[v] == 0){
					mark[u] = 0;
				} else if(mark[u] != 0){
					if(mark[u] != mark[v]){
						mark[u] = 0;
					}
				}
			}
		}
		s.erase(s.begin());
		com[v] = true;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m , k , s1 , s2 , f;
	cin>>n>>m>>k>>s1>>s2>>f; s1--; s2--; f--;
	for(int i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		adj[v].push_back( {u , w} );
		e.push_back( {v , u , w} );
	}
	for(int i = 0 ; i < k ; i++){
		ll v , u , l , r;
		cin>>v>>u>>l>>r; v--; u--;
		mp[{v , u}] = i;
		aj[v].push_back( {u , l , r} );
		ans[i] = r;
	}
	for(int i = 0 ; i < n ; i++){
		com[i] = false;
		dis[i] = 1e15;
		mark[i] = 0;
	}
	mark[s1] = 1;
	mark[s2] = 2;
	dis[s1] = 0;
	dis[s2] = 0;
	if(s1 == s2){
		mark[s2] = 0;
	}
	s.insert( {dis[s1] , s1} );
	s.insert( {dis[s2] , s2} );
	dij(true);
	if(mark[f] == 1){
		cout<<"WIN\n";
		for(int i = 0 ; i < k ; i++){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
		return 0;
	}
	for(int i = 0 ; i < n ; i++){
		adj[i].clear();
		com[i] = false;
		dis[i] = 1e15;
		mark[i] = 0;
	}
	for(int i = 0 ; i < m ; i++){
		ll v = e[i].first , u = e[i].second , w = e[i].third;
		adj[v].push_back( {u , w} );
	}
	mark[s1] = 1;
	mark[s2] = 2;
	dis[s1] = 0;
	dis[s2] = 0;
	if(s1 == s2){
		mark[s2] = 0;
	}
	s.insert( {dis[s1] , s1} );
	s.insert( {dis[s2] , s2} );
	dij(false);
	if(mark[f] == 0){
		cout<<"DRAW\n";
		for(int i = 0 ; i < k ; i++){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
	} else {
		cout<<"LOSE\n";
	}
	return 0;
}