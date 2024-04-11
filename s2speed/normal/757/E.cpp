#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;

const ll MAXN = 1e6 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

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

bitset<MAXN> gh;
ll d[MAXN] , dp[MAXN][20];

void prime(){
	gh.flip();
	memset(d , 0 , sizeof(d));
	for(ll i = 2 ; i < MAXN ; i++){
		if(!gh[i]) continue;
		d[i] = i;
		for(ll j = i * i ; j < MAXN ; j += i){
			gh[j] = false;
			d[j] = i;
		}
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	dp[0][0] = 1;
	for(int j = 1 ; j < 20 ; j++){
		dp[0][j] = 2;
	}
	for(int i = 1 ; i < MAXN ; i++){
		dp[i][0] = 1;
		for(int j = 1 ; j < 20 ; j++){
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % md;
		}
	}
	int q;
	cin>>q;
	while(q--){
		ll ans = 1 , r , n;
		cin>>r>>n;
		while(n != 1){
			ll c = d[n] , cnt = 0;
			while(n % c == 0){
				n /= c;
				cnt++;
			}
			ans *= dp[r][cnt]; ans %= md;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

/*

*/