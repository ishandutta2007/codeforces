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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 7 , inf = 2e16;
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

struct matrix {

	ll a[maxn][maxn];

	void def(){
		memset(a , 0 , sizeof(a));
		return;
	}

	void I(){
		def();
		for(ll i = 0 ; i < 6 ; i++) a[i][i] = 1;
		return;
	}

	friend matrix operator* (matrix a , matrix b){
		matrix res;
		res.def();
		for(ll i = 0 ; i < 6 ; i++){
			for(ll j = 0 ; j < 6 ; j++){
				ll h = 0;
				for(ll k = 0 ; k < 6 ; k++){
					h += 1ll * a.a[i][k] * b.a[k][j] % md;
				}
				res.a[i][j] = h % md;
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
		res.I();
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

matrix s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll x , y , dx , dy , t , f , anx , any;
	cin>>md>>x>>y>>dx>>dy>>t;
	s.def();
	s.a[0][0] = s.a[2][0] = 1;
	s.a[1][1] = s.a[3][1] = 1;
	s.a[2][2] = s.a[4][2] = 1;
	s.a[3][3] = s.a[4][3] = 1;
	s.a[2][4] = s.a[3][4] = s.a[5][4] = 1; s.a[4][4] = 3;
	s.a[5][5] = 1;
	s ^= t;
	dx += x + y; dx %= md; if(dx < 0) dx += md;
	dy += x + y; dy %= md; if(dy < 0) dy += md;
	f = x + y + dx + dy + 1; f %= md;
//	ll h = s.a[0][0] * x + s.a[1][0] * y + s.a[2][0] * dx + s.a[3][0] * dy + s.a[4][0] * f + s.a[5][0] * 1;
//	cout<<h<<' ';
//	h = s.a[0][1] * x + s.a[1][1] * y + s.a[2][1] * dx + s.a[3][1] * dy + s.a[4][1] * f + s.a[5][1] * 1;
//	cout<<h<<' ';
//	h = s.a[0][2] * x + s.a[1][2] * y + s.a[2][2] * dx + s.a[3][2] * dy + s.a[4][2] * f + s.a[5][2] * 1;
//	cout<<h<<' ';
//	h = s.a[0][3] * x + s.a[1][3] * y + s.a[2][3] * dx + s.a[3][3] * dy + s.a[4][3] * f + s.a[5][3] * 1;
//	cout<<h<<' ';
//	h = s.a[0][4] * x + s.a[1][4] * y + s.a[2][4] * dx + s.a[3][4] * dy + s.a[4][4] * f + s.a[5][4] * 1;
//	cout<<h<<' ';
//	cout<<'\n';
	anx = s.a[0][0] * x + s.a[1][0] * y + s.a[2][0] * dx + s.a[3][0] * dy + s.a[4][0] * f + s.a[5][0] * 1;
	any = s.a[0][1] * x + s.a[1][1] * y + s.a[2][1] * dx + s.a[3][1] * dy + s.a[4][1] * f + s.a[5][1] * 1;
	anx %= md; any %= md;
	if(!anx) anx = md; if(!any) any = md;
	cout<<anx<<' '<<any<<'\n';
	return 0;
}