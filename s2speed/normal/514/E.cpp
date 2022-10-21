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

const ll maxn = 112 , md = 1e9 + 7 , inf = 2e16;

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
		for(ll i = 0 ; i <= 100 ; i++) a[i][i] = 1;
		return;
	}

	friend matrix operator* (matrix a , matrix b){
		matrix res;
		res.def();
		for(ll i = 0 ; i <= 100 ; i++){
			for(ll j = 0 ; j <= 100 ; j++){
				ll h = 0;
				for(ll k = 0 ; k <= 100 ; k++){
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
ll cnt[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n , t;
	cin>>n>>t;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h; h--;
		cnt[h]++;
	}
	s.def();
	for(ll i = 0 ; i < 100 ; i++){
		s.a[i][0] = cnt[i];
	}
	s.a[100][0] = 1;
	for(ll i = 1 ; i < 100 ; i++){
		s.a[i - 1][i] = 1;
	}
	s.a[100][100] = 1;
	s ^= t + 1;
	cout<<s.a[100][0]<<'\n';
	return 0;
}