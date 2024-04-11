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

vector<ll> adj[maxn];
ll dis[maxn] , dep = 0 , par[maxn];
vector<pll> v;
bitset<maxn> s;

void tDFS(ll r){
	dis[r] = dep++;
	for(auto i : adj[r]){
		if(i == par[r]) continue;
		par[i] = r;
		tDFS(i);
	}
	dep--;
	return;
}

ll n , k;

bool check(ll x){
	if(x == 1){
		return false;
	}
	cout<<"? "<<x<<' ';
	for(ll i = 0 ; i < x ; i++){
		cout<<v[i].second<<' ';
	}
	cout<<endl;
	ll h;
	cin>>h;
	return (h == k);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	par[1] = -1;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	tDFS(1);
	for(ll i = 1 ; i <= n ; i++){
		v.push_back({dis[i] , i});
	}
	sort(all(v));
	cout<<"? "<<n<<' ';
	for(ll i = 1 ; i <= n ; i++){
		cout<<i<<' ';
	}
	cout<<endl;
	ll l = 1 , r = n;
	cin>>k;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(m)){
			r = m;
		} else {
			l = m;
		}
	}
	cout<<"! "<<v[l].second<<' '<<par[v[l].second]<<endl;
	return 0;
}