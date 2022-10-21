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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn] , cnt[maxn];
bitset<maxn> a;
vector<int> dv[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(ll i = 1 ; i < maxn ; i++){
		for(ll j = i ; j < maxn ; j += i){
			dv[j].push_back(i);
		}
	}
	memset(cnt , 0 , sizeof(cnt));
	memset(dp , 0 , sizeof(dp));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		cnt[h]++;
		a[h] = true;
	}
	for(ll i = 1 ; i < maxn ; i++){
		for(ll j = i << 1 ; j < maxn ; j += i){
			cnt[i] += cnt[j];
		}
		dp[i] = cnt[i] * (cnt[i] - 1) / 2;
	}
	ll ans = 0;
	for(ll i = 1e6 ; i ; i--){
		for(ll j = i << 1 ; j < maxn ; j += i){
			dp[i] -= dp[j];
		}
		if((dp[i] > 0) && !a[i]){
			ans++;
			for(auto j : dv[i]){
				dp[j] += cnt[j]++;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}