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

const ll maxn = 6e2 + 16 , md = 1e9 + 7 , inf = 2e16;

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

int n , m;
int ed[maxn][maxn] , dis[maxn];
vector<pii> adj[maxn];
set<pii , greater<pii>> s;

void dij(int r){
	memset(dis , 63 , sizeof(dis));
	dis[r] = 0;
	s.insert({0 , r});
	while(!s.empty()){
		auto it = s.begin();
		pii p = *it;
		s.erase(it);
		int v = p.second , j = dis[v] % n , lm = n - j;
		for(int i = 0 ; i < lm ; i++){
			if(dis[j] > dis[v] + ed[v][i]){
				s.erase({dis[j] , j});
				dis[j] = dis[v] + ed[v][i];
				s.insert({dis[j] , j});
			}
			j++;
		}
		j = 0;
		for(int i = lm ; i < n ; i++){
			if(dis[j] > dis[v] + ed[v][i]){
				s.erase({dis[j] , j});
				dis[j] = dis[v] + ed[v][i];
				s.insert({dis[j] , j});
			}
			j++;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(ed , 63 , sizeof(ed));
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		int a , b , c;
		cin>>a>>b>>c;
		adj[a].push_back({b , c});
	}
	for(int i = 0 ; i < n ; i++){
		for(auto p : adj[i]){
			int v = p.first , w = p.second;
			ed[i][v] = min(ed[i][v] , w);
			for(int j = (v + 1) % n ; j != v ; j++ , j %= n){
				w++;
				ed[i][j] = min(ed[i][j] , w);
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		dij(i);
		for(int j = 0 ; j < n ; j++){
			cout<<dis[j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}