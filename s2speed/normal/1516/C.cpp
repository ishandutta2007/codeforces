#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e2 + 16 , maxa = 2e3 + 16 , md = 1e9 + 7 , inf = 2e18;

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

ll a[maxn] , b[maxn];
bitset<maxn> dp[maxn * maxa];

void solve(){
	ll n , s = 0 , m = inf , ind = -1;
	cin>>n;
	dp[0][0] = true;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i]; s += a[i];
		for(ll j = 0 ; j <= 10 ; j++){
			if(a[i] & (1 << j)){
				b[i] = j;
				break;
			}
		}
		if(b[i] < m){
			m = b[i];
			ind = i;
		}
	}
	for(ll i = 1 ; i <= n ; i++){
		ll lm = maxn * maxa;
		for(ll j = 0 ; j < lm ; j++){
			dp[i][j] = dp[i - 1][j] | (j >= a[i] ? dp[i - 1][j - a[i]] : false);
		}
	}
	if(s & 1 || !dp[n][s / 2]){
		cout<<"0\n";
		return;
	}
	cout<<"1\n"<<ind<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
//	ll T;
//	cin>>T;
//	while(T--){
		solve();
//	}
	return 0;
}