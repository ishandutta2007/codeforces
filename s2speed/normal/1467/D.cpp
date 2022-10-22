#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 5e3 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

ll dp[MAX_N][MAX_N] , a[MAX_N] , pd[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , k , q , ans = 0;
	cin>>n>>k>>q;
	for(int i = 0 ; i < n ; i++){
		dp[0][i] = 1;
	}
	for(int j = 1 ; j <= k ; j++){
		dp[j][0] = dp[j - 1][1];
		dp[j][n - 1] = dp[j - 1][n - 2];
		for(int i = 1 ; i < n - 1 ; i++){
			dp[j][i] = dp[j - 1][i + 1] + dp[j - 1][i - 1]; dp[j][i] %= md;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j <= k ; j++){
			ll h = 1ll * dp[j][i] * dp[k - j][i] % md;
			pd[i] += h;
		}
		pd[i] %= md;
	}
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		ans += 1ll * a[i] * pd[i]; ans %= md;
	}
	while(q--){
		ll i , v;
		cin>>i>>v; i--;
		ll h = 1ll * (v - a[i]) * pd[i] % md; h += md; h %= md;
		ans += h; ans %= md;
		cout<<ans<<'\n';
		a[i] = v;
	}
	return 0;
}