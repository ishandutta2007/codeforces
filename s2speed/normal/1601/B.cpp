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

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

struct segtree {

	ll sz = 1;
	vector<vector<ll>> val;
	vector<ll> res;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.resize(sz << 1);
		return;
	}

	void add(ll l , ll r , ll k , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			val[x].push_back(k);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	void cal(ll i , ll x , ll lx , ll rx){
		for(auto v : val[x]){
			res.push_back(v);
		}
		val[x].clear();
		if(rx - lx == 1) return;
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			cal(i , ln , lx , m);
		} else {
			cal(i , rn , m , rx);
		}
		return;
	}

	void cal(ll i){
		res.clear();
		cal(i , 0 , 0 , sz);
		return;
	}

};

segtree st;
ll a[maxn] , b[maxn] , dp[maxn] , par[maxn];
vector<ll> adj[maxn] , u;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 63 , sizeof(dp));
	ll n;
	cin>>n;
	st.init(n + 1);
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		st.add(i - a[i] , i + 1 , i);
	}
	for(ll i = 1 ; i <= n ; i++){
		cin>>b[i];
		ll h = i + b[i];
		adj[h].push_back(i);
	}
	adj[0].push_back(0);
	u.push_back(0);
	dp[0] = 0;
	ll x = 0;
	while(x < sze(u)){
		ll v = u[x++];
		for(auto i : adj[v]){
			st.cal(i);
			for(auto j : st.res){
				if(dp[j] > dp[v] + 1){
					dp[j] = dp[v] + 1;
					u.push_back(j);
					par[j] = i;
				}
			}
		}
	}
	if(dp[n] > n){
		cout<<"-1\n";
		return 0;
	}
	cout<<dp[n]<<'\n';
	ll h = n;
	while(h > 0){
		cout<<par[h]<<' ';
		h = par[h]; h += b[h];
	}
	cout<<'\n';
	return 0;
}