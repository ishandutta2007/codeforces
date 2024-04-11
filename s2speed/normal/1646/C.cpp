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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll bp(ll p){
	ll o = 1 , cnt = 0;
	for(int i = 0 ; i < 63 ; i++){
		if(o & p) cnt++;
		o <<= 1;
	}
	return cnt;
}

ll fact[15];

void solve(){
	ll n;
	cin>>n;
	ll lm = (1 << 12);
	ll ans = inf;
	for(ll mask = 0 ; mask < lm ; mask++){
		ll h = 0 , res = 0;
		for(ll j = 0 ; j < 12 ; j++){
			if(mask & (1 << j)){
				h += fact[j];
				res++;
			}
		}
		res += bp(n - h);
		ans = min(ans , res);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact[0] = 6;
	for(ll i = 1 ; i < 12 ; i++){
		fact[i] = fact[i - 1] * (i + 3);
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}