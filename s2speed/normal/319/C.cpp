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

vector<plll> v;
ll dp[maxn] , a[maxn] , b[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i];
	}
	dp[0] = 0;
	v.push_back({0 , {b[0] , dp[0]}});
	for(ll i = 1 ; i < n ; i++){
		ll j = lower_bound(all(v) , mp(a[i] , mp(inf , inf))) - v.begin() - 1;
		dp[i] = 1ll * v[j].second.first * a[i] + v[j].second.second;
		ll t = 0;
		while(!v.empty()){
			ll x = v.back().first , h , o;
			h = 1ll * b[i] * x + dp[i];
			o = 1ll * v.back().second.first * x + v.back().second.second;
			if(h > o){
				ll q = v.back().second.first - b[i] , w = dp[i] - v.back().second.second;
				t = (w + q - 1) / q;
				break;
			}
			v.pop_back();
		}
		if(t <= 1e9) v.push_back({t , {b[i] , dp[i]}});
	}
//	for(auto p : v){
//		cout<<p.first<<' '<<p.second.first<<' '<<p.second.second<<'\n';
//	}
	cout<<dp[n - 1]<<'\n';
	return 0;
}