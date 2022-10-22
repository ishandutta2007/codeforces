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

const ll maxn = 5e5 + 17 , md = 998244353 , inf = 2e16;

ll n , m;
vector<vector<bool>> a , b , c , d;
string s;
vector<ll> adj[maxn];
ll dis[maxn] , par[maxn];
priority_queue<pll , vector<pll> , greater<pll>> pq;

bool check_adj(ll i , ll j){
	bool h = false;
	if(i > 0){
		h |= a[i - 1][j];
	}
	if(i < n - 1){
		h |= a[i + 1][j];
	}
	if(j > 0){
		h |= a[i][j - 1];
	}
	if(j < m - 1){
		h |= a[i][j + 1];
	}
	return h;
}

ll dij(bool t){
	while(!pq.empty()) pq.pop();
	for(ll i = t ; i < n ; i += 2){
		if(!b[i][0]) continue;
		if(a[i][0]){
			pq.push({0 , i * m});
			dis[i * m] = 0;
		} else {
			pq.push({1 , i * m});
			dis[i * m] = 1;
		}
	}
	while(!pq.empty()){
		pll p = pq.top(); pq.pop();
		ll v = p.second;
		if(dis[v] != p.first) continue;
		if(v % m == m - 1){
			return v;
		}
		for(auto u : adj[v]){
			ll i = u / m , j = u % m;
			if(!b[i][j]) continue;
			ll w = !a[i][j];
			if(dis[u] > dis[v] + w){
				par[u] = v;
				dis[u] = dis[v] + w;
				pq.push({dis[u] , u});
			}
		}
	}
	return -1;
}

void solve(){
	a.clear();
	cin>>n>>m;
	a.resize(n);
	for(ll i = 0 ; i < n ; i++){
		a[i].resize(m);
		cin>>s;
		for(ll j = 0 ; j < m ; j++){
			a[i][j] = (s[j] == '#');
			adj[i * m + j].clear();
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			ll v = i * m + j;
			if(i > 0 && j > 0){
				adj[v].push_back(v - m - 1); adj[v - m - 1].push_back(v);
			}
			if(i > 0 && j < m - 1){
				adj[v].push_back(v - m + 1); adj[v - m + 1].push_back(v);
			}
		}
	}
	b = a;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = i & 1 ; j < m ; j += 2){
			if(!check_adj(i , j)) b[i][j] = true;
		}
	}
	fill(dis , dis + n * m , inf); fill(par , par + n * m , -1);
	ll t = dij(0) , cnt[] = {inf , inf};
	if(t != -1){
		cnt[0] = 0;
		c = a;
		ll v = t;
		while(true){
			ll i = v / m , j = v % m;
			cnt[0] += !a[i][j];
			c[i][j] = true;
			if(j == 0) break;
			v = par[v];
		}
	}
	b = a;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = !(i & 1) ; j < m ; j += 2){
			if(!check_adj(i , j)) b[i][j] = true;
		}
	}
//	for(ll i = 0 ; i < n ; i++){
//		for(ll j = 0 ; j < m ; j++){
//			cout<<b[i][j];
//		}
//		cout<<'\n';
//	}
	t = dij(1);
	if(t != -1){
		cnt[1] = 0;
		d = a;
		ll v = t;
		while(true){
			ll i = v / m , j = v % m;
			cnt[1] += !a[i][j];
			d[i][j] = true;
			if(j == 0) break;
			v = par[v];
		}
	}
	if(cnt[0] == cnt[1] && cnt[0] == inf){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	if(cnt[0] <= cnt[1]){
		for(ll i = 0 ; i < n ; i++){
			for(ll j = 0 ; j < m ; j++){
				cout<<(c[i][j] ? '#' : '.');
			}
			cout<<'\n';
		}
	} else {
		for(ll i = 0 ; i < n ; i++){
			for(ll j = 0 ; j < m ; j++){
				cout<<(d[i][j] ? '#' : '.');
			}
			cout<<'\n';
		}
	}
	return;
}

/*
1
5 5
.....
.....
.....
.....
.....
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}