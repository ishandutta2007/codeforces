#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 11e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll inv[22][22] , dp[maxn] , a[maxn] , cnt[22];
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	memset(inv , 0 , sizeof(inv));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < 20 ; j++){
			if(a[i] == j) continue;
			inv[a[i]][j] += cnt[j];
		}
		cnt[a[i]]++;
	}
	dp[0] = 0;
	ll lm = (1 << 20);
	for(ll mask = 1 ; mask < lm ; mask++){
		for(ll j = 0 ; j < 20 ; j++){
			if(mask & (1 << j)) v.push_back(j);
		}
		dp[mask] = inf;
		for(auto i : v){
			ll h = 0;
			for(auto j : v){
				h += inv[i][j];
			}
			dp[mask] = min(dp[mask] , h + dp[mask - (1 << i)]);
		}
		v.clear();
	}
	cout<<dp[lm - 1]<<'\n';
	return 0;
}