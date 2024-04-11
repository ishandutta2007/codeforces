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

const ll maxn = 5.1e3 + 17 , md = 998244353 , inf = 2e16;

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

ll chs[maxn][maxn] , dv[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	chs[0][0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		chs[i][0] = 1;
		for(ll j = 1 ; j <= i ; j++){
			chs[i][j] = chs[i - 1][j - 1] + chs[i - 1][j]; chs[i][j] -= (chs[i][j] >= md) * md;
		}
	}
	for(ll i = 1 ; i < maxn ; i++){
		dv[i] = tav(i , md - 2);
	}
	ll n , s , m;
	cin>>n>>m>>s; n--;
	ll res = 0;
	for(ll i = s ; i <= m ; i++){
		for(ll j = 0 ; j <= n ; j++){
			ll h = 0;
			for(ll k = 0 ; k + j <= n ; k++){
				ll o = m - (j + k + 1) * i , t = n - j;
				if(o < 0) break;
				ll f;
				if(t == 0){
					f = (o == 0);
				} else {
					f = chs[o + t - 1][t - 1] * chs[n - j][k] % md;
				}
				h += (1 - ((k & 1) << 1)) * f;
//				cout<<i<<' '<<j<<' '<<k<<' '<<o<<' '<<t<<' '<<f<<'\n';
			}
			h %= md; h += (h < 0) * md;
			h *= chs[n][j]; h %= md;
			h *= dv[1 + j]; h %= md;
			res += h; res %= md;
		}
	}
	ll k = chs[m - s + n][n];
	res *= tav(k , md - 2); res %= md;
	cout<<res<<'\n';
	return 0;
}