#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 52 , md = 1e9 + 7;
ll inf;

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

ll a[maxn] , b[maxn] , c[maxn] , dp[maxn][maxn];
bitset<27> sl[maxn][maxn] , hl[maxn][maxn];
string s , h;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 63 , sizeof(dp)); inf = dp[0][0];
	ll n , m , q;
	cin>>s>>h>>q; n = sze(s); m = sze(h);
	for(ll i = 0 ; i < q ; i++){
		string inp;
		cin>>inp;
		a[i] = inp[0] - 'a';
		b[i] = inp[3] - 'a';
		c[i] = inp[4] - 'a';
	}
	for(ll i = 0 ; i < n ; i++){
		sl[i][i][s[i] - 'a'] = true;
	}
	for(ll l = 1 ; l < n ; l++){
		for(ll i = 0 ; i < n - l ; i++){
			for(ll k = i ; k < i + l ; k++){
				for(ll e = 0 ; e < q ; e++){
					if(sl[i][k][b[e]] & sl[k + 1][i + l][c[e]]){
						sl[i][i + l][a[e]] = true;
					}
				}
			}
		}
	}
	for(ll i = 0 ; i < m ; i++){
		hl[i][i][h[i] - 'a'] = true;
	}
	for(ll l = 1 ; l < m ; l++){
		for(ll i = 0 ; i < m - l ; i++){
			for(ll k = i ; k < i + l ; k++){
				for(ll e = 0 ; e < q ; e++){
					if(hl[i][k][b[e]] & hl[k + 1][i + l][c[e]]){
						hl[i][i + l][a[e]] = true;
					}
				}
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			bitset<27> tmp = sl[0][i] & hl[0][j];
			if(tmp.any()){
				dp[i][j] = 1;
				continue;
			}
			for(ll k = 1 ; k <= i ; k++){
				for(ll e = 1 ; e <= j ; e++){
					tmp = sl[k][i] & hl[e][j];
					if(tmp.any()){
						dp[i][j] = min(dp[i][j] , dp[k - 1][e - 1] + 1);
					}
				}
			}
		}
	}
	cout<<(dp[n - 1][m - 1] == inf ? -1 : dp[n - 1][m - 1])<<'\n';
	return 0;
}