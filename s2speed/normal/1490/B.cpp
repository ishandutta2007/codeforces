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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 15 , MAX = 1e6 + 15 , md = 998244353 , inf = 1e15;
// check problem statement

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

void solve(){
	ll n , k , ans = 0 , cnt[] = {0 , 0 , 0};
	cin>>n; k = n / 3;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		cnt[h % 3]++;
	}
	for(ll i = 0 ; i < 6 ; i++){
		if(cnt[i % 3] > k){
			ll h = cnt[i % 3] - k;
			cnt[i % 3] =  k;
			ans += h;
			cnt[(i + 1) % 3] += h;
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/