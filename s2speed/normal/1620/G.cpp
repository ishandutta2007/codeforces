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

const ll maxn = (1 << 23) + 16 , md = 998244353 , inf = 2e16;

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

string s;
ll a[maxn] , f[maxn];
short int h[maxn][26] , cnt[24][26];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	memset(h , 127 , sizeof(h));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>s;
		ll k = sze(s);
		for(ll j = 0 ; j < k ; j++){
			cnt[i][s[j] - 'a']++;
		}
	}
	ll lm = (1 << n);
	a[0] = 0;
	for(ll mask = 1 ; mask < lm ; mask++){
		for(ll i = 0 ; i < n ; i++){
			if(!(mask & (1 << i))) continue;
			ll msk = mask ^ (1 << i);
			for(ll j = 0 ; j < 26 ; j++){
				h[mask][j] = min(cnt[i][j] , h[msk][j]);
			}
		}
		ll z = 1 , c = __builtin_popcount(mask);
		for(ll j = 0 ; j < 26 ; j++){
			z *= h[mask][j] + 1; z %= md;
		}
		if(c & 1){
			a[mask] = z;
		} else {
			a[mask] = md - z;
		}
	}
	memcpy(f , a , sizeof(f));
	for(ll i = 0 ; i < n ; i++){
		for(ll mask = 0 ; mask < lm ; mask++){
			if(mask & (1 << i)){
				f[mask] += f[mask ^ (1 << i)];
				f[mask] -= (f[mask] >= md) * md;
			}
		}
	}
	ll ans = 0;
	for(ll mask = 0 ; mask < lm ; mask++){
		ll k = 0 , z = 0;
		for(ll i = 0 ; i < n ; i++){
			if(!(mask & (1 << i))) continue;
			z += i;
			k++;
		}
		z += k;
		ans ^= f[mask] * z * k;
	}
	cout<<ans<<'\n';
	return 0;
}