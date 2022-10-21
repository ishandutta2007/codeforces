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

vector<pll> v;
vector<ll> c;
ll a[maxn] , b[maxn];
bitset<maxn> ans;

void solve(){
	v.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++) ans[i] = false;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		c.push_back(a[i]);
	}
	sort(all(c));
	for(ll i = 0 ; i < n ; i++){
		a[i] = lower_bound(all(c) , a[i]) - c.begin();
	}
	c.clear();
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i];
		c.push_back(b[i]);
	}
	sort(all(c));
	for(ll i = 0 ; i < n ; i++){
		b[i] = lower_bound(all(c) , b[i]) - c.begin();
	}
	c.clear();
	for(ll i = 0 ; i < n ; i++){
		v.push_back({a[i] , i});
	}
	sort(all(v));
	ll m = inf;
	for(ll j = n - 1 ; j >= 0 ; j--){
		ll i = v[j].second;
		ans[i] = true;
		m = min(m , b[i]);
		if(m == j) break;
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i];
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