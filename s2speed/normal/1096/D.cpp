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

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 1e18;

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

ll dp[MAXN][5] , val[MAXN];
char c[] = {'h' , 'a' , 'r' , 'd' , '?'};

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	ll n;
	string s;
	cin>>n>>s;
	for(ll i = 0 ; i < n ; i++){
		cin>>val[i];
	}
	dp[0][0] = (s[0] == 'h') * val[0];
	for(ll i = 1 ; i < n ; i++){
		for(ll j = 0 ; j < 4 ; j++){
			dp[i][j] = dp[i - 1][j];
			if(s[i] == c[j]){
				dp[i][j] += val[i];
				if(j > 0) dp[i][j] = min(dp[i][j] , dp[i][j - 1]);
			}
		}
	}
	cout<<dp[n - 1][3]<<'\n';
	return 0;
}

/*

*/