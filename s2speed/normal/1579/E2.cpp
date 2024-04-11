#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
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

struct fentree{

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
			h |= (h + 1);
		}
		return;
	}

	ll cal(ll i){
		ll res = 0 , h = i;
		while(h > -1){
			res += val[h];
			h &= (h + 1); h--;
		}
		return res;
	}

	void clear(){
		val.clear();
		return;
	}

};

fentree ft;
vector<ll> v;
ll a[maxn] , cnt[maxn];

void solve(){
	ft.clear();
	v.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cnt[i] = 0;
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	ft.init(sze(v));
	for(ll i = 0 ; i < n ; i++){
		a[i] = lower_bound(all(v) , a[i]) - v.begin();
	}
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		ll h = ft.cal(a[i] - 1);
		ans += min(h , i - cnt[a[i]] - h);
		ft.add(a[i]);
		cnt[a[i]]++;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}