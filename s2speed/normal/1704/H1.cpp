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

const ll maxn = 5e3 + 17 , inf = 2e16;
ll md;

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

ll fact[maxn] , _fact[maxn] , chs[maxn][maxn] , tv[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n>>md;
	fact[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		fact[i] = fact[i - 1] * i % md;
	}
	_fact[maxn - 1] = tav(fact[maxn - 1] , md - 2);
	for(ll i = maxn - 2 ; ~i ; i--){
		_fact[i] = _fact[i + 1] * (i + 1) % md;
	}
	chs[0][0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		chs[i][0] = 1;
		for(ll j = 1 ; j <= i ; j++){
			ll h = chs[i - 1][j - 1] + chs[i - 1][j];
			h -= (h >= md) * md;
			chs[i][j] = h;
		}
	}
	for(ll i = 1 ; i < maxn ; i++){
		tv[i][0] = 1;
		for(ll j = 1 ; j < maxn ; j++){
			tv[i][j] = tv[i][j - 1] * i % md;
		}
	}
	ll res = 0;
	for(ll i = 1 ; i <= n ; i++){
		for(ll j = i ; j + i <= n ; j++){
			ll k = n - (i + j);
			ll h = chs[n][i] * fact[n - i] % md * _fact[k] % md * chs[j - 1][i - 1] % md * tv[n - 1][i] % md * tv[j][k] % md;
			res += h;
		}
	}
	res %= md;
	cout<<res<<'\n';
	return 0;
}