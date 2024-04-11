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

const ll maxn = 3e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

vector<ll> adj[maxn] , u , bfs , ans;
vector<pll> ed;
ll gr[maxn];

void BFS(){
	for(auto i : u){
		gr[i] = i;
	}
	bfs = u;
	ll x = 0;
	while(x < sze(bfs)){
		ll v = bfs[x++];
		for(auto i : adj[v]){
			if(gr[i] != -1) continue;
			gr[i] = gr[v];
			bfs.push_back(i);
		}
	}
	return;
}

struct segtree {

	ll sz = 1;
	vector<ll> val , laz;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		laz.assign(sz << 1 , 0);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = 0;
		val[x] += h;
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln] += h; laz[rn] += h;
		return;
	}

	void add(ll l , ll r , ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = k;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return max(a , b);
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st[52];
ll a[maxn] , ls[maxn] , pr[maxn] , dp[maxn][52];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k;
	cin>>n>>k;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		pr[i] = ls[a[i]];
		ls[a[i]] = i;
	}
	for(ll j = 0 ; j <= k ; j++){
		st[j].init(n);
		dp[0][j] = 0;
	}
	for(ll i = 1 ; i <= n ; i++){
		for(ll j = 0 ; j < k ; j++){
			st[j].add(pr[i] , i , 1);
			dp[i][j] = st[j].cal(0 , i);
			st[j + 1].add(i , i + 1 , dp[i][j]);
		}
	}
	cout<<dp[n][k - 1]<<'\n';
	return 0;
}