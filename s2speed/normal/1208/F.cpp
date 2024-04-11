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

const ll maxn = (1 << 21) + 16 , md = 1e9 + 7 , inf = 2e16;

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

pll dp[maxn];

pll operator+ (pll a , pll b){
	pll res;
	if(a.first > b.first){
		res.first = a.first;
		res.second = max(a.second , b.first);
	} else if(a.first < b.first) {
		res.first = b.first;
		res.second = max(a.first , b.second);
	} else {
		res.first = a.first;
		res.second = max(a.second , b.second);
	}
	return res;
}

void operator+= (pll &a , pll b){
	a = a + b;
	return;
}

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , -1 , sizeof(dp));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = n - 1 ; i >= 0 ; i--){
		if(dp[a[i]].first == -1){
			dp[a[i]].first = i;
		} else if(dp[a[i]].second == -1){
			dp[a[i]].second = i;
		}
	}
	ll lm = (1 << 21) - 1;
	for(ll j = 0 ; j < 21 ; j++){
		for(ll mask = 0 ; mask <= lm ; mask++){
			if(!(mask & (1 << j))){
				dp[mask] += dp[mask ^ (1 << j)];
			}
		}
	}
	ll ans = 0;
	for(ll i = 0 ; i < n - 2 ; i++){
		ll res = 0;
		for(ll j = 20 ; j >= 0 ; j--){
			ll o = (1 << j) , h = res ^ o;
			if(a[i] & o) continue;
			if(dp[h].second > i){
				res ^= o;
			}
		}
		ans = max(ans , res ^ a[i]);
	}
	cout<<ans<<'\n';
	return 0;
}

/*
3
0 5 6
*/