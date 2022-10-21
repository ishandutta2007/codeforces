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

const ll maxn = 2e5 + 16 , md = 998244353 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll lcm(ll a , ll b){
	ll res = 1ll * a * b / gcd(a , b);
	return res;
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

vector<pll> v , u;
ll a[maxn];

void solve(){
	v.clear();
	ll ans = 0 , n , o = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = n - 1 ; i >= 0 ; i--){
		u.push_back({a[i] , 1});
		ans += o;
		for(auto p : v){
			ll c = p.first , t = p.second;
			ll q = (a[i] + c - 1) / c;
			ll y = a[i] / q;
			ll h = 1ll * (q - 1) * t % md;
			o += h;
			ans += h;
			if(u.back().first == y){
				u.back().second += t;
			} else {
				u.push_back({y , t});
			}
		}
		v = u; u.clear();
		ans %= md; o %= md;
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