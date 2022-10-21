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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

struct fentree {

	ll sz;
	vector<ll> val;

	void init(ll n){
		val.assign(n , 0);
		sz = n;
		return;
	}

	void set(ll i , ll k){
		ll h = i;
		while(h < sz){
			val[h] += k;
			h |= (h + 1);
		}
		return;
	}

	ll cal(ll i){
		ll h = i , res = 0;
		while(~h){
			res += val[h];
			h &= (h + 1); h--;
		}
		return res % md;
	}

	ll cal(ll l , ll r){
		ll res = cal(r - 1) - cal(l - 1);
		res += (res < 0) * md;
		return res;
	}

	void clear(){
		val.clear();
		return;
	}

};

fentree ft , ht;
ll a[maxn] , p[maxn] , g[maxn] , h[maxn] , f[maxn] , b[maxn];
vector<pll> v;

void solve(){
	v.clear(); ft.clear(); ht.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back({a[i] , -i});
	}
	sort(all(v));
	for(ll i = 0 ; i < n ; i++){
		a[-v[i].second] = i;
		p[i] = -v[i].second;
	}
	ft.init(n);
	for(ll i = 0 ; i < n ; i++){
		g[i] = 1 + ft.cal(a[i]);
		ft.set(a[i] , g[i]);
	}
	ll mx = -1;
	for(ll i = n - 1 ; ~i ; i--){
		if(a[i] > mx){
			for(ll j = mx + 1 ; j <= a[i] ; j++){
				b[p[j]] = i;
			}
			mx = a[i];
		}
	}
	ft.clear();
	ft.init(n);
	ht.init(n);
	for(ll i = n - 1 ; ~i ; i--){
		h[i] = 1 + ht.cal(a[i] , n);
		ht.set(a[i] , h[i]);
		f[i] = ht.cal(a[b[i]] + 1 , n) + ft.cal(a[i] , a[b[i]]) + (i != b[i]); f[i] -= (f[i] >= md) * md;
		ft.set(a[i] , f[i]);
	}
//	for(ll i = 0 ; i < n ; i++){
//		cout<<f[i]<<' ';
//	}
//	cout<<'\n';
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		ans += f[i] * g[i] % md;
	}
	ans %= md;
	cout<<ans<<'\n';
	return;
}

/*
1
5
6 4 8 6 5
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}