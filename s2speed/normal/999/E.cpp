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
bitset<maxn> dead , mark , src;
ll c[maxn] , o = 0;

void dDFS(ll r){
	dead[r] = true;
	for(auto i : adj[r]){
		if(dead[i]) continue;
		dDFS(i);
	}
	return;
}

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
	mark[r] = true;
	for(auto i : jda[r]){
		if(mark[i]) continue;
		cDFS(i);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(c , -1 , sizeof(c));
	ll n , m , r;
	cin>>n>>m>>r; r--;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); jda[u].push_back(v);
	}
	dDFS(r);
	mark = dead;
	for(ll i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		fDFS(i);
	}
	reverse(all(ft));
	mark = dead;
	for(auto i : ft){
		if(c[i] != -1) continue;
		cDFS(i);
		o++;
	}
	src.set();
	for(ll i = 0 ; i < n ; i++){
		if(dead[i]) continue;
		for(auto j : adj[i]){
			if(dead[j] || c[j] == c[i]) continue;
			src[c[j]] = false;
		}
	}
	ll ans = 0;
	for(ll i = 0 ; i < o ; i++){
		ans += src[i];
	}
	cout<<ans<<'\n';
	return 0;
}