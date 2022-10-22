#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e6 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , cnt[] = {0 , 0 , 0 , 0};
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll x , y;
		cin>>x>>y;
		x %= 4; y %= 4;
		if(x == 0){
			x = 1;
		} else {
			x = 0;
		}
		if(y == 0){
			y = 1;
		} else {
			y = 0;
		}
		cnt[x + 2 * y]++;
	}
	ll ans = 1ll * n * (n - 1) * (n - 2) / 6;
	ans -= 1ll * cnt[0] * cnt[1] * cnt[2];
	ans -= 1ll * cnt[0] * cnt[1] * cnt[3];
	ans -= 1ll * cnt[0] * cnt[2] * cnt[3];
	ans -= 1ll * cnt[1] * cnt[2] * cnt[3];
	cout<<ans<<'\n';
	return 0;
}