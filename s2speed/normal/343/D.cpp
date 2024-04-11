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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e5 , md = 1e9 + 7 , inf = 2e16;

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

struct fentree {

	ll sz;
	vector<ll> val;

	void init(ll n){
		sz = n;
		val.assign(sz , 0);
		return;
	}

	void add(ll i , ll k){
		ll h = i;
		while(h < sz){
			val[h] += k;
			h |= (h + 1);
		}
		return;
	}

	ll cal(ll i){
		ll h = i , res = 0;
		while(h != -1){
			res += val[h];
			h &= (h + 1); h--;
		}
		return res;
	}

	ll cal(ll l , ll r){
		return cal(r - 1) - cal(l - 1);
	}

};

fentree st;
ll bt[maxn] , ft[maxn] , tme = 0 , pr[maxn];
set<ll> s;
vector<ll> adj[maxn];

void aDFS(ll r , ll par){
	bt[r] = tme++;
	pr[r] = par;
	for(auto i : adj[r]){
		if(i == par) continue;
		aDFS(i , r);
	}
	ft[r] = tme;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	aDFS(0 , -1);
	for(ll i = 0 ; i < n ; i++) s.insert(i); s.insert(inf);
	st.init(n);
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll t , i;
		cin>>t>>i; i--;
		if(t == 1){
			bool c = (st.cal(bt[i] , ft[i]) != (ft[i] - bt[i]));
			for(auto it = s.upper_bound(bt[i] - 1) ; *it < ft[i] ; it = s.erase(it)){
				st.add(*it , 1);
			}
			if(c && pr[i] != -1){
				ll h = st.cal(bt[pr[i]] , bt[pr[i]] + 1);
				if(h){
					s.insert(bt[pr[i]]);
					st.add(bt[pr[i]] , -1);
				}
			}
		}
		if(t == 2){
			ll h = st.cal(bt[i] , bt[i] + 1);
			s.insert(bt[i]);
			if(h) st.add(bt[i] , -1);
		}
		if(t == 3){
			cout<<(st.cal(bt[i] , ft[i]) == (ft[i] - bt[i]))<<'\n';
		}
	}
	return 0;
}