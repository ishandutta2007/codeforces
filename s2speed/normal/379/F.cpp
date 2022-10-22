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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e17;

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

vector<ll> adj[maxn] , t;
ll jad[maxn][20] , dis[maxn] , dep = 0;

void aDFS(ll r , ll par){
	dis[r] = dep++;
	jad[r][0] = par;
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	for(auto i : adj[r]){
		aDFS(i , r);
	}
	dep--;
	return;
}

ll find_jad(ll v , ll d){
	d = dis[v] - d;
	for(ll j = 0 ; j < 20 ; j++){
		if((1 << j) & d){
			v = jad[v][j];
		}
	}
	return v;
}

ll lca(ll v , ll u){
	if(dis[v] > dis[u]) swap(v , u);
	u = find_jad(u , dis[v]);
	if(v == u) return v;
	for(ll j = 19 ; j >= 0 ; j--){
		if(jad[v][j] != jad[u][j]){
			v = jad[v][j];
			u = jad[u][j];
		}
	}
	return jad[v][0];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(jad , -1 , sizeof(jad));
	adj[0].push_back(1); adj[0].push_back(2); adj[0].push_back(3);
	ll q;
	cin>>q;
	for(ll i = 0 ; i < q ; i++){
		ll h;
		cin>>h; h--;
		adj[h].push_back(2 * i + 4); adj[h].push_back(2 * i + 5);
		t.push_back(2 * i + 4);
	}
	aDFS(0 , -1);
	ll v = 1 , u = 2 , ans = 2;
	for(auto r : t){
		ll h = dis[r] + dis[v] - 2 * dis[lca(r , v)];
		if(h > ans){
			ans++;
			u = r;
			cout<<ans<<'\n';
			continue;
		}
		h = dis[r] + dis[u] - 2 * dis[lca(r , u)];
		if(h > ans){
			ans++;
			v = r;
			cout<<ans<<'\n';
			continue;
		}
		cout<<ans<<'\n';
	}
	return 0;
}