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

const ll maxn = 7e2 + 16 , md = 1e8 , inf = 2e16;

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

struct Int {

	ll a[18];

	void def(){
		memset(a , 0 , sizeof(a));
		return;
	}

	friend bool operator > (Int a , Int b){
		for(int j = 14 ; j >= 0 ; j--){
			if(a.a[j] > b.a[j]) return true;
			if(a.a[j] < b.a[j]) return false;
		}
		return false;
	}

	friend Int operator * (Int a , Int b){
		Int res;
		res.def();
		for(ll i = 0 ; i < 15 ; i++){
			for(ll j = 0 ; j < 15 ; j++){
				if(i + j >= 15) break;
				ll h = a.a[i] * b.a[j];
				res.a[i + j] += h % md;
				res.a[i + j + 1] += h / md;
			}
		}
		for(ll q = 0 ; q < 15 ; q++){
			ll h = res.a[q] / md;
			res.a[q + 1] += h;
			res.a[q] %= md;
		}
		return res;
	}

};

Int dp[maxn][maxn] , f[maxn] , h[maxn];
vector<ll> adj[maxn];
ll z[maxn];

void merge(ll v , ll u){
	for(ll i = 1 ; i <= z[v] + z[u] ; i++) h[i].def();
	for(ll i = 1; i <= z[v] ; i++){
		for(ll j = 1 ; j <= z[u] ; j++){
			Int o = dp[v][i] * dp[u][j];
			if(o > h[i + j]){
				h[i + j] = o;
			}
			o = dp[v][i] * f[u];
			if(o > h[i]){
				h[i] = o;
			}
		}
	}
	for(ll i = 1 ; i <= z[v] + z[u] ; i++){
		dp[v][i] = h[i];
	}
	return;
}

void dDFS(ll r , ll par){
	dp[r][z[r] = 1].a[0] = 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		dDFS(i , r);
		merge(r , i);
		z[r] += z[i];
	}
	f[r] = dp[r][1];
	for(ll i = 2 ; i <= z[r] ; i++){
		Int w , o; w.def();
		w.a[0] = i;
		o = w * dp[r][i];
		if(o > f[r]) f[r] = o;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Int a , b;
	a.a[0] = 2; a.a[1] = 6; b.a[0] = 3;
	a = a * b;
	ll n;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	dDFS(0 , -1);
	bool t = false;
	for(ll j = 14 ; j >= 0 ; j--){
		ll h = f[0].a[j] , o = 1e7;
		for(ll q = 7 ; q >= 0 ; q--){
			if(h / o) t = true;
			if(t) cout<<h / o;
			h %= o; o /= 10;
		}
	}
	cout<<endl;
	return 0;
}