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

vector<ll> adj[maxn] , d[20] , b[2];
bool dep = false;
ll ans[maxn];
bitset<20> c;

void bDFS(ll r , ll par){
	b[dep].push_back(r); dep ^= 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		bDFS(i , r);
	}
	dep ^= 1;
	return;
}

void solve(){
	b[0].clear(); b[1].clear();
	for(ll j = 0 ; j < 20 ; j++) d[j].clear();
	c.reset();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++) adj[i].clear();
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	ll h = 0 , j = -1;
	for(ll i = 0 ; i < n ; i++){
		if(i == h){
			j++;
			h <<= 1; h++;
		}
		d[j].push_back(i);
	}
	bDFS(0 , -1);
	ll s0 = sze(b[0]) , s1 = sze(b[1]) , m = min(s0 , s1);
	bool ch = (s1 < s0);
	for(ll j = 0 ; j < 20 ; j++){
		if((1 << j) & m){
			c[j] = true;
		}
	}
	ll x[] = {0 , 0};
	for(ll j = 0 ; j < 20 ; j++){
		bool k = ch ^ !c[j];
		for(auto i : d[j]){
			ans[b[k][x[k]++]] = i;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i] + 1<<' ';
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