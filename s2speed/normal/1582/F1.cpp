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

const ll maxn = 1e5 + 16 , maxa = 525 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxa] , pd[maxa];
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 63 , sizeof(dp));
	memset(pd , 63 , sizeof(pd));
	dp[0] = 0;
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		for(ll j = 0 ; j < 512 ; j++){
			if(dp[j] < h){
				pd[j ^ h] = h;
			}
		}
		for(ll j = 0 ; j < 512 ; j++){
			dp[j] = min(dp[j] , pd[j]);
			pd[j] = inf;
		}
	}
	for(ll i = 0 ; i < 512 ; i++){
		if(dp[i] < maxa){
			v.push_back(i);
		}
	}
	cout<<sze(v)<<'\n';
	for(auto i : v){
		cout<<i<<' ';
	}
	cout<<'\n';
	return 0;
}