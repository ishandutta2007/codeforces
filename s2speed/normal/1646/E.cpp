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

const ll maxn = 1e3 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll lcm(ll a , ll b){
	return 1ll * a * b / gcd(a , b);
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

ll f[21];
bitset<maxn * maxn> mark;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m;
	cin>>n>>m;
	for(ll i = 1 ; i < 21 ; i++){
		ll lm = (1 << i) , res = 0;
		for(ll mask = 1 ; mask < lm ; mask++){
			ll h = 1 , cnt = 0 , mn = inf;
			for(ll j = 0 ; j < i ; j++){
				if(mask & (1 << j)){
					mn = min(mn , j + 1);
					cnt ^= 1;
					h = lcm(h , j + 1);
				}
			}
			ll t = m / (h / mn);
			res += t * (-1 + (cnt << 1));
		}
		f[i] = res;
	}
	ll ans = 1;
	for(ll i = 2 ; i <= n ; i++){
		if(mark[i]) continue;
		ll h = i;
		ll cnt = 0;
		while(h <= n){
			cnt++;
			mark[h] = true;
			h *= i;
		}
		ans += f[cnt];
	}
	cout<<ans<<'\n';
	return 0;
}