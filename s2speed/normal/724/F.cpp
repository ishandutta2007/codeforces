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

const ll maxn = 1e4 + 17 , inf = 2e16;
ll md;

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

ll dp[maxn][11] , pd[maxn][11] , f[maxn] , inv[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	ll n , d;
	cin>>n>>d>>md;
	if(n == 1){
		cout<<"1\n";
		return 0;
	}
	inv[1] = 1;
	for(ll i = 2 ; i < maxn ; i++){
		inv[i] = tav(i , md - 2);
	}
	ll lm = (n - 1) / 2;
	pd[1][0] = 1; f[1] = 1;
	for(ll k = 1 ; k <= lm ; k++){
		for(ll i = 1 ; i <= n ; i++){
			for(ll j = 0 ; j <= d ; j++){
				ll z = 1 , h = 0 , d = f[k];
				h += pd[i][j];
				for(ll t = 1 , s = i - k ; t <= j && s >= 1 ; t++ , s -= k){
//				if(k == 2 && i == 5 && j == 2){
//					cout<<t<<' '<<z<<' '<<s<<' '<<d<<'\n';
//				}
					z *= d; z %= md;
					z *= inv[t]; z %= md;
					d++;
					h += 1ll * z * pd[s][j - t] % md;
				}
				dp[i][j] = h % md;
			}
		}
		f[k + 1] = dp[k + 1][d - 1];
		memcpy(pd , dp , sizeof(pd));
	}
	ll ans = pd[n][d];
	if(!(n & 1)){
		ll d = f[n / 2] , h = d * (d + 1) / 2;
		ans += h; ans %= md;
	}
	cout<<ans<<'\n';
	return 0;
}