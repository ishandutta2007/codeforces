#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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

vector<ll> adj[maxn] , jda[maxn] , ft;
ll c[maxn] , o;
bitset<maxn> mark;

void fDFS(ll r){
	mark[r] = true;
	for(auto i : adj[r]){
		if(mark[i]) continue;
		fDFS(i);
	}
	ft.push_back(r);
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

void solve(){
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		c[i] = -1;
		adj[i].clear();
		jda[i].clear();
		mark[i] = false;
	}
	ft.clear();
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		if(v == u) continue;
		adj[v].push_back(u);
		jda[u].push_back(v);
	}
	for(ll i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		fDFS(i);
	}
	o = 0;
	reverse(all(ft));
	for(auto i : ft){
		if(c[i] != -1) continue;
		cDFS(i);
		o++;
	}
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		cnt += (c[i] == o - 1);
	}
	if(cnt == n){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n"<<cnt<<' '<<n - cnt<<'\n';
	for(ll i = 0 ; i < n ; i++){
		if(c[i] == o - 1) cout<<i + 1<<' ';
	}
	cout<<'\n';
	for(ll i = 0 ; i < n ; i++){
		if(c[i] != o - 1) cout<<i + 1<<' ';
	}
	cout<<'\n';
	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}