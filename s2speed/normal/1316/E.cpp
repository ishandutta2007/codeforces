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

const ll maxn = 1e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn][136] , a[maxn] , b[maxn][7];
vector<pll> c;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , -15 , sizeof(dp));
	ll n , p , k;
	cin>>n>>p>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		c.push_back({a[i] , i});
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < p ; j++){
			cin>>b[i][j];
		}
	}
	ll lm = (1 << p);
	sort(all(c) , greater<pll>());
	dp[0][0] = 0;
	for(ll e = 1 ; e <= n ; e++){
		ll i = c[e - 1].second;
		for(ll mask = 0 ; mask < lm ; mask++){
			ll cnt = 0 , h = -inf;
			for(ll j = 0 ; j < p ; j++){
				if(mask & (1 << j)){
					h = max(h , dp[e - 1][mask ^ (1 << j)] + b[i][j]);
					cnt++;
				}
			}
			h = max(h , dp[e - 1][mask] + (e - cnt <= k) * a[i]);
			dp[e][mask] = h;
		}
	}
	cout<<dp[n][lm - 1]<<'\n';
	return 0;
}