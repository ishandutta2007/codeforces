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
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 5 , md = 1e9 + 7 , inf = 2e15;

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

struct matrix {

	ll a[maxn][maxn];

	void init(bool k){
		for(ll i = 0 ; i < maxn ; i++){
			for(ll j = 0 ; j < maxn ; j++){
				a[i][j] = (i == j) & k;
			}
		}
		return;
	}

	friend matrix operator* (matrix a , matrix b){
		matrix res;
		res.init(false);
		for(ll i = 0 ; i < maxn ; i++){
			for(ll j = 0 ; j < maxn ; j++){
				for(ll k = 0 ; k < maxn ; k++){
					res.a[i][j] += 1ll * a.a[i][k] * b.a[k][j]; res.a[i][j] %= md - 1;
				}
			}
		}
		return res;
	}

	friend void operator*= (matrix &a , matrix b){
		a = a * b;
		return;
	}

	friend matrix operator^ (matrix n , ll k){
		matrix res;
		res.init(true);
		while(k > 0){
			if(k & 1){
				res *= n;
			}
			n *= n;
			k >>= 1;
		}
		return res;
	}

	friend void operator^= (matrix &n , ll k){
		n = n ^ k;
		return;
	}

};

matrix t;

/*
4 1 2 5 3
*/

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	ll n , f[3] , c;
	cin>>n>>f[0]>>f[1]>>f[2]>>c;
	n -= 2;
	t.init(false);
	t.a[0][0] = 1;
	t.a[1][0] = 1; t.a[1][1] = 1;
	t.a[2][3] = 1;
	t.a[3][4] = 1;
	t.a[4][1] = 1; t.a[4][2] = 1; t.a[4][3] = 1; t.a[4][4] = 1;
	t ^= n;
//	cout<<t.a[4][0]<<' '<<t.a[3][2]<<' '<<t.a[3][3]<<' '<<t.a[3][4]<<'\n';
	ll ans = tav(c , 2ll * t.a[4][0]);
	ans *= tav(f[0] , t.a[3][2]); ans %= md;
	ans *= tav(f[1] , t.a[3][3]); ans %= md;
	ans *= tav(f[2] , t.a[3][4]); ans %= md;
	cout<<ans<<'\n';
	return 0;
}