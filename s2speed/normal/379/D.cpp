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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

bool a[4];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , k , x , am = -1 , sn , sm;
	string v , u;
	cin>>k>>x>>n>>m;
	for(ll mask = 0 ; mask < 16 ; mask++){
		for(ll j = 0 ; j < 4 ; j++){
			a[j] = mask & (1 << j);
		}
		if(n == 1 && a[0] && a[1]) continue;
		if(m == 1 && a[2] && a[3]) continue;
		ll ln = (n - a[0] - a[1]) / 2;
		for(ll i = 0 ; i <= ln ; i++){
			ll lm = (m - a[2] - a[3]) / 2;
			for(ll j = 0 ; j <= lm ; j++){
				ll f = j , g = i , h;
				h = f + g + (a[1] & a[2]);
				g = f; f = h;
				for(ll q = 4 ; q <= k ; q++){
					h = f + g;
					if(q % 2){
						h += (a[3] & a[2]);
					} else {
						h += (a[3] & a[0]);
					}
					g = f; f = h;
					if(f > x) break;
				}
				if(f == x){
					am = mask;
					sn = i;
					sm = j;
					break;
				}
			}
			if(am != -1) break;
		}
		if(am != -1) break;
	}
	if(am == -1){
		cout<<"Happy new year!\n";
		return 0;
	}
	for(ll j = 0 ; j < 4 ; j++){
		a[j] = am & (1 << j);
	}
	if(a[0]) v += "C";
	for(ll i = 0 ; i < sn ; i++){
		v += "AC";
	}
	while(sze(v) < n - 1){
		v += "B";
	}
	if(sze(v) == n - 1){
		if(a[1]){
			v += "A";
		} else {
			v += "B";
		}
	}
	if(a[2]) u += "C";
	for(ll i = 0 ; i < sm ; i++){
		u += "AC";
	}
	while(sze(u) < m - 1){
		u += "B";
	}
	if(sze(u) == m - 1){
		if(a[3]){
			u += "A";
		} else {
			u += "B";
		}
	}
	cout<<v<<'\n'<<u<<'\n';
	return 0;
}