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

vector<ll> v;

void solve(){
	v.clear();
	ll n , m , a , b;
	cin>>n>>m>>a>>b;
	if(a > b){
		a = n - a + 1;
		b = n - b + 1;
	}
	for(ll i = 0 ; i < m ; i++){
		ll h;
		cin>>h;
		v.push_back(h);
	}
	ll t = b - 1 , c = b - a - 1;
	sort(all(v));
	ll x = m - 1 , ans = 0;
	for(ll i = t ; i > t - c && i > 0 && x >= 0 ; i--){
		while(v[x] >= i && x >= 0){
			x--;
		}
		if(x >= 0){
			ans++;
			x--;
		}
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