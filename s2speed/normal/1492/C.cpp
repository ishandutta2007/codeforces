#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	return ((b == 0) ? a : gcd(b , a % b));
}

const ll MAXN = 2e5 + 15 , md = 1e6 + 3 , inf = 1e18;

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

ll dp[MAXN] , pd[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s , t;
	ll n , m , ans = 0;
	cin>>n>>m>>s>>t;
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == t[0]){
			dp[0] = i;
			break;
		}
	}
	ll x = 1;
	for(ll i = dp[0] + 1 ; i < n && x < m ; i++){
		if(s[i] == t[x]){
			dp[x] = i;
			x++;
		}
	}
	for(ll i = n - 1 ; i >= 0 ; i--){
		if(s[i] == t[m - 1]){
			pd[m - 1] = i;
			break;
		}
	}
	x = m - 2;
	for(ll i = pd[m - 1] - 1 ; i >= 0 && x >= 0 ; i--){
		if(s[i] == t[x]){
			pd[x] = i;
			x--;
		}
	}
	for(ll i = 1 ; i < m ; i++){
		ans = max(ans , pd[i] - dp[i - 1]);
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/