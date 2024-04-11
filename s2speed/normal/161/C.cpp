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

const ll maxn = 2e5 + 16 , md = 998244353 , inf = 2e17;

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

ll ans(ll a , ll b , ll c , ll d , ll j){
	if(a == 1 && b == (1 << j) - 1){
		return d - c + 1;
	}
	if(c == 1 && d == (1 << j) - 1){
		return b - a + 1;
	}
	ll m = (1 << j - 1) , res = max(0ll , min(b , d) - max(a , c) + 1);
	if(a == m && b == m) return res;
	if(c == m && d == m) return res;
	ll a1 , a2 , b1 , b2 , c1 , c2 , d1 , d2;
	a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = -1;
	if(a == m) a++; 
	if(b == m) b--; 
	if(c == m) c++; 
	if(d == m) d--; 
	if(a < m && b > m){
		a1 = a , b1 = m - 1 , a2 = 1 , b2 = b - m;
	}
	if(c < m && d > m){
		c1 = c , d1 = m - 1 , c2 = 1 , d2 = d - m;
	}
	if(a > m) a -= m;
	if(b > m) b -= m;
	if(c > m) c -= m;
	if(d > m) d -= m;
	if(a1 == -1 && c1 == -1){
		res = max(res , ans(a , b , c , d , j - 1));
		return res;
	}
	if(a1 == -1){
		ll h = max(ans(a , b , c1 , d1 , j - 1) , ans(a , b , c2 , d2 , j - 1));
		res = max(res , h);
		return res;
	}
	if(c1 == -1){
		ll h = max(ans(c , d , a1 , b1 , j - 1) , ans(c , d , a2 , b2 , j - 1));
		res = max(res , h);
		return res;
	}
	ll h = max(ans(a1 , b1 , c2 , d2 , j - 1) , ans(a2 , b2 , c1 , d1 , j - 1));
	res = max(res , h);
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll a , b , c , d;
	cin>>a>>b>>c>>d;
	cout<<ans(a , b , c , d , 30)<<'\n';
	return 0;
}