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
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e2 + 15 , md = 1e9 + 7 , inf = 2e9;

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

ll cnt[MAXN];

void solve(){
	ll n , h , ans = 0 , x = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>h;
		cnt[h]++;
	}
	bool lock = false;
	for(ll i = 0 ; i < MAXN ; i++){
		if(cnt[i] >= 1){
			cout<<i<<' ';
			cnt[i]--;
		}
	}
	for(ll i = 0 ; i < MAXN ; i++){
		while(cnt[i]){
			cout<<i<<' ';
			cnt[i]--;
		}
	}
	cout<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/