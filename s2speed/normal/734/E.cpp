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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 5e18;

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

ll ds[maxn];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	ds[u] = v;
	return;
}

bitset<maxn> c;
vector<pll> ed;
vector<ll> adj[maxn];
ll d[maxn] , dep = 0 , h = 0;

void dDFS(ll r , ll par){
	d[r] = dep++;
	for(auto i : adj[r]){
		if(i == par) continue;
		dDFS(i , r);
		d[r] = max(d[r] , d[i]);
	}
	dep--;
	return;
}

ll aDFS(ll r , ll par){
	ll j = -1;
	for(auto i : adj[r]){
		if(i == par) continue;
		if(j == -1 && d[i] == d[r]){
			j = i;
		} else {
			h = max(h , d[i] - dep);
		}
	}
	if(h >= d[r] - dep - 1) return d[r] - dep;
	dep++; h++;
	return aDFS(j , r);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		bool h;
		cin>>h;
		c[i] = h;
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		ed.push_back({v , u});
	}
	iota(ds , ds + n , 0);
	for(auto p : ed){
		ll v = p.first , u = p.second;
		if(c[v] == c[u]) merge(v , u);
	}
	for(auto p : ed){
		ll v = p.first , u = p.second;
		if(c[v] != c[u]){
			v = dsu(v); u = dsu(u);
			adj[v].push_back(u); adj[u].push_back(v);
		}
	}
	dDFS(dsu(0) , -1);
	cout<<aDFS(dsu(0) , -1)<<'\n';
	return 0;
}