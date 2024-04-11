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
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1.5e5 + 15 , md = 1e9 + 7 , inf = 1e15;
// check problem statement

vector<ll> adj[MAXN][4];
ll a[MAXN][4] , dp[MAXN][4] , x[MAXN][4];
set<ll> s;
priority_queue<pll , vector<pll> , greater<pll> > pq;
vector<ll> d;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(x , 0 , sizeof(x));
	ll n[4];
	for(ll j = 0 ; j < 4 ; j++) cin>>n[j];
	for(ll j = 0 ; j < 4 ; j++){
		for(ll i = 0 ; i < n[j] ; i++){
			cin>>a[i][j];
			dp[i][j] = inf;
		}
	}
	for(ll j = 1 ; j < 4 ; j++){
		ll m;
		cin>>m;
		for(ll i = 0 ; i < m ; i++){
			ll y , z;
			cin>>y>>z; y--; z--;
			adj[y][j - 1].push_back(z);
		}
	}
	for(ll j = 0 ; j < 4 ; j++){
		for(ll i = 0 ; i < n[j] ; i++){
			sort(all(adj[i][j]));
			adj[i][j].push_back(inf);
		}
	}
	for(ll i = 0 ; i < n[0] ; i++){
		dp[i][0] = a[i][0];
	}
	for(ll j = 1 ; j < 4 ; j++){
		for(ll i = 0 ; i < n[j - 1] ; i++){
			pq.push({dp[i][j - 1] , i});
		}
		for(ll i = 0 ; i < n[j] ; i++){
			s.insert(i);
		}
		while(!pq.empty()){
			pll p = pq.top(); pq.pop();
			ll v = p.second , o = dp[v][j - 1];
			auto et = s.end();
			for(auto it = s.begin() ; it != et ; ++it){
				ll i = *it;
				while(adj[v][j - 1][x[v][j - 1]] < i) x[v][j - 1]++;
				if(adj[v][j - 1][x[v][j - 1]] == i) continue;
				d.push_back(i);
				dp[i][j] = o + a[i][j];
			}
			for(auto i : d){
				s.erase(i);
			}
			d.clear();
		}
		s.clear();
	}
	ll ans = inf;
	for(ll i = 0 ; i < n[3] ; i++){
		ans = min(ans , dp[i][3]);
	}
	cout<<(ans > 4e8 ? -1 : ans)<<'\n';
	return 0;
}

/*

*/