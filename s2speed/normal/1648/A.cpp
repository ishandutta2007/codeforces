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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

vector<vector<ll>> a;
vector<ll> v , x[maxn] , y[maxn];

void solve(){
	ll n , m;
	cin>>n>>m;
	a.resize(n);
	for(ll i = 0 ; i < n ; i++){
		a[i].resize(m);
		for(ll j = 0 ; j < m ; j++){
			cin>>a[i][j];
			v.push_back(a[i][j]);
		}
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			a[i][j] = lower_bound(all(v) , a[i][j]) - v.begin();
			x[a[i][j]].push_back(i);
			y[a[i][j]].push_back(j);
		}
	}
	ll vs = sze(v) , ans = 0 , ps;
	for(ll i = 0 ; i < vs ; i++){
		sort(all(x[i]));
		ps = 0;
		ll sz = sze(x[i]);
		for(ll j = 0 ; j < sz ; j++){
			ll h = j * x[i][j] - ps;
			ans += h;
			ps += x[i][j];
		}
		sort(all(y[i]));
		ps = 0;
		sz = sze(y[i]);
		for(ll j = 0 ; j < sz ; j++){
			ll h = j * y[i][j] - ps;
			ans += h;
			ps += y[i][j];
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	ll T;
//	cin>>T;
//	while(T--) 
	solve();
	return 0;
}