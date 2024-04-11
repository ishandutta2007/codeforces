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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , c[maxn] , d = 0 , cnt[maxn][2] , ans = 0;
vector<ll> adj[maxn];

void cDFS(ll r , ll par){
	c[r] = d;
	cnt[r][d] = 1;
	d ^= 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		cDFS(i , r);
		cnt[r][0] += cnt[i][0];
		cnt[r][1] += cnt[i][1];
	}
	d ^= 1;
	return;
}

void aDFS(ll r , ll par){
	ll o = c[r] , h;
	h = cnt[0][o] * cnt[0][o] - (cnt[0][o] - cnt[r][o]) * (cnt[0][o] - cnt[r][o]);
	for(auto i : adj[r]){
		if(i == par) continue;
		h -= cnt[i][o] * cnt[i][o];
	}
	o ^= 1;
	h -= cnt[0][o] * cnt[0][o] - (cnt[0][o] - cnt[r][o]) * (cnt[0][o] - cnt[r][o]);
	for(auto i : adj[r]){
		if(i == par) continue;
		h += cnt[i][o] * cnt[i][o];
	}
	ans += h % md * a[r] % md;
	for(auto i : adj[r]){
		if(i == par) continue;
		aDFS(i , r);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	cDFS(0 , -1);
	aDFS(0 , -1);
	ans %= md; ans += (ans < 0) * md;
	cout<<ans<<'\n';
	return 0;
}