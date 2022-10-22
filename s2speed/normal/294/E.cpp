#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e3 + 16 , md = 7340033 , inf = 2e18;

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

vector<plll> ed;
vector<pll> adj[maxn];
ll dis[maxn][maxn] , dep = 0 , z[maxn] , co[2] , cs[2] , cz[2] , cur;

void cDFS(ll r , ll par , ll v , ll u){
	z[r] = 1;
	cur += dep;
	for(auto p : adj[r]){
		ll i = p.first;
		if(i == par) continue;
		if((i == v && r == u) || (i == u && r == v)) continue;
		dep += p.second;
		cDFS(i , r , v , u);
		dep -= p.second;
		z[r] += z[i];
	}
	return;
}

void fDFS(ll r , ll par , ll v , ll u , bool c){
	cs[c] += cur;
	co[c] = min(co[c] , cur);
	for(auto p : adj[r]){
		ll i = p.first , w = p.second;
		if(i == par) continue;
		if((i == v && r == u) || (i == u && r == v)) continue;
		cur -= 1ll * z[i] * w; cur += 1ll * (cz[c] - z[i]) * w;
		fDFS(i , r , v , u , c);
		cur += 1ll * z[i] * w; cur -= 1ll * (cz[c] - z[i]) * w;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v-- ;u--;
		adj[v].push_back({u , w}); adj[u].push_back({v , w});
		ed.push_back({{v , u} , w});
	}
	ll ans = inf;
	for(auto q : ed){
		pll p = q.first;
		ll v = p.first , u = p.second , w = q.second , res = 0;
		co[0] = co[1] = inf; cs[0] = cs[1] = cur = 0;
		cDFS(v , -1 , v , u); cz[0] = z[v];
		fDFS(v , -1 , v , u , 0); cur = 0;
		cDFS(u , -1 , v , u); cz[1] = z[u];
		fDFS(u , -1 , v , u , 1);
//		cout<<v<<' '<<u<<'\n';
//		cout<<co[0]<<' '<<co[1]<<'\n';
		res += cs[0] + cs[1]; res >>= 1;
		res += 1ll * cz[0] * cz[1] * w;
		res += 1ll * co[1] * cz[0] + 1ll * co[0] * cz[1];
		ans = min(ans , res);
	}
	cout<<ans<<'\n';
	return 0;
}