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

const ll maxn = 5e2 + 17 , inf = 2e16;
ll md;

ll chs[maxn][maxn];
ll f[maxn] , g[maxn] , dp[maxn][maxn] , pd[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m;
	cin>>n>>m>>md;
	chs[0][0] = 1;
	for(ll i = 1 ; i <= n ; i++){
		chs[i][0] = 1;
		for(ll j = 1 ; j <= i ; j++){
			chs[i][j] = chs[i - 1][j - 1] + chs[i - 1][j]; chs[i][j] -= (chs[i][j] >= md) * md;
		}
	}
	f[0] = 1;
	for(ll i = 1 ; i <= n ; i++){
		ll h = 0 , o = 0;
		for(ll j = 0 ; j <= i - 1 ; j++){
			ll t = f[j] * f[i - 1 - j] % md * chs[i - 1][j] % md;
			h += (i + 1) * t;
			ll s = (j * (j + 1) + (i - 1 - j) * (i - j)) / 2;
			o += s * t % md + (g[j] * f[i - 1 - j] % md + g[i - 1 - j] * f[j] % md) * (i + 1) % md * chs[i - 1][j] % md;
		}
		f[i] = h % md;
		g[i] = o % md;
	}
//	for(ll i = 0 ; i <= n ; i++){
//		cout<<f[i]<<' '<<g[i]<<'\n';
//	}
	pd[0][0] = 1;
	for(ll i = 1 ; i <= n ; i++){
		dp[i][0] = 0; pd[i][0] = 1;
		for(ll j = 1 ; j <= i ; j++){
			ll h = pd[i - 1][j];
			for(ll k = 1 ; k < j ; k++){
				ll o = pd[i - k - 1][j - k] * f[k] % md * chs[m - j + k][k] % md;
				h += o;
			}
			h += f[j] * chs[m][j] % md;
			pd[i][j] = h % md;
			h = dp[i - 1][j];
			for(ll k = 1 ; k < j ; k++){
				ll o = (pd[i - k - 1][j - k] * g[k] + dp[i - k - 1][j - k] * f[k]) % md * chs[m - j + k][k] % md;
//				if(i == 4 && j == 3){
//					cout<<pd[i - k - 1][j - k]<<' '<<g[k]<<' '<<dp[i - k - 1][j - k]<<' '<<f[k]<<' '<<o<<'\n';
//				}
				h += o;
			}
			h += g[j] * chs[m][j] % md;
			dp[i][j] = h % md;
		}
	}
//	wall;
//	for(ll i = 0 ; i <= n ; i++){
//		for(ll j = 0 ; j <= m ; j++){
//			cout<<pd[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	cout<<dp[n][m]<<'\n';
	return 0;
}

/*
4 3 10000000
*/