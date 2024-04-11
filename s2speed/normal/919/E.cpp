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

const ll maxn = 1e7 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll a , b , p , x , ans = 0;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= p;
		}
		n *= n; n %= p;
		k >>= 1;
	}
	return res;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>a>>b>>p>>x;
	ans += (p - 1) * (x / (1ll * p * (p - 1)));
	x %= 1ll * p * (p - 1);
	ll h = b , d = tav(a , p - 2);
	for(ll i = 1 ; i < p ; i++){
		h *= d; h %= p;
		ll o = i - h;
		if(o < 0) o += p;
		ll g = i + 1ll * (p - 1) * o;
		ans += (g <= x);
	}
	cout<<ans<<'\n';
	return 0;
}