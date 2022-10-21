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

const ll maxn = 1e5 + 16 , maxa = 8192 , md = 1e9 + 7 , inf = 5e18;

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

ll dp[maxa];
vector<ll> v[maxn] , ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 63 , sizeof(dp));
	dp[0] = -1;
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		v[h].push_back(i);
	}
	for(ll i = 0 ; i < maxa ; i++){
		v[i].push_back(inf);
	}
	for(ll i = 0 ; i < maxa ; i++){
		for(ll j = 0 ; j < maxa ; j++){
			ll k = lower_bound(all(v[i]) , dp[j]) - v[i].begin();
			dp[j ^ i] = min(dp[j ^ i] , v[i][k]);
		}
	}
	for(ll i = 0 ; i < maxa ; i++){
		if(dp[i] < n){
			ans.push_back(i);
		}
	}
	cout<<sze(ans)<<'\n';
	for(auto i : ans){
		cout<<i<<' ';
	}
	cout<<'\n';
	return 0;
}