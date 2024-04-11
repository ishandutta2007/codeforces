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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

ll ch[maxn][4] , d , n;
db ans = 0;
vector<ll> adj[maxn];
vector<pll> ed;
ll z[maxn] , w[maxn];

void DFS(ll r , ll par){
	z[r] = 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
		z[r] += z[i];
	}
	return;
}

void add(ll v , ll k){
	for(ll j = 1 ; j <= 2 ; j++){
		db h = (db)6 * ch[z[v]][j] / d * ch[n - z[v]][3 - j] * k;
//		cout<<ch[z[v]][j]<<' '<<ch[n - z[v]][3 - j]<<' '<<z[v]<<' '<<j<<'\n';
		ans += h;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n; d = 1ll * n * (n - 1) * (n - 2);
	for(ll i = 0 ; i <= n ; i++){
		ch[i][0] = 1;
		for(ll j = 1 ; j <= 3 ; j++){
			ch[i][j] = 1ll * ch[i][j - 1] * (i - j + 1);
		}
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u , e;
		cin>>v>>u>>e; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
		ed.push_back({v , u});
		w[i - 1] = e;
	}
	DFS(0 , -1);
	for(ll e = 0 ; e < n - 1 ; e++){
		ll v = ed[e].first , u = ed[e].second;
		if(z[v] > z[u]) swap(ed[e].first , ed[e].second);
		add(ed[e].first , w[e]);
	}
	ll q;
	cin>>q;
	for(ll i = 0 ; i < q ; i++){
		ll v , u;
		cin>>v>>u; v--;
		add(ed[v].first , u - w[v]);
		w[v] = u;
		cout<<fixed<<setprecision(15)<<ans<<'\n';
	}
	return 0;
}