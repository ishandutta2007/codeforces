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

const ll maxn = 1e6 + 16 , md = 998244353 , inf = 2e18;

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

ll d[maxn] , f[maxn];
vector<ll> bfs , adj[maxn];
bitset<maxn> w;
vector<vector<char>> a;

void BFS(ll r){
	w[r] = true;
	bfs.push_back(r);
	ll x = 0;
	while(x < sze(bfs)){
		ll v = bfs[x++];
		for(auto i : adj[v]){
			if(w[i]) continue;
			f[i]++;
			if(f[i] >= d[i] - 1){
				w[i] = true;
				bfs.push_back(i);
			}
		}
	}
	bfs.clear();
	return;
}

void solve(){
	a.clear();
	ll n , m;
	cin>>n>>m;
	a.resize(n);
	for(ll i = 0 ; i < n ; i++){
		a[i].resize(m);
		for(ll j = 0 ; j < m ; j++){
			cin>>a[i][j];
			ll v = i * m + j;
			adj[v].clear();
		}
	}
	ll r;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			if(a[i][j] == '#') continue;
			ll v = i * m + j;
			if(a[i][j] == 'L') r = v;
			if(i > 0){
				if(a[i - 1][j] != '#'){
					adj[v].push_back(v - m); adj[v - m].push_back(v);
				}
			}
			if(j > 0){
				if(a[i][j - 1] != '#'){
					adj[v].push_back(v - 1); adj[v - 1].push_back(v);
				}
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			ll v = i * m + j;
			d[v] = sze(adj[v]);
			f[v] = 0;
			w[v] = false;
		}
	}
	BFS(r);
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			ll v = i * m + j;
			if(a[i][j] == '.' && w[v]){
				a[i][j] = '+';
			}
			cout<<a[i][j];
		}
		cout<<'\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}