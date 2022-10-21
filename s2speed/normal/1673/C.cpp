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

const ll maxn = 4e4 + 17 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn] , ps[maxn] , tv[6];

void solve(){
	ll n;
	cin>>n;
	cout<<dp[n]<<'\n';
	return;
}

vector<ll> v , u;

bool is_pal(ll x){
	u.clear();
	ll h = x;
	while(h > 0){
		u.push_back(h % 10);
		h /= 10;
	}
	reverse(all(u));
	ll us = sze(u);
	for(ll i = 0 ; i < us ; i++){
		h += tv[i] * u[i];
	}
	return (h == x);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	tv[0] = 1;
	for(ll i = 1 ; i < 6 ; i++){
		tv[i] = 10 * tv[i - 1];
	}
	dp[0] = 1;
	for(ll i = 1 ; i <= 4e4 ; i++){
		if(is_pal(i)) v.push_back(i);
	}
	for(auto k : v){
		for(ll i = 0 ; i < k ; i++) ps[i] = dp[i];
		for(ll i = k ; i <= 4e4 ; i++){
			ps[i] = ps[i - k] + dp[i]; ps[i] -= (ps[i] >= md) * md;
			dp[i] += ps[i - k]; dp[i] -= (dp[i] >= md) * md;
		}
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}