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

const ll maxn = 6e4 + 16 , maxk = 1e3 + 16 , md = 1e9 + 7 , P = 1e7 + 19 , inf = 2e16;

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

ll n , k , q;
ll dp[17][maxk] , l[maxn] , r[maxn] , w[maxn] , v[maxn];
bitset<maxn> ask;

void upd(ll w , ll v , ll j){
	for(ll i = k ; i >= w ; i--){
		dp[j][i] = max(dp[j][i] , dp[j][i - w] + v);
	}
	return;
}

struct segtree {

	ll sz = 1;
	vector<vector<pll>> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.resize(sz << 1);
		return;
	}

	void add(ll l , ll r , pll k , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			val[x].push_back(k);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		return;
	}

	void add(ll l , ll r , pll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	void DFS(ll j , ll x , ll lx , ll rx){
		memcpy(dp[j] , dp[j - 1] , sizeof(dp[j]));
		for(auto p : val[x]){
			upd(p.first , p.second , j);
		}
		if(rx - lx == 1){
			if(ask[lx]){
				ll res = 0 , t = 1;
				for(ll i = 1 ; i <= k ; i++){
					ll h = t * dp[j][i] % md;
					res += h;
					t *= P; t %= md;
				}
				res %= md;
				cout<<res<<'\n';
			}
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		DFS(j + 1 , ln , lx , m); DFS(j + 1 , rn , m , rx);
		return;
	}

	void DFS(){
		memset(dp[0] , 0 , sizeof(dp[0]));
		DFS(1 , 0 , 0 , sz);
		return;
	}

};

segtree st;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		l[i] = 0;
		cin>>v[i]>>w[i];
	}
	ll q;
	cin>>q;
	fill(r , r + maxn - 1 , q);
	ll cur = n;
	for(ll e = 0 ; e < q ; e++){
		ll t;
		cin>>t;
		if(t == 3){
			ask[e] = true;
		} else if(t == 2){
			ll i;
			cin>>i; i--;
			r[i] = e;
		} else {
			cin>>v[cur]>>w[cur];
			l[cur++] = e;
		}
	}
	st.init(q);
	for(ll i = 0 ; i < cur ; i++){
		st.add(l[i] , r[i] , {w[i] , v[i]});
//		cout<<l[i]<<' '<<r[i]<<'\n';
	}
	st.DFS();
	return 0;
}