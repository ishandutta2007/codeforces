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
 
const ll maxn = (1 << 7) + 16 , md = 1e9 + 7 , inf = 2e18;
 
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

	ll n , m;
	ll a[maxn][maxn];

	void init(ll x , ll y){
		n = x; m = y;
		return;
	}

	void build(vector<vector<ll>> &z){
		for(ll i = 0 ; i < n ; i++){
			for(ll j = 0 ; j < m ; j++){
				a[i][j] = z[i][j];
			}
		}
		return;
	}

	void def(bool k){
		memset(a , 0 , sizeof(a));
		if(k) for(ll i = 0 ; i < n ; i++) a[i][i] = 1;
		return;
	}

	friend matrix operator* (matrix a , matrix b){
		matrix res;
		res.init(a.n , b.m);
		res.def(0);
		ll n = a.n;
		for(ll i = 0 ; i < n ; i++){
			for(ll j = 0 ; j < n ; j++){
				for(ll k = 0 ; k < n ; k++){
					res.a[i][j] += 1ll * a.a[i][k] * b.a[k][j] % md;
					if(res.a[i][j] >= md) res.a[i][j] -= md;
				}
			}
		}
		return res;
	}

	friend void operator*= (matrix &a , matrix b){
		a = a * b;
		return;
	}

	friend matrix operator^ (matrix a , ll k){
		matrix res;
		res.init(a.n , a.n);
		res.def(1);
		ll n = a.n;
		while(k > 0){
			if(k & 1){
				res *= a;
			}
			a *= a;
			k >>= 1;
		}
		return res;
	}

	friend void operator^= (matrix &a , ll k){
		a = a ^ k;
		return;
	}

};

vector<vector<ll>> z[7] , h;
matrix a[7] , x;
matrix ans , tmp;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(ll e = 0 ; e < 7 ; e++){
		ll lm = 1 << (e + 1);
		z[e].resize(lm);
		for(ll mask = 0 ; mask < lm ; mask++){
			z[e][mask].resize(lm);
			for(ll ksam = 0 ; ksam < lm ; ksam++){
				ll f = 0 , g = 1;
				for(ll j = e ; j >= 0 ; j--){
					ll a = f , b = g;
					f = g + f;
					g = f;
					if(!(mask & (1 << j)) & !(ksam & (1 << j))) g = a;
				}
				z[e][mask][ksam] = g;
			}
		}
		a[e].init(lm , lm); a[e].build(z[e]);
	}
	for(ll i = 0 ; i < 7 ; i++){
		ll k;
		cin>>k;
		a[i] ^= k;
	}
	ll lm = 1 << 7;
	ans.init(lm , lm);
	ans.def(1);
	h.resize(lm);
	for(ll i = 0 ; i < lm ; i++) h[i].assign(lm , 0);
	for(ll i = 0 ; i < 7 ; i++){
		ll q = 1 << (i + 1);
		for(ll j = 0 ; j < q ; j++){
			for(ll k = 0 ; k < q ; k++){
				h[j][k] = a[i].a[j][k];
			}
		}
		tmp.init(lm , lm); tmp.build(h);
		ans *= tmp;
	}
	cout<<ans.a[0][0]<<'\n';
	return 0;
}