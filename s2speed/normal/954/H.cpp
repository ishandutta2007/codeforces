#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e4 + 17 , md = 1e9 + 7 , inf = 2e16;

inline ll tav(ll n , ll k){
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

ll a[maxn];
ll ans[maxn] , cur[maxn] , bp[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fill(bp , bp + maxn , 1);
	ll n , dv = tav(2 , md - 2);
	cin>>n; n--;
	ll lm = (n << 1);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ans[0] = cur[0] = 1;
	ll sz = 1;
	for(ll i = 0 ; i < n ; i++){
		sz *= a[i]; sz %= md;
		for(ll j = 0 ; j < i ; j++){
			bp[j] *= a[i]; bp[j] %= md;
		}
		bp[i] *= a[i] - 1; bp[i] %= md;
		for(ll j = 2 * i + 2 ; j > 0 ; j--){
			cur[j] = cur[j - 1];
		}
		ll lm = ((i + 1) << 1);
		for(ll j = 0 ; j <= lm ; j++){
			ans[j] += cur[j] * sz % md;
		}
		for(ll j = i ; ~j ; j--){
			ll d = 2 * (i + 1 - j);
			cur[d] += bp[j]; cur[d] %= md;
			ans[d] += bp[j] * sz % md * dv % md;
		}
//		for(ll j = 0 ; j <= lm ; j++){
//			cout<<cur[j]<<' ';
//		}
//		cout<<'\n';
	}
	for(ll i = 1 ; i <= lm ; i++){
		ans[i] %= md;
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}

/*
19
942 948 298 402 80 358 605 781 206 257 608 28 714 984 267 633 894 734 866
*/