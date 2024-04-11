#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e3 + 16 , md = 998244353 , inf = 2e18;

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

ll a[maxn] , ans[maxn] , z[maxn][maxn] , t[maxn] , _t[maxn] , cnt[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , c;
	cin>>n>>c;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	if(c <= 10){
		ll dp[n / c + 5][(1 << c) + 5] , pd[n / c + 5][(1 << c) + 5] , lm = (1 << c);
		memset(pd , 0 , sizeof(pd));
		pd[0][0] = pd[0][1 << a[0]] = 1;
		if(c == 1) pd[1][0] = 1;
		for(ll i = 1 ; i < n ; i++){
			memset(dp , 0 , sizeof(dp));
			ll cl = i / c;
			for(ll j = 0 ; j <= cl ; j++){
				for(ll mask = 0 ; mask < lm - 1 ; mask++){
					dp[j][mask] += pd[j][mask]; if(dp[j][mask] >= inf) dp[j][mask] %= md;
					dp[j][mask | (1 << a[i])] += pd[j][mask]; if(dp[j][mask | (1 << a[i])] >= inf) dp[j][mask | (1 << a[i])] %= md;
				}
			}
			for(ll j = 0 ; j <= cl ; j++){
				dp[j + 1][0] += dp[j][lm - 1]; if(dp[j + 1][0] >= inf) dp[j + 1][0] %= md;
			};
			memcpy(pd , dp , sizeof(pd));
		}
		memset(ans , 0 , sizeof(ans));
		for(ll j = 0 ; j <= n / c ; j++){
			for(ll mask = 0 ; mask < lm - 1 ; mask++){
				ans[j] += pd[j][mask]; if(ans[j] >= inf) ans[j] %= md;
			}
			if(!j) ans[j]--;
			ans[j] %= md; if(ans[j] < 0) ans[j] += md;
		}
		for(ll j = 0 ; j <= n / c ; j++){
			cout<<ans[j]<<' ';
		}
		for(ll j = n / c + 1 ; j <= n ; j++){
			cout<<"0 ";
		}
		cout<<'\n';
		return 0;
	}
	ll dp[n + 5][n / c + 5];
	t[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		t[i] = ((t[i - 1] + 1) << 1) - 1; if(t[i] >= md) t[i] %= md;
		_t[i] = tav(t[i] , md - 2);
	}
	memset(z , 0 , sizeof(z));
	for(ll i = 0 ; i < n ; i++){
		memset(cnt , 0 , sizeof(cnt));
		ll tnc = 1 , h = 1;
		z[i][i] = 0;
		cnt[a[i]]++;
		for(ll j = i + 1 ; j < n ; j++){
			cnt[a[j]]++;
			if(cnt[a[j]] == 1){
				tnc++;
			} else {
				h *= _t[cnt[a[j]] - 1]; h %= md;
				h *= t[cnt[a[j]]]; h %= md;
			}
			if(tnc < c){
				z[i][j] = 0;
				continue;
			}
			z[i][j] = 1ll * h * _t[cnt[a[j]]] % md;
		}
	}
	memset(dp , 0 , sizeof(dp));
	for(ll i = 0 ; i < n ; i++){
		dp[i][1] = z[0][i];
	}
	for(ll k = 2 ; k <= n / c ; k++){
		for(ll i = 0 ; i < n ; i++){
			for(ll j = i + 1 ; j < n ; j++){
				dp[j][k] += 1ll * z[i + 1][j] * dp[i][k - 1]; dp[j][k] %= md;
			}
		}
	}
	ans[0] = t[n];
	for(ll j = 1 ; j <= n / c ; j++){
		for(ll i = 0 ; i < n ; i++){
			ans[j] += 1ll * dp[i][j] * (t[n - i - 1] + 1) % md;
		}
		ans[j] %= md;
	}
	for(ll j = 1 ; j <= n / c ; j++){
		ans[j - 1] -= ans[j];
		if(ans[j - 1] < 0) ans[j - 1] += md;
	}
	for(ll j = 0 ; j <= n / c ; j++){
		cout<<ans[j]<<' ';
	}
	for(ll j = n / c + 1 ; j <= n ; j++){
		cout<<"0 ";
	}
	cout<<'\n';	
	return 0;
}