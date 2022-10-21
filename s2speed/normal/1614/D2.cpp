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

const ll maxn = 2e7 + 2 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn];
int cnt[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
//	memset(dp , 0 , sizeof(dp));
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		int h;
		cin>>h;
		cnt[h]++;
	}
	for(int i = 1 ; i < maxn ; i++){
		for(int j = i << 1 ; j < maxn ; j += i){
			cnt[i] += cnt[j];
		}
	}
	for(int i = maxn - 1 ; i ; i--){
		dp[i] = 1ll * cnt[i] * i;
		if(!cnt[i]) continue;
		for(int j = i << 1 ; j < maxn ; j += i){
			if(!cnt[j]) continue;
			ll h = dp[j] + 1ll * (cnt[i] - cnt[j]) * i;
			dp[i] = max(dp[i] , h);
		}
	}
	cout<<dp[1]<<'\n';
	return 0;
}