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

const ll maxn = 24 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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

ll dv;

ll chs(ll n , ll k){
	if(k > n) return 0;
	ll res = 1;
	for(ll i = n ; i > n - k ; i--){
		res *= i % md; res %= md;
	}
	return res * dv % md;
}

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , s , ans = 0;
	cin>>n>>s;
	dv = 1;
	for(ll i = 2 ; i < n ; i++){
		dv *= tav(i , md - 2); dv %= md;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]++;
	}
	ll lm = (1 << n);
	for(ll mask = 0 ; mask < lm ; mask++){
		ll h = 0 , cnt = 0;
		for(ll j = 0 ; j < n ; j++){
			if(mask & (1 << j)){
				h += a[j];
				cnt ^= 1;
			}
		}
		ans += (1 - (cnt << 1)) * chs(s - h + n - 1 , n - 1);
	}
	ans %= md; ans += (ans < 0) * md;
	cout<<ans<<'\n';
	return 0;
}