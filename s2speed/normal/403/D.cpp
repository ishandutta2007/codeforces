#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pll;
typedef double db;

const ll MAX_N = 1000 + 20 , md = 1e9 + 7;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}
 
ll fact[MAX_N] , a[MAX_N];
 
void fact_build(){
    fact[0] = 1;
	a[0] = 1;
    for(int i = 1 ; i < MAX_N ; i++){
		fact[i] = fact[i - 1] * i;
		fact[i] %= md;
		a[i] = tav(fact[i] , md - 2);
    }
}
 
ll chs(ll n, ll k){
    if(k > n) return 0;
    return (((fact[n] * a[k]) % md) * a[n - k]) % md;
}


ll dp[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fact_build();
	for(int j = 0 ; j <= 1000 ; j++){
		for(int i = 0 ; i <= 1000 ; i++){
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for(int i = 1 ; i <= 1000 ; i++){
		dp[i][1] = 1;
	}
	for(int i = 1 ; i <= 1000 ; i++){
		for(int j = 2 ; j <= 1000 ; j++){
			ll h = 0;
			for(int k = 1 ; k * j <= i ; k++){
				ll q = dp[i - k * j][j - 1];
				if(q == 0){
					break;
				}
				h += q;
			}
			if(h == 0){
				break;
			}
			dp[i][j] = h % md;
		}
	}
	ll t;
	cin>>t;
	while(t--){
		ll n , k , ans = 0;
		cin>>n>>k;
		for(int i = (k - 1) * k / 2 ; i < n ; i++){
			ll z = dp[i][k] + dp[i][k - 1];
			z *= chs(n - i , k);
			z %= md;
			ans += z;
			ans %= md;
		}
		ans *= fact[k];
		ans %= md;
		cout<<ans<<'\n';
	}
	return 0;
}