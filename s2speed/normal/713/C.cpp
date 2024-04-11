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

const ll maxn = 3e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn][maxn] , a[maxn];
vector<pll> v[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 63 , sizeof(dp));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	dp[0][0] = 0;
	v[0].push_back({a[0] , 0});
	for(ll i = 1 ; i < n ; i++){
		for(ll j = 0 ; j < i ; j++){
			dp[i][j] = dp[i - 1][j] + abs(a[j] + i - j - a[i]);
			v[i].push_back({a[j] + i - j , dp[i][j]});
		}
		ll cur = 0;
		for(ll j = i ; j >= 0 ; j--){
			ll q = a[i] - (i - j);
			cur += abs(q - a[j]);
			if(!j){
				dp[i][i] = min(dp[i][i] , cur);
				break;
			}
			auto it = lower_bound(all(v[j - 1]) , mp(q , -1ll));
			if(it == v[j - 1].begin()) continue;
			it--;
			dp[i][i] = min(dp[i][i] , cur + (*it).second);
		}
		v[i].push_back({a[i] , dp[i][i]});
		sort(all(v[i]));
		for(ll j = 1 ; j <= i ; j++){
			v[i][j].second = min(v[i][j].second , v[i][j - 1].second);
		}
	}
	ll d = 4;
	for(ll j = 0 ; j <= d ; j++){
		cerr<<dp[d][j]<<' ';
	}
	cerr<<'\n';
	cout<<v[n - 1][n - 1].second<<'\n';
	return 0;
}