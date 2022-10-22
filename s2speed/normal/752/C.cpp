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

const ll MAXN = 2e5 + 15 , md = 998244353 , inf = 1e15;

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

ll dp[MAXN] , last[] = {-1 , -1 , -1 , -1};

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	string s;
	cin>>n>>s;
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == 'R'){
			last[0] = i;
		}
		if(s[i] == 'L'){
			last[1] = i;
		}
		if(s[i] == 'U'){
			last[2] = i;
		}
		if(s[i] == 'D'){
			last[3] = i;
		}
		ll a = min(last[0] , last[1]) , b = min(last[2] , last[3]) , j = max(a , b);
		if(j == -1){
			dp[i] = 1;
		} else {
			dp[i] = dp[j] + 1;
		}
	}
	cout<<dp[n - 1]<<'\n';
	return 0;
}

/*

*/