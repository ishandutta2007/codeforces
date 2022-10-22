#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 55 , md = 1e9 + 7 , inf = 1e18;

ll dp[MAXN][MAXN] , pd[MAXN][MAXN] , t[MAXN] , tv[MAXN] , d[MAXN];

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

ll fact[MAXN] , fact_md[MAXN];

void fact_build(){
	fact[0] = 1;
	fact_md[0] = 1;
	for(ll i = 1 ; i < MAXN ; i++){
		fact[i] = 1ll * fact[i - 1] * i % md;
		fact_md[i] = tav(fact[i] , md - 2);
	}
	return;
}

ll chs(ll n , ll k){
	if(k > n || k < 0) return 0;
	return fact[n] * fact_md[k] % md * fact_md[n - k] % md;
}

ll dv(ll n , ll k){
	return n * tv[k] % md;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact_build();
	memset(pd , 0 , sizeof(pd));
	memset(dp , 0 , sizeof(dp));
	pd[0][0] = 1;
	for(ll j = 0 ; j < MAXN ; j++){
		ll h;
		if(j > 2){
			h = pd[2][j - 3];
			pd[0][j] = 1ll * (j - 1) * (j - 2) / 2 * h % md;
		}
		for(ll i = 2 ; i < MAXN ; i += 2){
			h = 1ll * (i - 1) * pd[i - 2][j] % md;
			pd[i][j] += h;
			h = 1ll * j * pd[i][j - 1] % md;
			pd[i][j] += h;
			pd[i][j] %= md;
		}
	}
	ll o = 1;
	for(ll i = 0 ; i < MAXN ; i++){
		t[i] = o;
		tv[i] = tav(t[i] , md - 2);
		o <<= 1;
	}
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>d[i];
	}
	for(ll i = n - 1 ; i > 0 ; i--){
		ll a = 0 , b = 0 , lm = n - i;
		for(ll j = 0 ; j < lm ; j++){
			if(d[i + j] == 2){
				a++;
			} else {
				b++;
			}
			ll ml = lm - j;
			for(ll q = 0 ; q < ml ; q++){
				for(ll x = q % 2 , y = q / 2 ; x <= q ; x += 2 , y--){
					for(ll k = 0 ; k <= x ; k++){
						if(y + x - k > b) continue;
						if(k > a) break;
//						cout<<i<<' '<<j<<' '<<q<<' '<<x<<' '<<y<<' '<<k<<' '<<a<<' '<<b<<'\n';
						ll h = dv(fact[q] , y) , da , db;
						db = b - (y + x - k);
						da = a - k + x - k;
						h *= pd[da][db]; h %= md;
						h *= chs(a , k); h %= md;
						h *= chs(b , y); h %= md;
						h *= chs(b - y , x - k); h %= md;
						if(q == 0){
							if(i + j + q == n - 1){
								dp[i][j] += h;
							}
						} else {
							h *= dp[i + j + 1][q - 1]; h %= md;
							dp[i][j] += h;
						}
					}
				}
			}
			dp[i][j] %= md;
		}
	}
	cout<<dp[1][d[0] - 1]<<'\n';
	return 0;
}

/*
4
3 3 3 3
*/