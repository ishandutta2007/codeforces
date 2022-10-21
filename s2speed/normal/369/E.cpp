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

vector<ll> merge(vector<ll> a , vector<ll> b){
	vector<ll> res;
	ll x = sze(a) , y = sze(b);
	a.push_back(inf); b.push_back(inf);
	for(ll i = 0 ; i < x + y ; i++){
		if(a[x] < b[y]){
			res.push_back(a[x++]);
		} else {
			res.push_back(b[y++]);
		}
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

	void add(ll i){
		ll h = i;
		while(h < sz){
			val[h]++;
			h |= h + 1;
		}
		return;
	}

	ll cal(ll i){
		ll h = i , res = 0;
		while(h != -1){
			res += val[h];
			h &= h + 1;	h--;
		}
		return res;
	}	

};

fentree ft;
vector<pll> a , b[maxn];
vector<ll> v;
ll ans[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , q;
	cin>>n>>q;
	ft.init(maxn);
	for(ll i = 0 ; i < n ; i++){
		ll l , r;
		cin>>l>>r;
		a.push_back({r , l});
	}
	sort(all(a));
	fill(ans , ans + q , n);
	for(ll e = 0 ; e < q ; e++){
		ll k;
		cin>>k;
		v.clear(); v.push_back(0);
		for(ll i = 0 ; i < k ; i++){
			ll h;
			cin>>h;
			v.push_back(h);
		} v.push_back(maxn);
		for(ll i = 1 ; i < k + 2 ; i++){
			ll j = lower_bound(all(a) , mp(v[i] , -1ll)) - a.begin() - 1;
			if(~j) b[j].push_back({v[i - 1] , e});
		}
	}
	for(ll i = 0 ; i < n ; i++){
		ft.add(a[i].second);
		for(auto p : b[i]){
			ll j = p.second , l = p.first;
			ans[j] -= i + 1 - ft.cal(l);
		}
	}
	for(ll i = 0 ; i < q ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}