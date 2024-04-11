#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e5 + 15 , MAXK = 1e2 + 15 , md = 998244353 , inf = 1e15;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

ll a[MAXN] , dp[MAXN][MAXK] , sum[MAXN] , last[MAXK];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	memset(sum , 0 , sizeof(sum));
	memset(last , -1 , sizeof(last));
	ll n , k , l;
	cin>>n>>k>>l;
	if(l == 1){
		cout<<"0\n";
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		if(a[i] > -1) a[i]--;
	}
	if(a[0] == -1){
		for(ll i = 0 ; i < k ; i++){
			dp[0][i] = 1;
		}
		sum[0] = k;
	} else {
		dp[0][a[0]] = 1;
		for(ll j = 0 ; j < k ; j++){
			if(j == a[0]) continue;
			last[j] = 0;
		}
		sum[0] = 1;
	}
	for(ll i = 1 ; i < n ; i++){
		if(a[i] != -1){
			for(ll j = 0 ; j < k ; j++){
				if(j == a[i]) continue;
				last[j] = i;
			}
			dp[i][a[i]] = sum[i - 1];
			if(last[a[i]] <= i - l){
				if(i - l == -1){
					dp[i][a[i]] += md - 1; dp[i][a[i]] %= md;
				} else {
					ll h = sum[i - l] - dp[i - l][a[i]] - md;
					dp[i][a[i]] -= h;
					dp[i][a[i]] %= md;
				}
			}
		} else {
			for(ll j = 0 ; j < k ; j++){
				dp[i][j] = sum[i - 1];
				if(last[j] <= i - l){
					if(i - l == -1){
						dp[i][j] += md - 1; dp[i][j] %= md;
					} else {
						ll h = sum[i - l] - dp[i - l][j] - md;
						dp[i][j] -= h;
						dp[i][j] %= md;
					}
				}
			}
		}
		for(ll j = 0 ; j < k ; j++){
			sum[i] += dp[i][j];
		}
		sum[i] %= md;
	}
	cout<<sum[n - 1]<<'\n';
	return 0;
}

/*

*/