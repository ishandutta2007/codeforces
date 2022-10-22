#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;

const ll MAXN = 2e5 + 20 , MAX = 1e6 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

ll f[MAXN] , ans = 0 , cnt[MAX] , z[MAX];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	memset(z , 0 , sizeof(z));	
	f[0] = 0;
	for(int i = 1 ; i < MAXN ; i++){
		ll h = tav(2 , i - 1);
		h += 2 * f[i - 1];
		f[i] = h % md;
	}
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ll h;
		double sq;
		cin>>h; sq = sqrt(h);
		for(int j = 1 ; j <= sq ; j++){
			if(h % j == 0){
				cnt[j]++;
				if(j != sq){
					cnt[h / j]++;
				}
			}
		}
	}
	for(int i = 2 ; i < MAX ; i++){
		if(!cnt[i]) continue;
		ll h = i - z[i] , o;
		z[i] = i;
		for(int j = 2 * i ; j < MAX ; j += i){
			z[j] += h;
		}
		o = 1ll * f[cnt[i]] * h;
		o %= md;
		o += md;
		ans += o;
		ans %= md;
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/