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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

struct segtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		return;
	}

	void add(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] += k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			add(i , k , ln , lx , m);
		} else {
			add(i , k , rn , m , rx);
		}
		val[x] = val[ln] + val[rn];
		return;
	}

	void add(ll i , ll k){
		add(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1) return lx;
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(val[ln] >= k) return cal(k , ln , lx , m);
		return cal(k - val[ln] , rn , m , rx);
	}

	ll cal(ll k){
		if(val[0] < k) return -1;
		return cal(k , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
	}

};

segtree st;
set<ll> s[maxn];
ll a[maxn] , cnt[maxn] , res[maxn] , ans[maxn];
vector<ll> adj[maxn];
vector<plll> v[maxn];

void add(ll i){
	s[cnt[i]].erase(i);
	st.add(cnt[i] , -1);
	res[++cnt[i]]--;
	st.add(cnt[i] , 1);
	s[cnt[i]].insert(i);
	return;
}

void del(ll i){
	s[cnt[i]].erase(i);
	st.add(cnt[i] , -1);
	res[cnt[i]--]++;
	st.add(cnt[i] , 1);
	s[cnt[i]].insert(i);
	return;
}

void DFS(ll r){
	add(a[r]);
	for(auto q : v[r]){
		ll l = q.first.first , k = q.first.second , j = q.second;
		k += res[l];
		ll h = st.cal(k);
		if(h == -1){
			ans[j] = -2;
		} else {
			ll z = *(s[h].begin());
			ans[j] = z;
		}
	}
	for(auto i : adj[r]){
		DFS(i);
	}
	del(a[r]);
	return;
}

void solve(){
	st.clear();
	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	for(ll i = 0 ; i <= n ; i++){
		cnt[i] = 0; res[i] = n;
		adj[i].clear(); v[i].clear(); s[i].clear();
		if(i < n) s[0].insert(i);
	}
	res[0] = 0;
	st.init(n + 1);
	st.add(0 , n);
	for(ll i = 1 ; i < n ; i++){
		ll h;
		cin>>h; h--;
		adj[h].push_back(i);
	}
	for(ll i = 0 ; i < q ; i++){
		ll u , l , k;
		cin>>u>>l>>k; u--;
		v[u].push_back({{l , k} , i});
	}
	DFS(0);
	for(ll i = 0 ; i < q ; i++){
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