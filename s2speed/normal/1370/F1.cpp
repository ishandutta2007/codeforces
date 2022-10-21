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

const ll maxn = 1e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll n , lm , h;
vector<ll> adj[maxn] , o;
ll f[maxn] , dis[maxn] , dep = 0 , z[maxn];

void DFS(ll r , ll par){
	dis[r] = dep++;
	z[r] = 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
		z[r] += z[i];
	}
	dep--;
	return;
}

ll find_centroid(ll r , ll par){
	for(auto i : adj[r]){
		if(i == par) continue;
		if(z[i] > lm) return find_centroid(i , r);
	}
	return r;
}

bool check(ll x){
	o.clear();
	for(ll i = 0 ; i < n ; i++){
		if(dis[i] >= x) o.push_back(i);
	}
	if(o.empty()) return false;
	cout<<"? "<<sze(o)<<' ';
	for(auto i : o){
		cout<<i + 1<<' ';
	}
	cout<<endl;
	ll z;
	cin>>f[x]>>z; f[x]--;
	return (z == h);
}

void solve(){
	cin>>n; lm = n >> 1;
	for(ll i = 0 ; i < n ; i++) adj[i].clear();
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	cout<<"? "<<n<<' ';
	for(ll i = 1 ; i <= n ; i++){
		cout<<i<<' ';
	}
	cout<<endl;
	ll e;
	cin>>e>>h;
	DFS(0 , -1);
	ll c = find_centroid(0 , -1);
	DFS(c , -1);
	ll l = 0 , r = 502;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(m)){
			l = m;
		} else {
			r = m;
		}
	}
	ll v = f[l];
	DFS(v , -1);
	o.clear();
	for(ll i = 0 ; i < n ; i++){
		if(dis[i] == h) o.push_back(i);
	}
	cout<<"? "<<sze(o)<<' ';
	for(auto i : o){
		cout<<i + 1<<' ';
	}
	cout<<endl;
	ll u;
	cin>>u>>e; u--;
	cout<<"! "<<v + 1<<' '<<u + 1<<endl;
	string s;
	cin>>s;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}