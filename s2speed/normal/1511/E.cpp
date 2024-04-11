#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define size(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 3e5 + 16 , md = 998244353 , inf = 2e18;
 
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

ll dv(ll n , ll k){
	n *= tav(k , md - 2); n %= md;
	return n;
}

ll t[maxn];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	t[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		t[i] = t[i - 1] << 1;
		if(t[i] >= md) t[i] -= md;
	}
	ll n , m , w = 0 , ans = 0;
	cin>>n>>m;
	char a[n + 10][m + 10];
	memset(a , 0 , sizeof(a));
	ll lf[n + 10][m + 10][2] , rt[n + 10][m + 10][2] , up[n + 10][m + 10][2] , dn[n + 10][m + 10][2];
	memset(lf , 0 , sizeof(lf)); memset(rt , 0 , sizeof(rt)); memset(up , 0 , sizeof(up)); memset(dn , 0 , sizeof(dn));
	for(ll i = 1 ; i <= n ; i++){
		for(ll j = 1 ; j <= m ; j++){
			cin>>a[i][j]; w += (a[i][j] == 'o');
		}
	}
	for(ll i = 1 ; i <= n ; i++){
		lf[i][1][0] = t[w - 1] * (a[i][1] == 'o');
		for(ll j = 2 ; j <= m ; j++){
			if(a[i][j] == '*') continue;
			if(a[i][j - 1] == '*'){
				lf[i][j][0] = t[w - 1];
			} else {
				lf[i][j][1] = dv(lf[i][j - 1][0] , 2);
				lf[i][j][0] = dv(lf[i][j - 1][1] , 2) + t[w - 2];
				if(lf[i][j][0] > md) lf[i][j][0] -= md;
			}
		}
	}
	for(ll i = 1 ; i <= n ; i++){
		rt[i][m][0] = t[w - 1] * (a[i][m] == 'o');
		for(ll j = m - 1 ; j > 0 ; j--){
			if(a[i][j] == '*') continue;
			if(a[i][j + 1] == '*'){
				rt[i][j][0] = t[w - 1];
			} else {
				rt[i][j][1] = dv(rt[i][j + 1][0] , 2);
				rt[i][j][0] = dv(rt[i][j + 1][1] , 2) + t[w - 2];
				if(rt[i][j][0] > md) rt[i][j][0] -= md;
			}
		}
	}
	for(ll j = 1 ; j <= m ; j++){
		up[1][j][0] = t[w - 1] * (a[1][j] == 'o');
		for(ll i = 2 ; i <= n ; i++){
			if(a[i][j] == '*') continue;
			if(a[i - 1][j] == '*'){
				up[i][j][0] = t[w - 1];
			} else {
				up[i][j][1] = dv(up[i - 1][j][0] , 2);
				up[i][j][0] = dv(up[i - 1][j][1] , 2) + t[w - 2];
				if(up[i][j][0] > md) up[i][j][0] -= md;
			}
		}
	}
	for(ll j = 1 ; j <= m ; j++){
		dn[n][j][0] = t[w - 1] * (a[n][j] == 'o');
		for(ll i = n - 1 ; i > 0 ; i--){
			if(a[i][j] == '*') continue;
			if(a[i + 1][j] == '*'){
				dn[i][j][0] = t[w - 1];
			} else {
				dn[i][j][1] = dv(dn[i + 1][j][0] , 2);
				dn[i][j][0] = dv(dn[i + 1][j][1] , 2) + t[w - 2];
				if(dn[i][j][0] > md) dn[i][j][0] -= md;
			}
		}
	}
	for(ll i = 1 ; i < n ; i++){
		for(ll j = 1 ; j <= m ; j++){
			if(a[i][j] == '*' || a[i + 1][j] == '*') continue;
			ll cur = 1ll * up[i][j][0] * dn[i + 1][j][0] % md;
			ans += cur;
			cur = 1ll * up[i][j][0] * dn[i + 1][j][1] % md;
			cur = dv(cur , 2);
			ans += cur;
			cur = 1ll * up[i][j][1] * dn[i + 1][j][0] % md;
			cur = dv(cur , 2);
			ans += cur;
		}
	}
	for(ll i = 1 ; i <= n ; i++){
		for(ll j = 1 ; j < m ; j++){
			if(a[i][j] == '*' || a[i][j + 1] == '*') continue;
			ll cur = 1ll * lf[i][j][0] * rt[i][j + 1][0] % md;
			ans += cur;
			cur = 1ll * lf[i][j][0] * rt[i][j + 1][1] % md;
			cur = dv(cur , 2);
			ans += cur;
			cur = 1ll * lf[i][j][1] * rt[i][j + 1][0] % md;
			cur = dv(cur , 2);
			ans += cur;
		}
	}
	ans %= md; ans = dv(ans , t[w]);
	cout<<ans<<'\n';
	return 0;
}

/*
2 2
oo
oo
*/