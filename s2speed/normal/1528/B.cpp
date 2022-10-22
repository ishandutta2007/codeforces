#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e6 + 16 , md = 998244353 , inf = 2e17;

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

ll dp[maxn] , cur = 1;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	for(ll i = 1 ; i < maxn ; i++){
		for(ll j = i ; j < maxn ; j += i){
			dp[j]++;
		}
	}
	for(ll i = 2 ; i < maxn ; i++){
		dp[i] += cur; if(dp[i] >= md) dp[i] -= md;
		cur += dp[i]; if(cur >= md) cur -= md;
	}
	ll n;
	cin>>n;
	cout<<dp[n]<<'\n';
	return 0;
}